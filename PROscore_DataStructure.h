//Communication Data Structure
// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Payload_Data {
  uint8_t HomeScore = 0;
  uint8_t GuestScore = 0;

  uint8_t HomeFoul = 0;
  uint8_t GuestFoul = 0;

  uint8_t HomeTOut = 0;
  uint8_t GuestTOut = 0;

  uint8_t period = 1;

  uint8_t GameTime_Minute = 0;
  uint8_t GameTime_Second = 0;
  uint8_t GameTime_Millis = 0;

  uint8_t ShotClock_Second = 0;
  uint8_t ShotClock_Millis = 0;

  uint8_t BallPoss = 0;

  bool buzzer = false;
  bool GT_SC_sync = false;

  bool TeamNameSetupMode = false;

  bool SetupMode = false;
  uint8_t DataToSet = 0;

  uint8_t TN_ID = 0;
  char CurrentTeamName[10] = "xxxxxxxxxx";

  bool EndOfGame=false;
};

Payload_Data payload;  // Create a variable with the above structure
