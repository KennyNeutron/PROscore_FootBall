bool buttonPressed = false;

bool shift_Pressed() {
  return status_PB[PB_Shift];
}


void KeyFunctions() {
  if (status_PB[PB_BallPoss] && !buttonPressed) {
    if (shift_Pressed()) {
      BallPoss = 0;
    } else {
      switch (BallPoss) {
        case 0:
          BallPoss = 1;
          break;
        case 1:
          BallPoss = 2;
          break;
        case 2:
          BallPoss = 1;
          break;
        default:
          BallPoss = 0;
          break;
      }
    }
  }
  if (autoBuzz == 0) {
    if (status_PB[PB_Buzzer]) {
      Serial.println("Buzz Press");
      Serial.println(shift_Pressed());
      Serial.println(GT_started);
      Serial.println(HasTeamNames);
      if (shift_Pressed() && !buttonPressed && !GT_started && HasTeamNames) {
        Serial.begin(9600);
        Serial.println("TN MODE");
        //prev_SpecificCharToChange = get_CurrentChar();
        TN_CurrentChange = 0;
        TN_ButtonAssign = 0;
        TN_CurrentPress = 0;

        SpecificCharToChange = '#';
        TN_FirstPress = false;
        TN_Prev_ButtonAssign = 0;

        //Which TeamName To Change
        TN_NowChanging = 0;

        TeamNameSetupMode = true;
        //show_WhichTN_ToChange();
      } else {
        buzzer = true;
        TN_ManualUpdate = false;
      }

    } else {
      buzzer = false;
      if (HasTeamNames) {
        if (!TN_ManualUpdate && !GT_started) {
          TeamNameSetupMode = true;
        //   NRF_UpdateAllTN();
        //   NRF_UpdateAllTN();
        //   NRF_UpdateAllTN();
          TeamNameSetupMode = false;
          TN_ManualUpdate = true;
        }
      }
    }
  }

  if (status_PB[PB_ShotClockR24] &&  !buttonPressed) {
    if(!GT_started){
        GameTime_Minute--;
    }
    buttonPressed = true;
  }



  if (status_PB[PB_ShotClockR14] && !buttonPressed) {
    if(!GT_started){
        GameTime_Minute++;
    }
    buttonPressed = true;
  }

  if (status_PB[PB_ShotClockSTART] && !buttonPressed) {
    if (!SeparateSCSP) {
      if (GT_started && !SC_started) {
        SC_started = true;
      } else {
        SC_started = false;
      }
    } else {
      if (GT_started) {
        SC_started = true;
      }
    }

    //Serial.println("SC START!");
  }

  if (status_PB[PB_ShotClockSTOP] && !buttonPressed) {
    SC_started = false;
    //Serial.println("SC STOP!");
  }


  if (status_PB[PB_GameTimeSTART] && !buttonPressed) {

    if (!SeparateSP) {
      if (shift_Pressed() && !GT_started) {
        SetupMode = true;
        DataToSet = 1;
      } else {
        GT_started = !GT_started;
        if (SyncTime) {
          SC_started = GT_started;
        }
        if (!GT_started) {
          SC_started = false;
        }
      }
    } else {
      if (shift_Pressed() && !GT_started) {
        SetupMode = true;
        DataToSet = 1;
      } else {
        GT_started = true;
      }
    }
    if (SyncTime) {
      SC_started = GT_started;
      Start_FirstPress = !Start_FirstPress;
    }

    //    if (!Start_FirstPress && GT_started && SyncTime){
    //      GameTime_Millis--;
    //    }
  }

  if (status_PB[PB_GameTimeSTOP] && !buttonPressed) {
    GT_started = false;
    SC_started = false;
  }

  if (status_PB[PB_HomeScore] && !buttonPressed) {
    if (shift_Pressed()) {
      HomeScore--;
    } else {
      HomeScore++;
    }
  }

  if (status_PB[PB_HomeFoul] && !buttonPressed) {
    if (shift_Pressed()) {
      HomeFoul--;
    } else {
      HomeFoul++;
    }
  }

  if (status_PB[PB_HomeTOut] && !buttonPressed) {
    if(!GT_started){
        GameTime_Second--;
    }
    buttonPressed = true;
  }

  if (status_PB[PB_GuestScore] && !buttonPressed) {
    if (shift_Pressed()) {
      GuestScore--;
    } else {
      GuestScore++;
    }
  }


  if (status_PB[PB_GuestFoul] && !buttonPressed) {
    if (shift_Pressed()) {
      GuestFoul--;
    } else {
      GuestFoul++;
    }
  }

  if (status_PB[PB_GuestTOut] && !buttonPressed) {
     if(!GT_started){
        GameTime_Second++;
    }
    buttonPressed = true;
  }

  if (status_PB[PB_Period] && !buttonPressed) {
    period++;
    if (period >= 11) {
      period = 0;
    }
  }

  if (PB_NoPress()) {
    buttonPressed = false;
  } else {
    buttonPressed = true;
  }
}