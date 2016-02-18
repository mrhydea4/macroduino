
uint8_t menuItemsVisible = 1;
uint8_t lastKey;
uint32_t lastButton;

void ToggleEditState(uint8_t state) {
  switch (systemState) {
    case State::Nav: {
        systemState = state;
        break;
      }
    default: {
        SaveConfiguration();
        systemState = State::Nav;
        break;
      }
  }
}

bool ShowWelcome(const Menu::Action_t action) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Macroduino");
  lcd.setCursor(0, 1);
  lcd.print("Get stacking!");
  return true;
}

bool ExpFramesEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &expFrames;
    minValue = 1;
    maxValue = 999;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    ExpFramesEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool ExpStepsEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &expSteps;
    minValue = 1;
    maxValue = 9999;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    ExpStepsEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool ExpRun(const Menu::Action_t action) {
  if (action == Menu::actionTrigger) {
    systemState = State::Expert;
  }  
}

bool TotalDistEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &totalDist;
    minValue = 1;
    maxValue = 88;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    TotalDistEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool FocusDistEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &focusDist;
    minValue = 1;
    maxValue = 65535;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FocusDistEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool FrameOverlapEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &frameOverlap;
    minValue = 1;
    maxValue = 99;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FrameOverlapEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool FramePauseEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &framePause;
    minValue = 0;
    maxValue = 999;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FramePauseEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool SafetyFramesEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &safetyFrames;
    minValue = 0;
    maxValue = 9;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    SafetyFramesEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool DepthOfFrameDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentDoubleParam = &depthOfFrame;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    DepthOfFrameDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool StepsPerFrameDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &stepsPerFrame;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    StepsPerFrameDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool TotalFramesDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &totalFrames;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    TotalFramesDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool FocalLengthEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &focalLength;
    minValue = 1;
    maxValue = 999;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FocalLengthEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool FNumberIndexEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &fNumberIndex;
    minValue = 0;
    switch (fNumberScale) {
      case F_NUMBER_SCALE_WHOLE: {
          maxValue = 12;
        }
      case F_NUMBER_SCALE_HALF: {
          maxValue = 24;
        }
      case F_NUMBER_SCALE_THIRD: {
          maxValue = 36;
        }
    }
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditSel);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FNumberIndexEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
}

bool FNumberScaleEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &fNumberScale;
    minValue = 0;
    maxValue = 2;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditSel);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FNumberScaleEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    Serial.println("actionParent");
    // navigating to self->parent
  }
}

bool CoCEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &coc;
    minValue = 0;
    maxValue = 9999;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    CoCEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool FocusPauseEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &focusPause;
    minValue = 0;
    maxValue = 999;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FocusPauseEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool ShutterPauseEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &shutterPause;
    minValue = 0;
    maxValue = 999;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    ShutterPauseEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool FNumberValueDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentDoubleParam = &fNumber;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FNumberValueDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool HyperfocalDistDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentDoubleParam = &hyperfocalDist;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    HyperfocalDistDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool NearFocusDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentDoubleParam = &nearFocus;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    NearFocusDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool FarFocusDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentDoubleParam = &farFocus;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    FarFocusDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool DepthOfFieldDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentDoubleParam = &depthOfField;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    DepthOfFieldDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool NormRun(const Menu::Action_t action) {
  if (action == Menu::actionTrigger) {
    systemState = State::Normal;
  }
}

bool RevPerMinEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &revPerMin;
    minValue = 15;
    maxValue = 120;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    RevPerMinEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool StepsPerRevEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &stepsPerRev;
    minValue = 1;
    maxValue = 65535;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    StepsPerRevEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool DistPerRevEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &distPerRev;
    minValue = 1;
    maxValue = 65535;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    DistPerRevEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool DistPerStepDisp(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentDoubleParam = &distPerStep;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    DistPerStepDisp(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool SettlePauseEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentIntParam = &settlePause;
    minValue = 0;
    maxValue = 999;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditInt);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    SettlePauseEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool UseBacklightEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentBoolParam = &useBacklight;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditBool);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    UseBacklightEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool UseSpeakerEdit(const Menu::Action_t action) {
  if (action == Menu::actionDisplay) {
    // initialy entering this menu item
    currentBoolParam = &useSpeaker;
  }
  if (action == Menu::actionTrigger) {
    // click on already active item
    ToggleEditState(State::EditBool);
  }
  if (action == Menu::actionLabel) {
    // show thy label but don't do anything yet
    UseSpeakerEdit(Menu::actionDisplay);
  }
  if (action == Menu::actionParent) {
    // navigating to self->parent
  }
  return true;
}

bool ResetConfig(const Menu::Action_t action) {
  if (action == Menu::actionTrigger) {
    // click on already active item
    ResetConfiguration();
  }
  return true;
}

bool NullCallback(const Menu::Action_t action) {
  return true;
}

// TODO


// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Menu Structure
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Name,                          Label,                Next,                   Previous,               Parent,                 Child,                    Callback
MenuItem(navWelcome,              "Macroduino",         navExpMode,             Menu::NullItem,         Menu::NullItem,         navExpMode,               ShowWelcome);

    MenuItem(navExpMode,              "Expert Mode",        navNormMode,            navWelcome,             navWelcome,             navExpFrames,             NullCallback);

        MenuItem(navExpFrames,            "Frames",             navExpSteps,            Menu::NullItem,         navExpMode,             navExpFramesEdit,         NullCallback);

        MenuItem(navExpSteps,             "Steps",              navExpRun,              navExpFrames,           navExpMode,             navExpStepsEdit,          NullCallback);
            MenuItem(navExpFramesEdit,        "int",                Menu::NullItem,         Menu::NullItem,         navExpFrames,           Menu::NullItem,           ExpFramesEdit);
    
        MenuItem(navExpRun,               "Run",                Menu::NullItem,         navExpSteps,            navExpMode,             Menu::NullItem,           ExpRun);
            MenuItem(navExpStepsEdit,         "int",                Menu::NullItem,         Menu::NullItem,         navExpSteps,            Menu::NullItem,           ExpStepsEdit);
  
    MenuItem(navNormMode,             "Normal Mode",        navSystem,              navExpMode,             navWelcome,             navStack,                 NullCallback);
  
        MenuItem(navStack,                "Stack",              navCamera,              Menu::NullItem,         navNormMode,            navTotalDist,             NullCallback);

            MenuItem(navTotalDist,            "Total Dist",         navFocusDist,           Menu::NullItem,         navStack,               navTotalDistEdit,         NullCallback);
                MenuItem(navTotalDistEdit,        "int",                Menu::NullItem,         Menu::NullItem,         navTotalDist,           Menu::NullItem,           TotalDistEdit);

            MenuItem(navFocusDist,            "Focus Dist",         navFrameOverlap,        navTotalDist,           navStack,               navFocusDistEdit,         NullCallback);
                MenuItem(navFocusDistEdit,        "int",                Menu::NullItem,         Menu::NullItem,         navFocusDist,           Menu::NullItem,           FocusDistEdit);        
  
            MenuItem(navFrameOverlap,         "Frame Overlap",      navSafetyFrames,        navFocusDist,           navStack,               navFrameOverlapEdit,      NullCallback);
                MenuItem(navFrameOverlapEdit,     "int",                Menu::NullItem,         Menu::NullItem,         navFrameOverlap,        Menu::NullItem,           FrameOverlapEdit);
            
            MenuItem(navSafetyFrames,         "Safety Frames",      navFramePause,          navFrameOverlap,        navStack,               navSafetyFramesEdit,      NullCallback);
                MenuItem(navSafetyFramesEdit,     "int",                Menu::NullItem,         Menu::NullItem,         navSafetyFrames,        Menu::NullItem,           SafetyFramesEdit);
            
            MenuItem(navFramePause,           "Frame Pause",        navDepthOfFrame,        navSafetyFrames,        navStack,               navFramePauseEdit,        NullCallback);
                MenuItem(navFramePauseEdit,       "int",                Menu::NullItem,         Menu::NullItem,         navFramePause,          Menu::NullItem,           FramePauseEdit);
            
            MenuItem(navDepthOfFrame,         "Depth of Frame",     navStepsPerFrame,       navFramePause,          navStack,               navDepthOfFrameDisp,      NullCallback);
                MenuItem(navDepthOfFrameDisp,     "dbl",                Menu::NullItem,         Menu::NullItem,         navDepthOfFrame,        Menu::NullItem,           DepthOfFrameDisp);
            
            MenuItem(navStepsPerFrame,        "Steps Per Frame",    navTotalFrames,         navDepthOfFrame,        navStack,               navStepsPerFrameDisp,     NullCallback);
                MenuItem(navStepsPerFrameDisp,    "int",                Menu::NullItem,         Menu::NullItem,         navStepsPerFrame,       Menu::NullItem,           StepsPerFrameDisp);
            
            MenuItem(navTotalFrames,          "Total Frames",       Menu::NullItem,         navStepsPerFrame,       navStack,               navTotalFramesDisp,       NullCallback);
                MenuItem(navTotalFramesDisp,      "int",                Menu::NullItem,         Menu::NullItem,         navTotalFrames,         Menu::NullItem,           TotalFramesDisp);


        MenuItem(navCamera,               "Camera/Lens",        navNormRun,             navStack,               navNormMode,            navFocalLength,           NullCallback);

            MenuItem(navFocalLength,          "Focal Length",       navFNumberIndex,        Menu::NullItem,         navCamera,              navFocalLengthEdit,       NullCallback);
                MenuItem(navFocalLengthEdit,      "int",                Menu::NullItem,         Menu::NullItem,         navFocalLength,         Menu::NullItem,           FocalLengthEdit);

            MenuItem(navFNumberIndex,         "F Number Index",     navFNumberScale,        navFocalLength,         navCamera,              navFNumberEdit,           NullCallback);
                MenuItem(navFNumberEdit,          "sel",                Menu::NullItem,         Menu::NullItem,         navFNumberIndex,        Menu::NullItem,           FNumberIndexEdit);
            
            MenuItem(navFNumberScale,         "F Number Scale",     navCoC,                 navFNumberIndex,        navCamera,              navFNumberScaleEdit,      NullCallback);
                MenuItem(navFNumberScaleEdit,     "sel",                Menu::NullItem,         Menu::NullItem,         navFNumberScale,        Menu::NullItem,           FNumberScaleEdit);
            
            MenuItem(navCoC,                  "Circ of Conf",       navFocusPause,          navFNumberScale,        navCamera,              navCoCEdit,               NullCallback);
                MenuItem(navCoCEdit,              "int",                Menu::NullItem,         Menu::NullItem,         navCoC,                 Menu::NullItem,           CoCEdit);
            
            MenuItem(navFocusPause,           "Focus Pause",        navShutterPause,        navCoC,                 navCamera,              navShutterPauseEdit,      NullCallback);
                MenuItem(navFocusPauseEdit,       "int",                Menu::NullItem,         Menu::NullItem,         navShutterPause,        Menu::NullItem,           ShutterPauseEdit);
            
            MenuItem(navShutterPause,         "Shutter Pause",      navFNumberValue,        navFocusPause,          navCamera,              navFocusPauseEdit,        NullCallback);
                MenuItem(navShutterPauseEdit,     "int",                Menu::NullItem,         Menu::NullItem,         navFocusPause,          Menu::NullItem,           FocusPauseEdit);
            
            MenuItem(navFNumberValue,         "F Number Value",     navHyperfocalDist,      navShutterPause,        navCamera,              navFNumberValueDisp,      NullCallback);
                MenuItem(navFNumberValueDisp,     "dbl",                Menu::NullItem,         Menu::NullItem,         navFNumberValue,        Menu::NullItem,           FNumberValueDisp);
            
            MenuItem(navHyperfocalDist,       "Hyperfocal Dist",    navNearFocus,           navFNumberValue,        navCamera,              navHyperfocalDistDisp,    NullCallback);
                MenuItem(navHyperfocalDistDisp,   "dbl",                Menu::NullItem,         Menu::NullItem,         navHyperfocalDist,      Menu::NullItem,           HyperfocalDistDisp);
            
            MenuItem(navNearFocus,            "Near Focus Dist",    navFarFocus,            navHyperfocalDist,      navCamera,              navNearFocusDisp,         NullCallback);
                MenuItem(navNearFocusDisp,        "dbl",                Menu::NullItem,         Menu::NullItem,         navNearFocus,           Menu::NullItem,           NearFocusDisp);
            
            MenuItem(navFarFocus,             "Far Focus Dist",     navDepthOfField,        navNearFocus,           navCamera,              navFarFocusDisp,          NullCallback);
                MenuItem(navFarFocusDisp,         "dbl",                Menu::NullItem,         Menu::NullItem,         navFarFocus,            Menu::NullItem,           FarFocusDisp);
            
            MenuItem(navDepthOfField,         "Depth of Field",     Menu::NullItem,         navFarFocus,            navCamera,              navDepthOfFieldDisp,      NullCallback);
                MenuItem(navDepthOfFieldDisp,     "dbl",                Menu::NullItem,         Menu::NullItem,         navDepthOfField,        Menu::NullItem,           DepthOfFieldDisp);
          
        MenuItem(navNormRun,              "Run",                Menu::NullItem,         navCamera,              navNormMode,            Menu::NullItem,           NormRun);
    
    MenuItem(navSystem,               "System",             Menu::NullItem,         navNormMode,            navWelcome,             navMotor,                 NullCallback);
  
        MenuItem(navMotor,                "Motor",              navRail,                Menu::NullItem,         navSystem,              navRevPerMin,             NullCallback);

            MenuItem(navRevPerMin,            "Revs Per Min",       navStepsPerRev,         Menu::NullItem,         navMotor,               navRevPerMinEdit,         NullCallback);
                MenuItem(navRevPerMinEdit,        "int",                Menu::NullItem,         Menu::NullItem,         navRevPerMin,           Menu::NullItem,           RevPerMinEdit);

            MenuItem(navStepsPerRev,          "Steps Per Rev",      Menu::NullItem,         navRevPerMin,           navMotor,               navStepsPerRevEdit,       NullCallback);
                MenuItem(navStepsPerRevEdit,      "int",                Menu::NullItem,         Menu::NullItem,         navStepsPerRev,         Menu::NullItem,           StepsPerRevEdit);

        MenuItem(navRail,                 "Rail",               navUseBacklight,        navMotor,               navSystem,              navDistPerRev,            NullCallback);
            MenuItem(navDistPerRev,           "Dist Per Rev",       navSettlePause,         Menu::NullItem,         navRail,                navDistPerRevEdit,        NullCallback);
                MenuItem(navDistPerRevEdit,       "int",                Menu::NullItem,         Menu::NullItem,         navDistPerRev,          Menu::NullItem,           DistPerRevEdit);

            MenuItem(navSettlePause,          "Settle Pause",       navDistPerStep,         navDistPerRev,          navRail,                navSettlePauseEdit,       NullCallback);
                MenuItem(navSettlePauseEdit,      "int",                Menu::NullItem,         Menu::NullItem,         navSettlePause,         Menu::NullItem,           SettlePauseEdit);
            
            MenuItem(navDistPerStep,          "Dist Per Step",      Menu::NullItem,         navSettlePause,         navRail,                navDistPerStepDisp,       NullCallback);
                MenuItem(navDistPerStepDisp,      "dbl",                Menu::NullItem,         Menu::NullItem,         navDistPerStep,         Menu::NullItem,           DistPerStepDisp);
        
        MenuItem(navUseBacklight,         "Use Backlight",      navUseSpeaker,          navRail,                navSystem,              navUseBacklightEdit,      NullCallback);
            MenuItem(navUseBacklightEdit,     "bool",                 Menu::NullItem,       Menu::NullItem,         navUseBacklight,        Menu::NullItem,           UseBacklightEdit);
        
        MenuItem(navUseSpeaker,           "Use Speaker",        navReset,               navUseBacklight,        navSystem,              navUseSpeakerEdit,        NullCallback);
            MenuItem(navUseSpeakerEdit,       "bool",                 Menu::NullItem,       Menu::NullItem,         navUseSpeaker,          Menu::NullItem,           UseSpeakerEdit);
        
        MenuItem(navReset,                "Reset",              Menu::NullItem,         navUseSpeaker,          navSystem,              Menu::NullItem,           ResetConfig);
    
                

