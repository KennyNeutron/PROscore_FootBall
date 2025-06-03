//Variables used in this system are written here


//############ Basketball Variables ###########

//Basketball data
uint8_t HomeScore = 0;
uint8_t GuestScore = 0;

uint8_t HomeFoul = 0;
uint8_t GuestFoul = 0;

uint8_t HomeTOut = 0;
uint8_t GuestTOut = 0;

//Baskeball Time
uint8_t GameTime_Minute = 0;
uint8_t GameTime_Second = 0;
uint8_t GameTime_Millis = 0;

uint8_t ShotClock_Second = 24;
uint8_t ShotClock_Millis = 0;

uint8_t period = 1;
uint8_t BallPoss = 0;
//#############################################

//Display update
bool display_updated = false;

//interrupts
uint16_t isr_tmr_counter = 0;

//msc
bool GT_SC_sync = false;

bool SetupMode = false;
uint8_t DataToSet = 0;

uint32_t blinker_millis = 0;
bool blink = false;

bool EndOfGame = false;

//TeamNames
bool TeamNameSetupMode = false;
