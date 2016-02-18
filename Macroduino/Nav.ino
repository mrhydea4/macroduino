
void NavController(){
  
  uint8_t buttons = lcd.readButtons();
  if (buttons) {
    if (buttons & BUTTON_UP && lastKey != KEY_UP) {
      ButtonUp();
    }
    if (buttons & BUTTON_DOWN && lastKey != KEY_DOWN) {
      ButtonDown();
    }
    if (buttons & BUTTON_LEFT && lastKey != KEY_LEFT) {
      ButtonLeft();
    }
    if (buttons & BUTTON_RIGHT && lastKey != KEY_RIGHT) {
      ButtonRight();
    }      
    if (buttons & BUTTON_SELECT && lastKey != KEY_SELECT) {
      ButtonSelect();
    }
    lastButton = millis();
  } else {
    lastKey = KEY_NONE;
  }
}

void ButtonUp() {
  switch (systemState) {
    case State::Nav: {
        // Move to previous menu item
        engine->navigate(engine->getPrev());
        dirtyDisplay = true;               
      break;
    }
    case State::EditInt: {
      *currentIntParam += 10;
      *currentIntParam = min(*currentIntParam, maxValue);
      MyDelay(250);
      dirtyDisplay = true;
      break;              
    }
    case State::EditBool: {
      *currentBoolParam = !*currentBoolParam;
      MyDelay(250);
      dirtyDisplay = true;
      break;
    }
    case State::EditSel: {
      *currentIntParam += 1;
      *currentIntParam = min(*currentIntParam, maxValue);
      MyDelay(250);
      dirtyDisplay = true;
      break;
    }
  }
  lastKey = KEY_UP;
}

void ButtonDown() {
  switch (systemState) {
    case State::Nav: {
        // Move to next menu item
        engine->navigate(engine->getNext());
        dirtyDisplay = true;        
      break;
    }
    case State::EditInt: {
      if (*currentIntParam >= 10) {
        *currentIntParam -= 10;
        *currentIntParam = max(*currentIntParam, minValue);
      }
      MyDelay(250);
      dirtyDisplay = true;        
      break;
    }
    case State::EditBool: {
      *currentBoolParam = !*currentBoolParam;
      MyDelay(250);
      dirtyDisplay = true;
      break;
    }
    case State::EditSel: {
      if (*currentIntParam >= 1) {
        *currentIntParam -= 1;
        *currentIntParam = max(*currentIntParam, minValue);
      }
      if (currentIntParam == &fNumberScale) {
        fNumberIndex = 0;
      }
      MyDelay(250);
      dirtyDisplay = true;        
      break;
    }
  }
  lastKey = KEY_DOWN;
}

void ButtonLeft() {
  switch (systemState) {
    case State::Nav: {
        // Move to parent menu item
        engine->navigate(engine->getParent());
        dirtyDisplay = true;        
      break;
    }
    case State::EditInt: {
      if (*currentIntParam >= 1) {
        *currentIntParam -= 1;
        *currentIntParam = max(*currentIntParam, minValue);
      }
      MyDelay(250);
      dirtyDisplay = true;        
      break;      
    }
    case State::EditBool: {
      *currentBoolParam = !*currentBoolParam;
      MyDelay(250);
      dirtyDisplay = true;
      break;
    }
    case State::EditSel: {
      if (*currentIntParam >= 1) {
        *currentIntParam -= 1;
        *currentIntParam = max(*currentIntParam, minValue);
      }
      if (*currentIntParam == (uint32_t)fNumberScale) {
        fNumberIndex = 0;
      }
      MyDelay(250);
      dirtyDisplay = true;        
      break;
    }
  }
  lastKey = KEY_LEFT;
}

void ButtonRight() {
  switch (systemState) {
    case State::Nav: {
        // Move to child menu item or to the parameter adjustment
        engine->navigate(engine->getChild());
        dirtyDisplay = true;        
      break;
    }
    case State::EditInt: {
      *currentIntParam += 1;
      *currentIntParam = min(*currentIntParam, maxValue);
      MyDelay(250);
      dirtyDisplay = true;        
      break;
    }
    case State::EditBool: {
      *currentBoolParam = !*currentBoolParam;
      MyDelay(250);
      dirtyDisplay = true;
      break;
    }
    case State::EditSel: {
      *currentIntParam += 1;
      *currentIntParam = min(*currentIntParam, maxValue);
      MyDelay(250);
      dirtyDisplay = true;        
      break;
    }
  }
  lastKey = KEY_RIGHT;
}

void ButtonSelect() {
  switch (systemState) {
    default: {
        // Triggers State::Edit for the current variable
        engine->invoke();
        dirtyDisplay = true;        
      break;
    }
  }
  lastKey = KEY_SELECT;
}

