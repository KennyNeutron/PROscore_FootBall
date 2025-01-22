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

#define SeparateSP true   //Separate Start & Stop Buttons for GT
#define SeparateSCSP true 
#define SyncTime true //Buzz on Shotclock 0 not 0.0
#define ForPROleague false  //give 500ms extra for sc reset

#define PB_test true        //for testing push button assignment
#define HasTeamNames false  //This Unit Has TeamName Control

bool TN_ManualUpdate = false;
uint8_t SC_Default = 24;
void setup(){
    Serial.begin(115200);
    Serial.println("PROscore_FootBall System Start....");

}


void loop(){

}