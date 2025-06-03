  void displayUNIT_5AShotClock() {
  //Serial.println("ShotClock Display");
  if (ThisUnit.HasMillis) {
    if (SetupMode == true && DataToSet == 3 && blink == true) {
      SevenSeg.printOneDigit(255);
    } else {
      SevenSeg.printOneDigit(GameTime_Millis + 100);
    }
  }

  SevenSeg.printOneDigit(255);
  display_5A_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);
  display_5AShotClock(ShotClock_Second, ShotClock_Millis, false);
}

void display_5AScoreboard() {

  if (ThisUnit.HasMillis) {
    if (SetupMode == true && DataToSet == 3 && blink == true) {
      SevenSeg.printOneDigit(255);
    } else {
      SevenSeg.printOneDigit(GameTime_Millis + 100);
    }
  }

  SevenSeg.printOneDigit(255);

  display_GuestTOut(GuestTOut);
  display_HomeTOut(HomeTOut);

  display_GuestFoul(GuestFoul);
  display_HomeFoul(HomeFoul);

  display_Period(period);


  display_HomeScore(HomeScore);
  display_GuestScore(GuestScore);

  display_5A_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);
  display_5AShotClock(ShotClock_Second, ShotClock_Millis, false);
}

void display_5AShotClock(uint8_t ShotClock_Second, uint8_t ShotClock_Millis, bool Display_Millis) {
  if (!SetupMode) {
    if (ShotClock_Second < 10) {
      SevenSeg.printOneDigit(ShotClock_Millis + 100);
      SevenSeg.printOneDigit(ShotClock_Second + 100);
    } else {

      SevenSeg.printOneDigit(ShotClock_Second % 10);
      SevenSeg.printOneDigit(ShotClock_Second / 10);
    }
  } else {
    if (DataToSet > 4 && !blink) {
      if (DataToSet == 6 && !Display_Millis) {
        SevenSeg.printOneDigit(ShotClock_Millis + 100);
        SevenSeg.printOneDigit(254);
      } else {
        SevenSeg.printOneDigit(ShotClock_Second % 10);
        SevenSeg.printOneDigit(ShotClock_Second / 10);
      }
    } else if (DataToSet > 4 && blink) {
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
    } else {
      SevenSeg.printOneDigit(ShotClock_Second % 10);
      SevenSeg.printOneDigit(ShotClock_Second / 10);
    }
  }
}

void display_5A_GameTime(uint8_t Minute, uint8_t Second, uint8_t Millis, bool Display_Millis) {

  if (!Display_Millis && Minute == 0 && !SetupMode) {
    SevenSeg.printOneDigit(255); 
    SevenSeg.printOneDigit(Millis + 100);   
    SevenSeg.printByte(Second, true);
  } else {
    if (!Display_Millis && SetupMode && DataToSet == 3) {
      if (blink) {
        SevenSeg.printOneDigit(255);
      } else {
        SevenSeg.printOneDigit(Millis + 100);
      }
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
    } else {
      if (SetupMode == true && DataToSet == 1 && blink == true) {
        SevenSeg.printOneDigit(254);
        SevenSeg.printOneDigit(254);
      } else {
        SevenSeg.printOneDigit((Second % 10) + 100);
        SevenSeg.printOneDigit((Second / 10) + 100);
      }

      if (SetupMode == true && DataToSet == 2 && blink == true) {
        SevenSeg.printOneDigit(254);
        SevenSeg.printOneDigit(254);
      } else {
        if (Minute < 10) {
          SevenSeg.printOneDigit((Minute % 10) + 100);
          SevenSeg.printOneDigit(255);
        } else {
          SevenSeg.printOneDigit((Minute % 10) + 100);
          SevenSeg.printOneDigit((Minute / 10) + 100);
        }
      }
    }
  }
}