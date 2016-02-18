
void StackController() {
  if (systemState == State::Normal) {
    NormalMode();
    systemState = State::Nav;
    lastButton = millis();
  }
  if (systemState == State::Expert) {
    ExpertMode();
    systemState = State::Nav;  
    lastButton = millis();
  }
  if (systemState == State::Abort) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Aborting");
    MyDelay(2000);
    systemState = State::Nav;
    lastButton = millis();
  }
}

void ExpertMode() {

  // Allow for everything to settle down before starting
  Countdown("Starting");

  // Go forward the total number of frames
  FrameLoop(expFrames, expSteps);

}

void NormalMode() {

  // Allow for everything to settle down before starting
  Countdown("Starting");

  // Back up the number of safety frames
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Adding safety");
  lcd.setCursor(0, 1);
  lcd.print("  frames");
  for (int i = 1; i <= safetyFrames; i++) {
    Serial.println(stepsPerFrame);
    myMotor->step(stepsPerFrame, BACKWARD, SINGLE);
    delay(500);
  }

  // Allow for everything to settle down before starting
  Countdown("Continuing");

  // Go forward the total number of frames
  FrameLoop(totalFrames, stepsPerFrame);

}

void Countdown(char s[]) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(s);
  lcd.print(" in");
  lcd.setCursor(0, 1);
  lcd.print("3...");
  delay(1000);
  lcd.print("2...");
  delay(1000);
  lcd.print("1...");
  delay(1000);  
}

void FrameLoop(int frames, int steps) {

  for (int i = 1; i <= frames; i++) {

    // Output the frame information
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Frame");
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd.print(" of ");
    lcd.print(frames);
    
    // Enable focus pin
    digitalWrite(pinFocus, HIGH);
    delay(focusPause);

    // Fire the shot
    digitalWrite(pinShutter, HIGH);
    delay(shutterPause);
    digitalWrite(pinShutter, LOW);

    // Release the focus pin
    digitalWrite(pinFocus, LOW);

    // Move the carriage between shots and allow for settling
    if (i < frames) {

      // Pause for the remaining portion of the configured interval
      delay(framePause);

      // Move the carriage
      myMotor->step(steps, FORWARD, SINGLE);

      // Allow the carriage to settle
      delay(settlePause);

    }

  }

  myMotor->release();
  
}

