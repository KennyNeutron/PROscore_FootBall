/*
    PROscore Wireless 2025 - Receiver Code
    Version: 1.2.5 (based on original v2024.1.0.1)

    Author: KennyNeutron

    Date Started: 2024-02-12
    Last Updated: 2025-05-18
*/

#include "Arduino.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "SN74HC595.h"
#include "variables.h"
#include "PTWDBS_DataStructure.h"

RF24 NRF(A0, A1);  //CE, CSN pins
const byte address[6] = "ZK002";

SN74HC595 SevenSeg;
#define BuzzerPin 2  //Default buzzer pin
//#define BuzzerPin 5  //Alternative buzzer pin

char SerialData[17] = " ";

//Communication Data Structure
//Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct This_Unit {
  bool IsScoreBoard = false;
  bool IsShotClock = false;
  bool HasMillis = false;             //General: this unit supports any millis display on shot clock
  bool ShowMillisBelow10Sec = false;  //Show millis on shot clock when <10s left
};

This_Unit ThisUnit;  //Create a variable with the above structure

bool nrfBroken = false;

void setup() {
  //Initialize unit configuration
  ThisUnit.IsScoreBoard = true;
  ThisUnit.IsShotClock = false;
  ThisUnit.HasMillis = false;
  ThisUnit.ShowMillisBelow10Sec = false;

  Serial.begin(9600);
  Serial.println("Reciever\nSYSTEM START...");
  Serial.println("NRF Address: " + String((char*)address));

  //Initialize shift register
  //SevenSeg.begin(8, 9, 10, 3);  //Old PCB
  //SevenSeg.begin(2, 3, 4, A7);  //Alternative pin configuration
  // SevenSeg.begin(8, 9, 7, 10);    //New PCB configuration
  SevenSeg.begin(8, 9, 10, 7);  //FootBall Config

  pinMode(BuzzerPin, OUTPUT);
  digitalWrite(BuzzerPin, 0);

  //Try to initialize NRF module for 5 seconds
  while (!NRF.begin()) {
    if (millis() > 5000) {
      nrfBroken = true;
      goto nonrf;
    }
  }

nonrf:
  //Handle case where NRF module is not working
  if (nrfBroken) {
    uint8_t HomeScore = 99;
    uint8_t GuestScore = 99;

    uint8_t HomeFoul = 3;
    uint8_t GuestFoul = 3;

    uint8_t HomeTOut = 3;
    uint8_t GuestTOut = 3;

    //Basketball Time
    uint8_t GameTime_Minute = 12;
    uint8_t GameTime_Second = 34;
    uint8_t GameTime_Millis = 5;

    uint8_t ShotClock_Second = 66;
    uint8_t ShotClock_Millis = 6;

    uint8_t period = 3;

    //Display fallback values based on device type
    if (ThisUnit.IsScoreBoard && !ThisUnit.IsShotClock) {
      displayUNIT_Scoreboard();
    } else if (!ThisUnit.IsScoreBoard && ThisUnit.IsShotClock) {
      displayUNIT_ShotClock();
    }
    SevenSeg.latchData();
    while (1)
      ;  //Infinite loop if NRF is broken
  }

  //Configure NRF if working
  NRF.setPALevel(RF24_PA_MAX);
  NRF.setDataRate(RF24_250KBPS);
  NRF.openReadingPipe(0, address);
  NRF.startListening();

  PSABTinterrupt_setup();

  //Output device configuration information to serial
  if (ThisUnit.IsScoreBoard && !ThisUnit.IsShotClock) {
    Serial.print("This Unit is Scoreboard");
    if (ThisUnit.HasMillis) {
      Serial.println(" with Millis");
    } else {
      Serial.println(" without Millis");
    }
  } else if (!ThisUnit.IsScoreBoard && ThisUnit.IsShotClock) {
    Serial.print("This Unit is Shotclock");
    if (ThisUnit.HasMillis) {
      Serial.println(" with Millis");
    } else {
      Serial.println(" without Millis");
    }
  }
}

void loop() {
  //Check for incoming data on NRF module
  if (NRF.available()) {
    NRF.read(&payload, sizeof(Payload_Data));  //Read the whole data and store it into the 'payload' structure
    TeamNameSetupMode = payload.TeamNameSetupMode;

    if (!TeamNameSetupMode) {
      //Normal operation mode - update all game variables
      HomeScore = payload.HomeScore;
      GuestScore = payload.GuestScore;

      HomeFoul = payload.HomeFoul;
      GuestFoul = payload.GuestFoul;

      HomeTOut = payload.HomeTOut;
      GuestTOut = payload.GuestTOut;

      GameTime_Minute = payload.GameTime_Minute;
      GameTime_Second = payload.GameTime_Second;
      GameTime_Millis = payload.GameTime_Millis;

      ShotClock_Second = payload.ShotClock_Second;
      ShotClock_Millis = payload.ShotClock_Millis;

      BallPoss = payload.BallPoss;

      period = payload.period;
      GT_SC_sync = payload.GT_SC_sync;

      SetupMode = payload.SetupMode;
      DataToSet = payload.DataToSet;

      TeamNameSetupMode = payload.TeamNameSetupMode;

      EndOfGame = payload.EndOfGame;
    } else {
      //Team name setup mode - prepare serial data
      TeamNameSetupMode = payload.TeamNameSetupMode;
      SerialData[0] = 'a';
      SerialData[1] = 'b';
      for (int i = 2; i <= 11; i++) {
        SerialData[i] = payload.CurrentTeamName[i - 2];
      }
      SerialData[12] = payload.TeamNameSetupMode + 48;
      SerialData[13] = payload.TN_ID + 48;
      SerialData[14] = 'c';
      Serial.print(SerialData);

      //Debug output for SerialData (commented out)
      //for (int a = 0; a < 16; a++) {Serial.print("SD["); Serial.print(a); Serial.print("]:"); Serial.println(SerialData[a],HEX);}
    }
  }

  //Update display if needed and not in team name setup mode
  if (!display_updated && !TeamNameSetupMode) {
    //Serial.println("update DISPLAY");
    if (ThisUnit.IsScoreBoard && !ThisUnit.IsShotClock) {
      displayUNIT_Scoreboard();
    } else if (!ThisUnit.IsScoreBoard && ThisUnit.IsShotClock) {
      displayUNIT_ShotClock();
    }
    SevenSeg.latchData();
    display_updated = true;

    //Control buzzer based on game state
    if (EndOfGame && ThisUnit.IsShotClock && !ThisUnit.IsScoreBoard) {
      digitalWrite(BuzzerPin, 1);  //ShotClock buzzer stays on at end of game
    } else {
      digitalWrite(BuzzerPin, payload.buzzer);
    }
  }
}