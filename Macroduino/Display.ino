
void DisplayController() {
  if (dirtyDisplay) {
    UpdateDisplay();
  }
  if (millis() - lastButton > 15000) { lcd.setBacklight(false); };
}

void UpdateDisplay() {
  lcd.setBacklight(useBacklight);
  
  if (engine->currentItem != &navWelcome) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(engine->getLabel(engine->getParent(engine->currentItem)));
    lcd.setCursor(0, 1);
    switch (systemState) {
      case State::Nav: {
          if (engine->getLabel(engine->currentItem) == "int") {
            DisplayIntParam(false);
          } else if (engine->getLabel(engine->currentItem) == "bool") {
            DisplayBoolParam(false);
          } else if (engine->getLabel(engine->currentItem) == "sel") {
            DisplaySelParam(false);
          } else if (engine->getLabel(engine->currentItem) == "dbl") {
            DisplayDoubleParam();
          } else {
            lcd.print(engine->getLabel(engine->currentItem));
          };
          break;
        }
      case State::EditInt: {
          DisplayIntParam(true);
          break;
        }
      case State::EditBool: {
          DisplayBoolParam(true);
          break;
        }
      case State::EditSel: {
          DisplaySelParam(true);
          break;
        }
    }
  }
  dirtyDisplay = !dirtyDisplay;
}

void MyDelay(unsigned long wait) {
  unsigned long then = millis();
  do {

  }
  while (millis() - then < wait);
}

void DisplayIntParam(bool edit) {
  lcd.print(*currentIntParam);
  if (edit) {
    lcd.print("*");
  };
}

void DisplayDoubleParam() {
  lcd.print("=");
  lcd.print(*currentDoubleParam, DEC);
}

void DisplayBoolParam(bool edit) {
  if (*currentBoolParam) {
    lcd.print("YES");
  } else {
    lcd.print("NO");
  }
  if (edit) {
    lcd.print("*");
  };
}

void DisplaySelParam(bool edit) {
  char buffer[15];
  
  if (currentIntParam == &fNumberIndex) {
    switch (fNumberScale) {
      case F_NUMBER_SCALE_WHOLE: {
          strcpy_P(buffer, (char*)pgm_read_word(&(NAV_LENS_SCALE_WHOLE_OPT_TEXT[fNumberIndex])));
          lcd.print(buffer);
          break;
        }
      case F_NUMBER_SCALE_HALF: {
          strcpy_P(buffer, (char*)pgm_read_word(&(NAV_LENS_SCALE_HALF_OPT_TEXT[fNumberIndex])));
          lcd.print(buffer);
          break;
        }
      case F_NUMBER_SCALE_THIRD: {
          strcpy_P(buffer, (char*)pgm_read_word(&(NAV_LENS_SCALE_THIRD_OPT_TEXT[fNumberIndex])));
          lcd.print(buffer);
          break;
        }
    }
  } else if (currentIntParam == &fNumberScale) {
    strcpy_P(buffer, (char*)pgm_read_word(&(NAV_LENS_SCALE_OPT_TEXT[fNumberScale])));
    lcd.print(buffer);
  }

  if (edit) {
    lcd.print("*");
  };
}



