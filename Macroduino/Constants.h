
// Default parameter values - Please refer to the Global configuration parameters section for limits and options
const uint16_t  PROGMEM     DEFAULT_EXP_FRAMES =              10;     // count
const uint16_t  PROGMEM     DEFAULT_EXP_STEPS =               200;    // count
const uint16_t  PROGMEM     DEFAULT_TOTAL_DIST =              50;     // mm
const uint16_t  PROGMEM     DEFAULT_FRAME_OVERLAP =           25;     // %
const uint16_t  PROGMEM     DEFAULT_FRAME_PAUSE =             250;    // ms
const uint16_t  PROGMEM     DEFAULT_SAFETY_FRAMES =           5;      // count
const uint16_t  PROGMEM     DEFAULT_COC =                     30;     // um (micrometers)
const uint16_t  PROGMEM     DEFAULT_FOCUS_PAUSE =             300;    // ms
const uint16_t  PROGMEM     DEFAULT_SHUTTER_PAUSE =           100;    // ms
const uint16_t  PROGMEM     DEFAULT_F_NUMBER_SCALE =          2;      // Third
const uint16_t  PROGMEM     DEFAULT_F_NUMBER_INDEX =          27;     // f/22
const uint16_t  PROGMEM     DEFAULT_FOCAL_LENGTH =            105;    // mm
const uint16_t  PROGMEM     DEFAULT_FOCUS_DIST =              315;    // mm
const uint16_t  PROGMEM     DEFAULT_REV_PER_MIN =             120;    // count
const uint16_t  PROGMEM     DEFAULT_STEPS_PER_REV =           200;    // count
const uint16_t  PROGMEM     DEFAULT_DIST_PER_REV =            1060;   // um (micrometers)
const uint16_t  PROGMEM     DEFAULT_SETTLE_PAUSE =            100;    // ms
const bool      PROGMEM     DEFAULT_USE_BACKLIGHT =           true;   // Yes, use backlight
const bool      PROGMEM     DEFAULT_USE_SPEAKER =             true;   // Yes, use speaker

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// NOTE - User should not modify anything below this line
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// System constants
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const uint8_t   PROGMEM     VERSION_MAJOR =                   0;
const uint8_t   PROGMEM     VERSION_MINOR =                   0;
const uint8_t   PROGMEM     VERSION_PATCH =                   1;
const uint8_t   PROGMEM     KEY_NONE =                        0;
const uint8_t   PROGMEM     KEY_LEFT =                        1;
const uint8_t   PROGMEM     KEY_RIGHT =                       2;
const uint8_t   PROGMEM     KEY_UP =                          3;  
const uint8_t   PROGMEM     KEY_DOWN =                        4;
const uint8_t   PROGMEM     KEY_SELECT =                      5;
const uint8_t   PROGMEM     LCD_CHARS =                       16;
const uint8_t   PROGMEM     LCD_LINES =                       2;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Sled limit constants
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const uint16_t  PROGMEM     SLED_RESET_POS =                  90;
const uint16_t  PROGMEM     SLED_ZERO_POS =                   0;
const uint16_t  PROGMEM     SLED_MAX_POS =                    17000;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// EEPROM addresses for storing configuration values
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const byte      PROGMEM     EEPROM_SIZE =                     0x50;
const byte      PROGMEM     EEPROM_ADDY_VERSION_MAJOR =       0x00;
const byte      PROGMEM     EEPROM_ADDY_VERSION_MINOR =       0x01;
const byte      PROGMEM     EEPROM_ADDY_VERSION_PATCH =       0x02;
const byte      PROGMEM     EEPROM_ADDY_EXP_FRAMES =          0x04;
const byte      PROGMEM     EEPROM_ADDY_EXP_STEPS =           0x06;
const byte      PROGMEM     EEPROM_ADDY_TOTAL_DIST =          0x08;
const byte      PROGMEM     EEPROM_ADDY_FRAME_OVERLAP =       0x0A;
const byte      PROGMEM     EEPROM_ADDY_FRAME_PAUSE =         0x0C;
const byte      PROGMEM     EEPROM_ADDY_SAFETY_FRAMES =       0x0E;
const byte      PROGMEM     EEPROM_ADDY_COC =                 0x10;
const byte      PROGMEM     EEPROM_ADDY_FOCUS_PAUSE =         0x12;
const byte      PROGMEM     EEPROM_ADDY_SHUTTER_PAUSE =       0x14;
const byte      PROGMEM     EEPROM_ADDY_F_NUMBER_SCALE =      0x16;
const byte      PROGMEM     EEPROM_ADDY_FOCAL_LENGTH =        0x18;
const byte      PROGMEM     EEPROM_ADDY_F_NUMBER_INDEX =      0x1A;
const byte      PROGMEM     EEPROM_ADDY_FOCUS_DIST =          0x1C;
const byte      PROGMEM     EEPROM_ADDY_REV_PER_MIN =         0x1E;
const byte      PROGMEM     EEPROM_ADDY_STEPS_PER_REV =       0x20;
const byte      PROGMEM     EEPROM_ADDY_DIST_PER_REV =        0x22;
const byte      PROGMEM     EEPROM_ADDY_SETTLE_PAUSE =        0x24;
const byte      PROGMEM     EEPROM_ADDY_USE_BACKLIGHT =       0x26;
const byte      PROGMEM     EEPROM_ADDY_USE_SPEAKER =         0x27;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// F Number Scale CONSTANTS
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const uint8_t   PROGMEM     F_NUMBER_SCALE_WHOLE =            0;
const uint8_t   PROGMEM     F_NUMBER_SCALE_HALF =             1;
const uint8_t   PROGMEM     F_NUMBER_SCALE_THIRD =            2;

const char NAV_F_NUMBER_SCALE_WHOLE[] PROGMEM = "Whole";
const char NAV_F_NUMBER_SCALE_HALF[] PROGMEM = "Half";
const char NAV_F_NUMBER_SCALE_THIRD[] PROGMEM = "Third";

const char* const NAV_LENS_SCALE_OPT_TEXT[] PROGMEM = { 
  NAV_F_NUMBER_SCALE_WHOLE, 
  NAV_F_NUMBER_SCALE_HALF, 
  NAV_F_NUMBER_SCALE_THIRD
};

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Full Stop Scale Constants
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const char NAV_F_NUMBER_WHOLE_1[] PROGMEM = "f/1";
const char NAV_F_NUMBER_WHOLE_1_4[] PROGMEM = "f/1.4";
const char NAV_F_NUMBER_WHOLE_2[] PROGMEM = "f/2";
const char NAV_F_NUMBER_WHOLE_2_8[] PROGMEM = "f/2.8";
const char NAV_F_NUMBER_WHOLE_4[] PROGMEM = "f/4";
const char NAV_F_NUMBER_WHOLE_5_6[] PROGMEM = "f/5.6";
const char NAV_F_NUMBER_WHOLE_8[] PROGMEM = "f/8";
const char NAV_F_NUMBER_WHOLE_11[] PROGMEM = "f/11";
const char NAV_F_NUMBER_WHOLE_16[] PROGMEM = "f/16";
const char NAV_F_NUMBER_WHOLE_22[] PROGMEM = "f/22";
const char NAV_F_NUMBER_WHOLE_32[] PROGMEM = "f/32";
const char NAV_F_NUMBER_WHOLE_45[] PROGMEM = "f/45";
const char NAV_F_NUMBER_WHOLE_64[] PROGMEM = "f/64";

const char* const NAV_LENS_SCALE_WHOLE_OPT_TEXT[] PROGMEM = {
  NAV_F_NUMBER_WHOLE_1, NAV_F_NUMBER_WHOLE_1_4, NAV_F_NUMBER_WHOLE_2, NAV_F_NUMBER_WHOLE_2_8, 
  NAV_F_NUMBER_WHOLE_4, NAV_F_NUMBER_WHOLE_5_6, NAV_F_NUMBER_WHOLE_8, NAV_F_NUMBER_WHOLE_11,
  NAV_F_NUMBER_WHOLE_16, NAV_F_NUMBER_WHOLE_22, NAV_F_NUMBER_WHOLE_32, NAV_F_NUMBER_WHOLE_45, 
  NAV_F_NUMBER_WHOLE_64
};

const double PROGMEM F_NUMBER_WHOLE_1 = 1;
const double PROGMEM F_NUMBER_WHOLE_1_4 = 1.414214;
const double PROGMEM F_NUMBER_WHOLE_2 = 2;
const double PROGMEM F_NUMBER_WHOLE_2_8 = 2.828427;
const double PROGMEM F_NUMBER_WHOLE_4 = 4;
const double PROGMEM F_NUMBER_WHOLE_5_6 = 5.656854;
const double PROGMEM F_NUMBER_WHOLE_8 = 8;
const double PROGMEM F_NUMBER_WHOLE_11 = 11.313708;
const double PROGMEM F_NUMBER_WHOLE_16 = 16;
const double PROGMEM F_NUMBER_WHOLE_22 = 22.627417;
const double PROGMEM F_NUMBER_WHOLE_32 = 32;
const double PROGMEM F_NUMBER_WHOLE_45 = 45.254834;
const double PROGMEM F_NUMBER_WHOLE_64 = 64;

const PROGMEM double NAV_LENS_SCALE_WHOLE_OPT_VALS[13] = {   
  F_NUMBER_WHOLE_1, F_NUMBER_WHOLE_1_4, F_NUMBER_WHOLE_2, F_NUMBER_WHOLE_2_8, 
  F_NUMBER_WHOLE_4, F_NUMBER_WHOLE_5_6, F_NUMBER_WHOLE_8, F_NUMBER_WHOLE_11,
  F_NUMBER_WHOLE_16, F_NUMBER_WHOLE_22, F_NUMBER_WHOLE_32, F_NUMBER_WHOLE_45, 
  F_NUMBER_WHOLE_64
};

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Half Stop Scale Constants
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const char NAV_F_NUMBER_HALF_1_2[] PROGMEM = "f/1.2";
const char NAV_F_NUMBER_HALF_1_7[] PROGMEM = "f/1.7";
const char NAV_F_NUMBER_HALF_2_4[] PROGMEM = "f/2.4";
const char NAV_F_NUMBER_HALF_3_3[] PROGMEM = "f/3.3";
const char NAV_F_NUMBER_HALF_4_8[] PROGMEM = "f/4.8";
const char NAV_F_NUMBER_HALF_6_7[] PROGMEM = "f/6.7";
const char NAV_F_NUMBER_HALF_9_5[] PROGMEM = "f/9.5";
const char NAV_F_NUMBER_HALF_13[] PROGMEM = "f/13";
const char NAV_F_NUMBER_HALF_19[] PROGMEM = "f/19";
const char NAV_F_NUMBER_HALF_27[] PROGMEM = "f/27";
const char NAV_F_NUMBER_HALF_38[] PROGMEM = "f/38";
const char NAV_F_NUMBER_HALF_54[] PROGMEM = "f/54";

const char* const NAV_LENS_SCALE_HALF_OPT_TEXT[] PROGMEM = {
  NAV_F_NUMBER_WHOLE_1, NAV_F_NUMBER_HALF_1_2, NAV_F_NUMBER_WHOLE_1_4, NAV_F_NUMBER_HALF_1_7, 
  NAV_F_NUMBER_WHOLE_2, NAV_F_NUMBER_HALF_2_4, NAV_F_NUMBER_WHOLE_2_8, NAV_F_NUMBER_HALF_3_3, 
  NAV_F_NUMBER_WHOLE_4, NAV_F_NUMBER_HALF_4_8, NAV_F_NUMBER_WHOLE_5_6, NAV_F_NUMBER_HALF_6_7, 
  NAV_F_NUMBER_WHOLE_8, NAV_F_NUMBER_HALF_9_5, NAV_F_NUMBER_WHOLE_11, NAV_F_NUMBER_HALF_13, 
  NAV_F_NUMBER_WHOLE_16, NAV_F_NUMBER_HALF_19, NAV_F_NUMBER_WHOLE_22, NAV_F_NUMBER_HALF_27, 
  NAV_F_NUMBER_WHOLE_32, NAV_F_NUMBER_HALF_38, NAV_F_NUMBER_WHOLE_45, NAV_F_NUMBER_HALF_54, 
  NAV_F_NUMBER_WHOLE_64
};

const double PROGMEM F_NUMBER_HALF_1_2 = 1.189207;
const double PROGMEM F_NUMBER_HALF_1_7 = 1.681793;
const double PROGMEM F_NUMBER_HALF_2_4 = 2.378414;
const double PROGMEM F_NUMBER_HALF_3_3 = 3.363586;
const double PROGMEM F_NUMBER_HALF_4_8 = 4.756828;
const double PROGMEM F_NUMBER_HALF_6_7 = 6.727171;
const double PROGMEM F_NUMBER_HALF_9_5 = 9.513657;
const double PROGMEM F_NUMBER_HALF_13 = 13.454343;
const double PROGMEM F_NUMBER_HALF_19 = 19.027314;
const double PROGMEM F_NUMBER_HALF_27 = 26.908685;
const double PROGMEM F_NUMBER_HALF_38 = 38.054628;
const double PROGMEM F_NUMBER_HALF_54 = 53.817371;

const PROGMEM double NAV_LENS_SCALE_HALF_OPT_VALS[25] = {   
  F_NUMBER_WHOLE_1, F_NUMBER_HALF_1_2, F_NUMBER_WHOLE_1_4, F_NUMBER_HALF_1_7, 
  F_NUMBER_WHOLE_2, F_NUMBER_HALF_2_4, F_NUMBER_WHOLE_2_8, F_NUMBER_HALF_3_3, 
  F_NUMBER_WHOLE_4, F_NUMBER_HALF_4_8, F_NUMBER_WHOLE_5_6, F_NUMBER_HALF_6_7, 
  F_NUMBER_WHOLE_8, F_NUMBER_HALF_9_5, F_NUMBER_WHOLE_11, F_NUMBER_HALF_13, 
  F_NUMBER_WHOLE_16, F_NUMBER_HALF_19, F_NUMBER_WHOLE_22, F_NUMBER_HALF_27, 
  F_NUMBER_WHOLE_32, F_NUMBER_HALF_38, F_NUMBER_WHOLE_45, F_NUMBER_HALF_54, 
  F_NUMBER_WHOLE_64
};

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Third Stop Scale Constants
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const char NAV_F_NUMBER_THIRD_1_1[] PROGMEM = "f/1.1";
const char NAV_F_NUMBER_THIRD_1_2[] PROGMEM = "f/1.2";
const char NAV_F_NUMBER_THIRD_1_6[] PROGMEM = "f/1.6";
const char NAV_F_NUMBER_THIRD_1_8[] PROGMEM = "f/1.8";
const char NAV_F_NUMBER_THIRD_2_2[] PROGMEM = "f/2.2";
const char NAV_F_NUMBER_THIRD_2_5[] PROGMEM = "f/2.5";
const char NAV_F_NUMBER_THIRD_3_2[] PROGMEM = "f/3.2";
const char NAV_F_NUMBER_THIRD_3_5[] PROGMEM = "f/3.5";
const char NAV_F_NUMBER_THIRD_4_5[] PROGMEM = "f/4.5";
const char NAV_F_NUMBER_THIRD_5[] PROGMEM = "f/5";
const char NAV_F_NUMBER_THIRD_6_3[] PROGMEM = "f/6.3";
const char NAV_F_NUMBER_THIRD_7_1[] PROGMEM = "f/7.1";
const char NAV_F_NUMBER_THIRD_9[] PROGMEM = "f/9";
const char NAV_F_NUMBER_THIRD_10[] PROGMEM = "f/10";
const char NAV_F_NUMBER_THIRD_13[] PROGMEM = "f/13";
const char NAV_F_NUMBER_THIRD_14[] PROGMEM = "f/14";
const char NAV_F_NUMBER_THIRD_18[] PROGMEM = "f/18";
const char NAV_F_NUMBER_THIRD_20[] PROGMEM = "f/20";
const char NAV_F_NUMBER_THIRD_25[] PROGMEM = "f/25";
const char NAV_F_NUMBER_THIRD_29[] PROGMEM = "f/29";
const char NAV_F_NUMBER_THIRD_36[] PROGMEM = "f/36";
const char NAV_F_NUMBER_THIRD_40[] PROGMEM = "f/40";
const char NAV_F_NUMBER_THIRD_51[] PROGMEM = "f/51";
const char NAV_F_NUMBER_THIRD_57[] PROGMEM = "f/57";

const char* const NAV_LENS_SCALE_THIRD_OPT_TEXT[] PROGMEM = {
  NAV_F_NUMBER_WHOLE_1, NAV_F_NUMBER_THIRD_1_1, NAV_F_NUMBER_THIRD_1_2, NAV_F_NUMBER_WHOLE_1_4, NAV_F_NUMBER_THIRD_1_6, NAV_F_NUMBER_THIRD_1_8, 
  NAV_F_NUMBER_WHOLE_2, NAV_F_NUMBER_THIRD_2_2, NAV_F_NUMBER_THIRD_2_5, NAV_F_NUMBER_WHOLE_2_8, NAV_F_NUMBER_THIRD_3_2, NAV_F_NUMBER_THIRD_3_5, 
  NAV_F_NUMBER_WHOLE_4, NAV_F_NUMBER_THIRD_4_5, NAV_F_NUMBER_THIRD_5, NAV_F_NUMBER_WHOLE_5_6, NAV_F_NUMBER_THIRD_6_3, NAV_F_NUMBER_THIRD_7_1, 
  NAV_F_NUMBER_WHOLE_8, NAV_F_NUMBER_THIRD_9, NAV_F_NUMBER_THIRD_10, NAV_F_NUMBER_WHOLE_11, NAV_F_NUMBER_THIRD_13, NAV_F_NUMBER_THIRD_14, 
  NAV_F_NUMBER_WHOLE_16, NAV_F_NUMBER_THIRD_18, NAV_F_NUMBER_THIRD_20, NAV_F_NUMBER_WHOLE_22, NAV_F_NUMBER_THIRD_25, NAV_F_NUMBER_THIRD_29, 
  NAV_F_NUMBER_WHOLE_32, NAV_F_NUMBER_THIRD_36, NAV_F_NUMBER_THIRD_40, NAV_F_NUMBER_WHOLE_45, NAV_F_NUMBER_THIRD_51, NAV_F_NUMBER_THIRD_57, 
  NAV_F_NUMBER_WHOLE_64
};

const double PROGMEM F_NUMBER_THIRD_1_1 = 1.122462;
const double PROGMEM F_NUMBER_THIRD_1_2 = 1.259921;
const double PROGMEM F_NUMBER_THIRD_1_6 = 1.587401;
const double PROGMEM F_NUMBER_THIRD_1_8 = 1.781797;
const double PROGMEM F_NUMBER_THIRD_2_2 = 2.244924;
const double PROGMEM F_NUMBER_THIRD_2_5 = 2.519842;
const double PROGMEM F_NUMBER_THIRD_3_2 = 3.174802;
const double PROGMEM F_NUMBER_THIRD_3_5 = 3.563595;
const double PROGMEM F_NUMBER_THIRD_4_5 = 4.489848;
const double PROGMEM F_NUMBER_THIRD_5 = 5.039684;
const double PROGMEM F_NUMBER_THIRD_6_3 = 6.349604;
const double PROGMEM F_NUMBER_THIRD_7_1 = 7.12719;
const double PROGMEM F_NUMBER_THIRD_9 = 8.979696;
const double PROGMEM F_NUMBER_THIRD_10 = 10.079368;
const double PROGMEM F_NUMBER_THIRD_13 = 12.699208;
const double PROGMEM F_NUMBER_THIRD_14 = 14.254379;
const double PROGMEM F_NUMBER_THIRD_18 = 17.959393;
const double PROGMEM F_NUMBER_THIRD_20 = 20.158737;
const double PROGMEM F_NUMBER_THIRD_25 = 25.398417;
const double PROGMEM F_NUMBER_THIRD_29 = 28.508759;
const double PROGMEM F_NUMBER_THIRD_36 = 35.918786;
const double PROGMEM F_NUMBER_THIRD_40 = 40.317474;
const double PROGMEM F_NUMBER_THIRD_51 = 50.796834;
const double PROGMEM F_NUMBER_THIRD_57 = 57.017518;

const PROGMEM double NAV_LENS_SCALE_THIRD_OPT_VALS[37] = {   
  F_NUMBER_WHOLE_1, F_NUMBER_THIRD_1_1, F_NUMBER_THIRD_1_2, F_NUMBER_WHOLE_1_4, F_NUMBER_THIRD_1_6, F_NUMBER_THIRD_1_8, 
  F_NUMBER_WHOLE_2, F_NUMBER_THIRD_2_2, F_NUMBER_THIRD_2_5, F_NUMBER_WHOLE_2_8, F_NUMBER_THIRD_3_2, F_NUMBER_THIRD_3_5, 
  F_NUMBER_WHOLE_4, F_NUMBER_THIRD_4_5, F_NUMBER_THIRD_5, F_NUMBER_WHOLE_5_6, F_NUMBER_THIRD_6_3, F_NUMBER_THIRD_7_1, 
  F_NUMBER_WHOLE_8, F_NUMBER_THIRD_9, F_NUMBER_THIRD_10, F_NUMBER_WHOLE_11, F_NUMBER_THIRD_13, F_NUMBER_THIRD_14, 
  F_NUMBER_WHOLE_16, F_NUMBER_THIRD_18, F_NUMBER_THIRD_20, F_NUMBER_WHOLE_22, F_NUMBER_THIRD_25, F_NUMBER_THIRD_29, 
  F_NUMBER_WHOLE_32, F_NUMBER_THIRD_36, F_NUMBER_THIRD_40, F_NUMBER_WHOLE_45, F_NUMBER_THIRD_51, F_NUMBER_THIRD_57, 
  F_NUMBER_WHOLE_64
};


