

void displayUNIT_Scoreboard() {
  //Serial.println("Scoreboard Display");

  //display_EAC_Cavite(2);

  //display_NEUST(2);

  //display_Portable(1);  //Zeki Portable

  display_FootBall();
  // display_CSA_Bacolod(2);

  //display_PROscore(1);

  //display_PROscoreGinatilan();

  //display_5AScoreboard();
}

void displayUNIT_ShotClock() {
  //Serial.println("ShotClock Display");

  display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

  if (!SetupMode) {
    if (!GT_SC_sync) {
      display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
    } else {
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
    }
  } else {
    display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
  }
}

void display_ShotClock(uint8_t ShotClock_Second, uint8_t ShotClock_Millis, bool Display_Millis) {
  if (!SetupMode) {
    //Change ShotClock Millis Behaviour Here

    if (ThisUnit.ShowMillisBelow10Sec) {
      //Displaying ShotClock with Millis when below 10
      if (ShotClock_Second < 10) {
        SevenSeg.printOneDigit(ShotClock_Second + 100);
        SevenSeg.printOneDigit(ShotClock_Millis + 100);
      } else {
        SevenSeg.printOneDigit(ShotClock_Second / 10);
        SevenSeg.printOneDigit(ShotClock_Second % 10);
      }
    } else {
      //No Displaying ShotClock with Millis when below 10
      if (ShotClock_Second < 10) {
        SevenSeg.printOneDigit(255);
        SevenSeg.printOneDigit(ShotClock_Second + 100);
      } else {
        SevenSeg.printOneDigit(ShotClock_Second / 10);
        SevenSeg.printOneDigit(ShotClock_Second % 10);
      }
    }




  } else {
    if (DataToSet > 4 && !blink) {
      if (DataToSet == 6 && !Display_Millis) {
        SevenSeg.printOneDigit(254);
        SevenSeg.printOneDigit(ShotClock_Millis + 100);
      } else {
        SevenSeg.printOneDigit(ShotClock_Second / 10);
        SevenSeg.printOneDigit(ShotClock_Second % 10);
      }
    } else if (DataToSet > 4 && blink) {
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
    } else {
      SevenSeg.printOneDigit(ShotClock_Second / 10);
      SevenSeg.printOneDigit(ShotClock_Second % 10);
    }
  }
}



void display_HomeScore(uint8_t score) {
  SevenSeg.printByte(score, false);
}

void display_HomeFoul(uint8_t foul) {
  if (BallPoss == 1) {
    SevenSeg.printOneDigit(foul + 100);
  } else {
    SevenSeg.printOneDigit(foul);
  }
}

void display_HomeTOut(uint8_t TimeOut) {
  if (BallPoss == 1) {
    SevenSeg.printOneDigit(TimeOut + 100);
  } else {
    SevenSeg.printOneDigit(TimeOut);
  }
}

void display_GuestScore(uint8_t score) {
  SevenSeg.printByte(score, false);
}

void display_GuestFoul(uint8_t foul) {
  if (BallPoss == 2) {
    SevenSeg.printOneDigit(foul + 100);
  } else {
    SevenSeg.printOneDigit(foul);
  }
}

void display_GuestTOut(uint8_t TimeOut) {
  if (BallPoss == 2) {
    SevenSeg.printOneDigit(TimeOut + 100);
  } else {
    SevenSeg.printOneDigit(TimeOut);
  }
}

void display_Period(uint8_t PERIOD) {
  if (!SetupMode) {
    if (PERIOD == 10) {
      SevenSeg.printOneDigit(11);
    } else {
      SevenSeg.printOneDigit(PERIOD);
    }
  } else {
    if (blink && DataToSet == 4) {
      SevenSeg.printOneDigit(255);
    } else {
      if (PERIOD == 5) {
        SevenSeg.printOneDigit(11);
      } else {
        SevenSeg.printOneDigit(PERIOD);
      }
    }
  }
}

void display_GameTime(uint8_t Minute, uint8_t Second, uint8_t Millis, bool Display_Millis) {

  if (!Display_Millis && Minute == 0 && !SetupMode) {
    SevenSeg.printByte(Second, true);
    SevenSeg.printOneDigit(Millis + 100);
    SevenSeg.printOneDigit(255);
  } else {
    if (!Display_Millis && SetupMode && DataToSet == 3) {
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
      if (blink) {
        SevenSeg.printOneDigit(255);
      } else {
        SevenSeg.printOneDigit(Millis + 100);
      }
      SevenSeg.printOneDigit(255);
    } else {
      if (SetupMode == true && DataToSet == 2 && blink == true) {
        SevenSeg.printOneDigit(254);
        SevenSeg.printOneDigit(254);
      } else {
        if (Minute < 10) {
          SevenSeg.printOneDigit(255);
          SevenSeg.printOneDigit((Minute % 10) + 100);
        } else {
          SevenSeg.printOneDigit((Minute / 10) + 100);
          SevenSeg.printOneDigit((Minute % 10) + 100);
        }
      }

      if (SetupMode == true && DataToSet == 1 && blink == true) {
        SevenSeg.printOneDigit(254);
        SevenSeg.printOneDigit(254);
      } else {
        SevenSeg.printOneDigit((Second / 10) + 100);
        SevenSeg.printOneDigit((Second % 10) + 100);
      }
    }
  }

  if (Display_Millis) {
    if (SetupMode == true && DataToSet == 3 && blink == true) {
      SevenSeg.printOneDigit(255);
    } else {
      SevenSeg.printOneDigit(Millis + 100);
    }
  }
}


