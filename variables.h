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
uint8_t GameTime_Minute = 10;
uint8_t GameTime_Second = 0;
uint8_t GameTime_Millis = 0;

uint8_t ShotClock_Second = 24;
uint8_t ShotClock_Millis = 0;

uint8_t period = 1;

bool buzzer = false;
//#############################################
uint8_t autoBuzz = 0;
bool autoBuzzToggle = false;

uint8_t BallPoss = 0;

//interrupts
uint16_t isr_tmr_GTcounter = 0;
bool GT_started = false;

uint16_t isr_tmr_SCcounter = 0;
bool SC_started = false;

//Push Buttons
uint8_t PB_ScanCount = 0;
bool status_PB[18];  //16+2 just to be sure

//msc
bool GT_SC_sync = false;
bool Start_FirstPress=false;

bool SetupMode = false;
uint8_t DataToSet = 0;

bool TeamNameSetupMode = false;

bool NRF_UpdateTN = false;
uint32_t UpdateTN_Micros = 0;


uint32_t buzz_micros = 0;
bool EndOfGame=false;
//TeamNames
char HomeTeam_UP[10] = "HOME-TEAM ";
char HomeTeam_DW[10] = "LIGHT-TEAM";
char GuestTeam_UP[10] = "VISIT-TEAM";
char GuestTeam_DW[10] = "DARK-TEAM ";

// char HomeTeam_UP[10] = "ATENEO    ";
// char HomeTeam_DW[10] = "DE MANILA ";
// char GuestTeam_UP[10] = "LA SALLE  ";
// char GuestTeam_DW[10] = "GREENHILLS";

uint8_t TN_CurrentChange = 0;
uint8_t TN_ButtonAssign = 0;
uint8_t TN_CurrentPress = 0;

char SpecificCharToChange = ' ';
bool TN_FirstPress = false;
uint8_t TN_Prev_ButtonAssign = 0;

//Which TeamName To Change
uint8_t TN_NowChanging = 0;
char prev_SpecificCharToChange = '>';

/*
  0=HomeTeam_UP
  1=HomeTeam_DW
  2=GuestTeam_UP
  3=GuestTeam_DW
*/
