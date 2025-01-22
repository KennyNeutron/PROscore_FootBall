#define PB_Out0 2
#define PB_Out1 3
#define PB_Out2 4
#define PB_Out3 5

#define PB_In0 6
#define PB_In1 7
#define PB_In2 8
#define PB_In3 9


void PushButton_Setup() {
  pinMode(PB_Out0, OUTPUT);
  pinMode(PB_Out1, OUTPUT);
  pinMode(PB_Out2, OUTPUT);
  pinMode(PB_Out3, OUTPUT);

  pinMode(PB_In0, INPUT_PULLUP);
  pinMode(PB_In1, INPUT_PULLUP);
  pinMode(PB_In2, INPUT_PULLUP);
  pinMode(PB_In3, INPUT_PULLUP);

  digitalWrite(PB_Out0, 1);
  digitalWrite(PB_Out1, 1);
  digitalWrite(PB_Out2, 1);
  digitalWrite(PB_Out3, 1);

  for (int i = 0; i <= 17; i++) {
    status_PB[i] = false;
  }
}

void PushButton_Scan() {

  PB_Scan(PB_ScanCount);

  switch (PB_ScanCount) {
    case 0:
      if (!digitalRead(PB_In0)) {
        PB_setStatus(1, 1);
      } else {
        PB_setStatus(1, 0);
      }
      if (!digitalRead(PB_In1)) {
        PB_setStatus(2, 1);
      } else {
        PB_setStatus(2, 0);
      }
      if (!digitalRead(PB_In2)) {
        PB_setStatus(3, 1);
      } else {
        PB_setStatus(3, 0);
      }
      if (!digitalRead(PB_In3)) {
        PB_setStatus(4, 1);
      } else {
        PB_setStatus(4, 0);
      }
      break;
    case 1:
      if (!digitalRead(PB_In0)) {
        PB_setStatus(5, 1);
      } else {
        PB_setStatus(5, 0);
      }
      if (!digitalRead(PB_In1)) {
        PB_setStatus(6, 1);
      } else {
        PB_setStatus(6, 0);
      }
      if (!digitalRead(PB_In2)) {
        PB_setStatus(7, 1);
      } else {
        PB_setStatus(7, 0);
      }
      if (!digitalRead(PB_In3)) {
        PB_setStatus(8, 1);
      } else {
        PB_setStatus(8, 0);
      }
      break;
    case 2:
      if (!digitalRead(PB_In0)) {
        PB_setStatus(9, 1);
      } else {
        PB_setStatus(9, 0);
      }
      if (!digitalRead(PB_In1)) {
        PB_setStatus(10, 1);
      } else {
        PB_setStatus(10, 0);
      }
      if (!digitalRead(PB_In2)) {
        PB_setStatus(11, 1);
      } else {
        PB_setStatus(11, 0);
      }
      if (!digitalRead(PB_In3)) {
        PB_setStatus(12, 1);
      } else {
        PB_setStatus(12, 0);
      }
      break;
    case 3:
      if (!digitalRead(PB_In0)) {
        PB_setStatus(13, 1);
      } else {
        PB_setStatus(13, 0);
      }
      if (!digitalRead(PB_In1)) {
        PB_setStatus(14, 1);
      } else {
        PB_setStatus(14, 0);
      }
      if (!digitalRead(PB_In2)) {
        PB_setStatus(15, 1);
      } else {
        PB_setStatus(15, 0);
      }
      if (!digitalRead(PB_In3)) {
        PB_setStatus(16, 1);
      } else {
        PB_setStatus(16, 0);
      }
      break;
  }

  PB_Scan(255);

  PB_ScanCount++;

  if (PB_ScanCount == 5) {
    PB_ScanCount = 0;
  }
}

void PB_Scan(uint8_t ScanNum) {
  switch (ScanNum) {
    case 0:
      digitalWrite(PB_Out0, 0);
      digitalWrite(PB_Out1, 1);
      digitalWrite(PB_Out2, 1);
      digitalWrite(PB_Out3, 1);
      break;
    case 1:
      digitalWrite(PB_Out0, 1);
      digitalWrite(PB_Out1, 0);
      digitalWrite(PB_Out2, 1);
      digitalWrite(PB_Out3, 1);
      break;
    case 2:
      digitalWrite(PB_Out0, 1);
      digitalWrite(PB_Out1, 1);
      digitalWrite(PB_Out2, 0);
      digitalWrite(PB_Out3, 1);
      break;
    case 3:
      digitalWrite(PB_Out0, 1);
      digitalWrite(PB_Out1, 1);
      digitalWrite(PB_Out2, 1);
      digitalWrite(PB_Out3, 0);
      break;
    case 255:
      digitalWrite(PB_Out0, 1);
      digitalWrite(PB_Out1, 1);
      digitalWrite(PB_Out2, 1);
      digitalWrite(PB_Out3, 1);
      break;
  }
}

void PB_setStatus(uint8_t PushButton, bool status) {
  status_PB[PushButton] = status;
}

bool PB_NoPress() {

  bool StatusToReturn = true;

  for (int i = 0; i <= 17; i++) {
    
    if(PB_test && status_PB[i]){
      Serial.print("Pushed Button #");
      Serial.println(i);
    }
    
    if (status_PB[i] && i != PB_Shift) {
      StatusToReturn = false;
    }
  }

  return StatusToReturn;
}

bool PB_AllNoPress() {

  bool StatusToReturn = true;

  for (int i = 0; i <= 17; i++) {
    if (status_PB[i]) {
      StatusToReturn = false;
    }
  }

  return StatusToReturn;
}

void NRF_SendData() {
  payload.HomeScore = HomeScore;
  payload.GuestScore = GuestScore;
  payload.HomeFoul = HomeFoul;
  payload.GuestFoul = GuestFoul;
  payload.HomeTOut = HomeTOut;
  payload.GuestTOut = GuestTOut;
  payload.period = period;

  payload.GameTime_Minute = GameTime_Minute;
  payload.GameTime_Second = GameTime_Second;
  payload.GameTime_Millis = GameTime_Millis;

  payload.ShotClock_Second = ShotClock_Second;
  payload.ShotClock_Millis = ShotClock_Millis;

  payload.BallPoss = BallPoss;

  payload.buzzer = buzzer;
  payload.GT_SC_sync = GT_SC_sync;

  payload.SetupMode = SetupMode;
  payload.DataToSet = DataToSet;

  payload.TeamNameSetupMode = TeamNameSetupMode;

  payload.EndOfGame = EndOfGame;

  NRF.write(&payload, sizeof(Payload_Data));
}