/*
LED Driver Library ---> SN74HC595
by: Kenny Neutron
02-12-2024
*/

#ifndef SH74HC595_H
#define SN74HC595_H

#include "Arduino.h"

class SN74HC595 {
public:
  SN74HC595();
  void begin(uint8_t dataPin, uint8_t clockPin, uint8_t strobePin, uint8_t OEpin);

  void latchData();

  void regData(uint8_t DataToReg);

  void printNum(uint8_t NumToPrint);

  void printByte(uint8_t ByteToPrint, bool DisplayZero);

  void printOneDigit(uint8_t DigitToPrint);


private:
  uint8_t datPin, clkPin, strPin, oePin;
};

#endif