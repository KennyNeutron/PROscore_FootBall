#include "Arduino.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <EEPROM.h>
#include "variables.h"
#include "PROscore_DataStructure.h"
#include "Keymapping.h"

RF24 NRF(A0, A1);  // CE, CSN
const byte address[6] = "ZK001";

#define LED_RED 10
#define LED_GRN A3
#define batteryPin A2

#define SeparateSP false   //Separate Start & Stop Buttons for GT
#define SeparateSCSP false 
#define SyncTime false //Buzz on Shotclock 0 not 0.0
#define ForPROleague false  //give 500ms extra for sc reset

#define PB_test false        //for testing push button assignment
#define HasTeamNames false  //This Unit Has TeamName Control

bool TN_ManualUpdate = false;
uint8_t SC_Default = 24;
void setup(){
    Serial.begin(115200);
    Serial.println("PROscore_FootBall System Start....");


  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GRN,OUTPUT);
  digitalWrite(LED_RED,0);
  digitalWrite(LED_GRN, 0);
  //Next TeamName to Change, button assignment

  //PSeeprom_SaveAll();
  //PSeeprom_RetrieveAll();
  battery_init();

  for (int x = 0; x < 10; x++) {
    digitalWrite(LED_RED, LOW);
    delay(100);
    digitalWrite(LED_RED, HIGH);
    delay(100);
  }


  if (PB_test) {
    Serial.begin(9600);
    Serial.println("Controller\nSYSTEM START...");
  }

  if (!NRF.begin()) {
    while (1) {
      digitalWrite(LED_RED, HIGH);
      delay(50);
      digitalWrite(LED_RED, LOW);
      delay(50);
      digitalWrite(LED_RED, HIGH);
      delay(50);
      digitalWrite(LED_RED, LOW);
      delay(50);
      digitalWrite(LED_RED, HIGH);
      delay(50);
      digitalWrite(LED_RED, LOW);
      delay(1000);
    }
  }


  NRF.setPALevel(RF24_PA_MAX);
  NRF.setDataRate(RF24_250KBPS);
  NRF.openWritingPipe(address);

  PushButton_Setup();

  PSABTinterrupt_setup();


//   if (HasTeamNames) {
//     TeamNameSetupMode = true;
//     for (int i = 0; i < 10; i++) {
//       NRF_UpdateAllTN();
//     }
//     TeamNameSetupMode = false;
//   }


  reset_AllVariable();
  NRF_SendData();

  //delay(3000);
  //Serial.println("GT_Min:" + String(GameTime_Minute));
  //Serial.println("Period:" + String(period));
  if (shift_Pressed()) {
    HomeScore = 188;
    GuestScore = 188;

    HomeFoul = 8;
    GuestFoul = 8;

    HomeTOut = 8;
    GuestTOut = 8;

    //Baskeball Time
    GameTime_Minute = 88;
    GameTime_Second = 88;
    GameTime_Millis = 8;

    ShotClock_Second = 8;
    ShotClock_Millis = 8;
    period = 8;
    buzzer = true;
    while (1) {
      BallPoss = 1;
      NRF_SendData();
      BallPoss = 2;
      NRF_SendData();
    }
  }

  if (status_PB[PB_ShotClockR24]) {
    SC_Default = 12;
  }
  digitalWrite(LED_RED, LOW);

  digitalWrite(LED_GRN, 1);

}


void loop(){
    KeyFunctions();
    verifyVariable();
    NRF_SendData();
    BuzzerFunction();
}



void BuzzerFunction(){
    if (autoBuzz == 1) {
    //END OF SHOTCLOCK

  } else if (autoBuzz == 2) {
    //END OF PERIOD
    buzzer = true;
    if (buzz_micros > 16000) {
      buzzer = false;
      autoBuzz = 0;
      //newPeriod();
    }
  } else if (autoBuzz == 3) {
    //END OF GAME
    buzzer = true;
    if (buzz_micros > 40000) {
      buzzer = false;
      autoBuzz = 0;
    }
  }
}