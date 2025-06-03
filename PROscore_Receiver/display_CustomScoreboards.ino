//Display CSA Bacolod
void display_CSA_Bacolod(uint8_t thisScoreboard) {
  if (thisScoreboard == 1) {
    display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

    display_HomeFoul(HomeFoul);

    if (!GT_SC_sync) {
      display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
    } else {
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
    }

    display_GuestFoul(GuestFoul);

    display_HomeScore(HomeScore);

    display_Period(period);

    display_GuestScore(GuestScore);
  } else if (thisScoreboard == 2) {
    display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

    display_GuestFoul(GuestFoul);

    if (!GT_SC_sync) {
      display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
    } else {
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
    }
    display_HomeFoul(HomeFoul);

    display_GuestScore(GuestScore);

    display_Period(period);

    display_HomeScore(HomeScore);
  } else {
    display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

    display_HomeFoul(HomeFoul);

    if (!GT_SC_sync) {
      display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
    } else {
      SevenSeg.printOneDigit(255);
      SevenSeg.printOneDigit(255);
    }

    display_GuestFoul(GuestFoul);

    display_HomeScore(HomeScore);

    display_Period(period);

    display_GuestScore(GuestScore);
  }
}

//Display Ginatilan PS
void display_PROscoreGinatilan() {
  if (!GT_SC_sync) {
    display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
  } else {
    SevenSeg.printOneDigit(255);
    SevenSeg.printOneDigit(255);
  }

  display_HomeScore(HomeScore);

  // display_HomeTOut(HomeTOut);

  display_HomeFoul(HomeFoul);

  display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

  display_Period(period);

  display_GuestFoul(GuestFoul);

  //display_HomeTOut(GuestTOut);

  display_GuestScore(GuestScore);
}


//Display Scoreboard
void display_CornieMAX() {

  if (!GT_SC_sync) {
    display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
  } else {
    SevenSeg.printOneDigit(255);
    SevenSeg.printOneDigit(255);
  }

  display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

  display_HomeScore(HomeScore);

  display_HomeTOut(HomeTOut);

  display_HomeFoul(HomeFoul);

  display_Period(period);

  display_GuestFoul(GuestFoul);

  display_HomeTOut(GuestTOut);

  display_GuestScore(GuestScore);
}

void display_PROscore(uint8_t ThisScoreBoard) {
  switch (ThisScoreBoard) {
    case 1:
      if (!GT_SC_sync) {
        display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
      } else {
        SevenSeg.printOneDigit(255);
        SevenSeg.printOneDigit(255);
      }

      display_Period(period);

      display_HomeScore(HomeScore);

      // display_HomeTOut(HomeTOut);

      display_HomeFoul(HomeFoul);

      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_GuestFoul(GuestFoul);

      //display_HomeTOut(GuestTOut);

      display_GuestScore(GuestScore);
      break;

    case 2:
      if (!GT_SC_sync) {
        display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
      } else {
        SevenSeg.printOneDigit(255);
        SevenSeg.printOneDigit(255);
      }

      display_Period(period);

      display_HomeScore(GuestScore);

      // display_HomeTOut(GuestTOut);

      display_HomeFoul(GuestFoul);

      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_GuestFoul(HomeFoul);

      //display_HomeTOut(HomeTOut);

      display_GuestScore(HomeScore);
      break;
      break;

    default:
      if (!GT_SC_sync) {
        display_ShotClock(ShotClock_Second, ShotClock_Millis, false);
      } else {
        SevenSeg.printOneDigit(255);
        SevenSeg.printOneDigit(255);
      }

      display_Period(period);

      display_HomeScore(HomeScore);

      // display_HomeTOut(HomeTOut);

      display_HomeFoul(HomeFoul);

      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_GuestFoul(GuestFoul);

      //display_HomeTOut(GuestTOut);

      display_GuestScore(GuestScore);
      break;
  }
}



void display_EAC_Cavite(uint8_t ThisScoreBoard) {

  ThisUnit.HasMillis = true;

  switch (ThisScoreBoard) {
    case 1:
      //Scoreboard 1
      display_Period(period);

      display_HomeScore(HomeScore);
      display_HomeFoul(HomeFoul);
      display_HomeTOut(HomeTOut);

      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_GuestTOut(GuestTOut);
      display_GuestFoul(GuestFoul);
      display_GuestScore(GuestScore);
      break;
    case 2:
      //Scoreboard 2
      display_Period(period);

      display_GuestScore(GuestScore);
      display_GuestFoul(GuestFoul);
      display_GuestTOut(GuestTOut);

      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_HomeTOut(HomeTOut);
      display_HomeFoul(HomeFoul);
      display_HomeScore(HomeScore);
      break;
    default:
      //Scoreboard 1
      display_Period(period);

      display_HomeScore(HomeScore);
      display_HomeFoul(HomeFoul);
      display_HomeTOut(HomeTOut);

      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_GuestTOut(GuestTOut);
      display_GuestFoul(GuestFoul);
      display_GuestScore(GuestScore);
      break;
  }
}

void display_NEUST(uint8_t ThisScoreBoard) {

  ThisUnit.HasMillis = false;

  switch (ThisScoreBoard) {
    case 1:
      //Scoreboard 1
      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_HomeFoul(HomeFoul);

      display_HomeScore(HomeScore);

      display_HomeTOut(HomeTOut);

      display_Period(period);

      display_GuestTOut(GuestTOut);

      display_GuestFoul(GuestFoul);

      display_GuestScore(GuestScore);
      break;
    case 2:
      //Scoreboard 2
      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_GuestFoul(GuestFoul);

      display_GuestScore(GuestScore);

      display_GuestTOut(GuestTOut);

      display_Period(period);

      display_HomeTOut(HomeTOut);

      display_HomeFoul(HomeFoul);

      display_HomeScore(HomeScore);
      break;
    default:
      //Scoreboard 1
      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_HomeFoul(HomeFoul);

      display_HomeScore(HomeScore);

      display_HomeTOut(HomeTOut);

      display_Period(period);

      display_GuestTOut(GuestTOut);

      display_GuestFoul(GuestFoul);

      display_GuestScore(GuestScore);
      break;
  }
}

//Zeki Portable
void display_Portable(uint8_t ThisScoreBoard) {

  switch (ThisScoreBoard) {
    case 1:
      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_HomeFoul(HomeFoul);

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

      display_GuestFoul(GuestFoul);

      display_HomeScore(HomeScore);

      display_Period(period);

      display_GuestScore(GuestScore);
      break;

    case 2:
      display_GuestScore(GuestScore);

      display_Period(period);

      display_HomeScore(HomeScore);

      display_GuestFoul(GuestFoul);

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

      display_HomeFoul(HomeFoul);

      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);
      break;

    default:
      display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, ThisUnit.HasMillis);

      display_HomeFoul(HomeFoul);

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

      display_GuestFoul(GuestFoul);

      display_HomeScore(HomeScore);

      display_Period(period);

      display_GuestScore(GuestScore);
      break;
  }
}


void display_FootBall() {
  SevenSeg.printOneDigit((GameTime_Minute / 10) + 100);
  SevenSeg.printOneDigit((GameTime_Minute % 10) + 100);

  SevenSeg.printOneDigit((GameTime_Second / 10) + 100);
  SevenSeg.printOneDigit((GameTime_Second % 10) + 100);

  display_HomeScore(HomeScore);

  display_HomeFoul(HomeFoul);

  display_Period(period);

  display_GuestFoul(GuestFoul);

  display_GuestScore(GuestScore);
}
