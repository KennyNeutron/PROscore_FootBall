void reset_AllVariable() {

  //############ Basketball Variables ###########

  //Basketball data
  HomeScore = 0;
  GuestScore = 0;

  HomeFoul = 0;
  GuestFoul = 0;

  HomeTOut = 0;
  GuestTOut = 0;

  //Baskeball Time
  GameTime_Minute = 0;
  GameTime_Second = 0;
  GameTime_Millis = 0;

  ShotClock_Second = SC_Default;
  ShotClock_Millis = 0;

  period = 1;

  buzzer = false;
  //#############################################
  autoBuzz = 0;
  autoBuzzToggle = false;

  BallPoss = 0;

  //interrupts
  isr_tmr_GTcounter = 0;
  GT_started = false;

  isr_tmr_SCcounter = 0;
  SC_started = false;

  //Push Buttons
  PB_ScanCount = 0;
  status_PB[18];  //16+2 just to be sure

  //msc
  GT_SC_sync = false;

  SetupMode = false;
  DataToSet = 0;

  TeamNameSetupMode = false;

  NRF_UpdateTN = false;
  UpdateTN_Micros = 0;

  buzz_micros = 0;




  TN_CurrentChange = 0;
  TN_ButtonAssign = 0;
  TN_CurrentPress = 0;

  SpecificCharToChange = ' ';
  TN_FirstPress = false;
  TN_Prev_ButtonAssign = 0;

  //Which TeamName To Change
  TN_NowChanging = 0;
  prev_SpecificCharToChange = '>';

  EndOfGame = false;
}

void verifyVariable() {
  if (GameTime_Minute == 45 && GameTime_Second == 0 && GameTime_Millis == 0 && !autoBuzzToggle) {
    //Serial.println("END!");
    GT_started = false;
    SC_started = false;


      autoBuzz = 2;
    

    buzz_micros = 0;
    autoBuzzToggle = true;
  }

if (GameTime_Minute == 90 && GameTime_Second == 0 && GameTime_Millis == 0 && !autoBuzzToggle) {
    //Serial.println("END!");
    GT_started = false;
    SC_started = false;

      autoBuzz = 2;
   

    buzz_micros = 0;
    autoBuzzToggle = true;
  }

  if(GameTime_Minute == 255){
    GameTime_Minute = 99;
  }else if(GameTime_Minute == 100){
    GameTime_Minute = 0;
  }

  if(GameTime_Second == 255){
    GameTime_Second = 59;
  }else if(GameTime_Second == 60){
    GameTime_Second = 0;
  }



  if (HomeScore >= 100 && HomeScore != 255) {
    HomeScore = 0;
  } else if (HomeScore == 255) {
    HomeScore = 99;
  }

  if (HomeFoul >= 6 && HomeFoul < 9) {
    HomeFoul = 10;
  } else if (HomeFoul == 9) {
    HomeFoul = 5;
  } else if (HomeFoul == 255) {
    HomeFoul = 0;
  } else if (HomeFoul == 11) {
    HomeFoul = 10;
  }

  if (HomeTOut >= 10 && HomeTOut != 255) {
    HomeTOut = 9;
  } else if (HomeTOut == 255) {
    HomeTOut = 0;
  }

  if (GuestScore >= 100 && GuestScore != 255) {
    GuestScore = 0;
  } else if (GuestScore == 255) {
    GuestScore = 99;
  }

  if (GuestFoul >= 6 && GuestFoul < 9) {
    GuestFoul = 10;
  } else if (GuestFoul == 9) {
    GuestFoul = 5;
  } else if (GuestFoul == 255) {
    GuestFoul = 0;
  } else if (GuestFoul == 11) {
    GuestFoul = 10;
  }

  if (GuestTOut >= 10 && GuestTOut != 255) {
    GuestTOut = 9;
  } else if (GuestTOut == 255) {
    GuestTOut = 0;
  }


  if (GameTime_Millis >= 10) {
    GameTime_Millis = 0;
    GameTime_Second++;

    if (GameTime_Second >= 60) {
      GameTime_Second = 0;
      GameTime_Minute++;
    }
  }

 


}
