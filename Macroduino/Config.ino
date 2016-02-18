

void ConfigController() {

  // Has the configuration changed?
  if (dirtyConfig) {

    // Does the configuration exist on EEPROM?
    uint8_t major = ReadIntegerFromEEPROM(EEPROM_ADDY_VERSION_MAJOR, 1);
    uint8_t minor = ReadIntegerFromEEPROM(EEPROM_ADDY_VERSION_MINOR, 1);
    uint8_t patch = ReadIntegerFromEEPROM(EEPROM_ADDY_VERSION_PATCH, 1);

    if (  major == VERSION_MAJOR &&
          minor == VERSION_MINOR &&
          patch == VERSION_PATCH
       ) {

      // If it does exist, load the saved configuration
      LoadConfiguration();
      }
    
    else {
      //If it does NOT exist, load the default configuration and save it to the EEPROM
      ResetConfiguration();
    }
  }
}

void LoadConfiguration() {
  expFrames =           ReadIntegerFromEEPROM(EEPROM_ADDY_EXP_FRAMES,       2);
  expSteps =            ReadIntegerFromEEPROM(EEPROM_ADDY_EXP_STEPS,        2);
  totalDist =           ReadIntegerFromEEPROM(EEPROM_ADDY_TOTAL_DIST,       2);
  frameOverlap =        ReadIntegerFromEEPROM(EEPROM_ADDY_FRAME_OVERLAP,    2);
  framePause =          ReadIntegerFromEEPROM(EEPROM_ADDY_FRAME_PAUSE,      2);
  safetyFrames =        ReadIntegerFromEEPROM(EEPROM_ADDY_SAFETY_FRAMES,    2);
  coc =                 ReadIntegerFromEEPROM(EEPROM_ADDY_COC,              2);
  focusPause =          ReadIntegerFromEEPROM(EEPROM_ADDY_FOCUS_PAUSE,      2);
  shutterPause =        ReadIntegerFromEEPROM(EEPROM_ADDY_SHUTTER_PAUSE,    2);
  fNumberScale =        ReadIntegerFromEEPROM(EEPROM_ADDY_F_NUMBER_SCALE,   2);
  focalLength =         ReadIntegerFromEEPROM(EEPROM_ADDY_FOCAL_LENGTH,     2);
  fNumberIndex =        ReadIntegerFromEEPROM(EEPROM_ADDY_F_NUMBER_INDEX,   2);
  focusDist =           ReadIntegerFromEEPROM(EEPROM_ADDY_FOCUS_DIST,       2);
  revPerMin =           ReadIntegerFromEEPROM(EEPROM_ADDY_REV_PER_MIN,      2);
  stepsPerRev =         ReadIntegerFromEEPROM(EEPROM_ADDY_STEPS_PER_REV,    2);
  distPerRev =          ReadIntegerFromEEPROM(EEPROM_ADDY_DIST_PER_REV,     2);
  settlePause =         ReadIntegerFromEEPROM(EEPROM_ADDY_SETTLE_PAUSE,     2);
  useBacklight =        ReadIntegerFromEEPROM(EEPROM_ADDY_USE_BACKLIGHT,    1);
  useSpeaker =          ReadIntegerFromEEPROM(EEPROM_ADDY_USE_SPEAKER,      1);

  switch (fNumberScale) {
    case F_NUMBER_SCALE_WHOLE:
      fNumber = pgm_read_float(NAV_LENS_SCALE_WHOLE_OPT_VALS + fNumberIndex);
      break;
    case F_NUMBER_SCALE_HALF:
      fNumber = pgm_read_float(NAV_LENS_SCALE_HALF_OPT_VALS + fNumberIndex);
      break;
    case F_NUMBER_SCALE_THIRD:
      fNumber = pgm_read_float(NAV_LENS_SCALE_THIRD_OPT_VALS + fNumberIndex);
      break;
    default:
      fNumber = 69.696969;
  }

  distPerStep = ( (double)distPerRev / 1000 ) / stepsPerRev;                                                      // mm - Linear travel per step
  hyperfocalDist = (pow(focalLength, 2) / (fNumber * (double)coc / 1000)) + focalLength;                          // mm - Hyperfocal distance
  nearFocus = (focusDist * (hyperfocalDist - focalLength)) / (hyperfocalDist + focusDist - (2 * focalLength));    // mm - Near distance of acceptable sharpness
  farFocus = (focusDist * (hyperfocalDist - focalLength)) / (hyperfocalDist - focusDist);                         // mm - Far distance of acceptable sharpness
  depthOfField = farFocus - nearFocus;                                                                            // mm - Depth of field
  depthOfFrame = depthOfField * (1 - ((double)frameOverlap/100));                                                 // mm - Depth of field minus the overlap
  stepsPerFrame = int(depthOfFrame / distPerStep);                                                                // Motor steps to move the required distance
  totalFrames = safetyFrames + int(totalDist / depthOfFrame) + safetyFrames;                                      // Total number of frames needed to cover the stack

  lcd.setBacklight(useBacklight);
  myMotor->setSpeed(revPerMin);
  
  dirtyConfig = false;

}

void ResetConfiguration() {
  UpdateVersion();
  LoadDefaultConfiguration();
  SaveConfiguration();
}

void UpdateVersion() {
  WriteIntegerToEEPROM(EEPROM_ADDY_VERSION_MAJOR, VERSION_MAJOR, 1);
  WriteIntegerToEEPROM(EEPROM_ADDY_VERSION_MINOR, VERSION_MINOR, 1);
  WriteIntegerToEEPROM(EEPROM_ADDY_VERSION_PATCH, VERSION_PATCH, 1);  
}

void LoadDefaultConfiguration() {
  expFrames =           DEFAULT_EXP_FRAMES;
  expSteps =            DEFAULT_EXP_STEPS;
  totalDist =           DEFAULT_TOTAL_DIST;
  frameOverlap =        DEFAULT_FRAME_OVERLAP;
  framePause =          DEFAULT_FRAME_PAUSE;
  safetyFrames =        DEFAULT_SAFETY_FRAMES;
  coc =                 DEFAULT_COC;
  focusPause =          DEFAULT_FOCUS_PAUSE;
  shutterPause =        DEFAULT_SHUTTER_PAUSE;
  fNumberScale =        DEFAULT_F_NUMBER_SCALE;
  focalLength =         DEFAULT_FOCAL_LENGTH;
  fNumberIndex =        DEFAULT_F_NUMBER_INDEX;
  focusDist =           DEFAULT_FOCUS_DIST;
  revPerMin =           DEFAULT_REV_PER_MIN;
  stepsPerRev =         DEFAULT_STEPS_PER_REV;
  distPerRev =          DEFAULT_DIST_PER_REV;
  settlePause =         DEFAULT_SETTLE_PAUSE;
  useBacklight =        DEFAULT_USE_BACKLIGHT;
  useSpeaker =          DEFAULT_USE_SPEAKER;
}

void SaveConfiguration() {
  for (unsigned int i = 0x04; i < EEPROM_SIZE; i++) {    
    // Skip over the Version locations
    EEPROM.write(i, 0x00);
  }

  WriteIntegerToEEPROM(EEPROM_ADDY_EXP_FRAMES,        expFrames,      2);
  WriteIntegerToEEPROM(EEPROM_ADDY_EXP_STEPS,         expSteps,       2);
  WriteIntegerToEEPROM(EEPROM_ADDY_TOTAL_DIST,        totalDist,      2);
  WriteIntegerToEEPROM(EEPROM_ADDY_FRAME_OVERLAP,     frameOverlap,   2);
  WriteIntegerToEEPROM(EEPROM_ADDY_FRAME_PAUSE,       framePause,     2);
  WriteIntegerToEEPROM(EEPROM_ADDY_SAFETY_FRAMES,     safetyFrames,   2);
  WriteIntegerToEEPROM(EEPROM_ADDY_COC,               coc,            2);
  WriteIntegerToEEPROM(EEPROM_ADDY_FOCUS_PAUSE,       focusPause,     2);
  WriteIntegerToEEPROM(EEPROM_ADDY_SHUTTER_PAUSE,     shutterPause,   2);
  WriteIntegerToEEPROM(EEPROM_ADDY_F_NUMBER_SCALE,    fNumberScale,   2);
  WriteIntegerToEEPROM(EEPROM_ADDY_FOCAL_LENGTH,      focalLength,    2);
  WriteIntegerToEEPROM(EEPROM_ADDY_F_NUMBER_INDEX,    fNumberIndex,   2);
  WriteIntegerToEEPROM(EEPROM_ADDY_FOCUS_DIST,        focusDist,      2);
  WriteIntegerToEEPROM(EEPROM_ADDY_REV_PER_MIN,       revPerMin,      2);
  WriteIntegerToEEPROM(EEPROM_ADDY_STEPS_PER_REV,     stepsPerRev,    2);
  WriteIntegerToEEPROM(EEPROM_ADDY_DIST_PER_REV,      distPerRev,     2);
  WriteIntegerToEEPROM(EEPROM_ADDY_SETTLE_PAUSE,      settlePause,    2);
  WriteIntegerToEEPROM(EEPROM_ADDY_USE_BACKLIGHT,     useBacklight,   1);
  WriteIntegerToEEPROM(EEPROM_ADDY_USE_SPEAKER,       useSpeaker,     1);
  // Trigger the flag to update the in-memory configuration
  dirtyConfig = true;
}

void WriteIntegerToEEPROM(unsigned int address, unsigned int value, unsigned int len) {
  for (int i = 0; i < len; i++) {
    int b = value / pow(256, len - i - 1);
    EEPROM.write(address + i, b);
    if ( b > 0 ) { 
      value -= b * pow(256, len - i - 1); 
    };
  }
}

uint16_t ReadIntegerFromEEPROM(unsigned int address, unsigned int len) {
  int readValue = 0;
  for (int i = 0; i < len; i++) {
    int b = EEPROM.read(address + i);
    readValue +=  b * pow(256, len - i - 1) + 0.5;   
  }
  return readValue;
}

