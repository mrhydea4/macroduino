// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// NOTE - User should not modify anything below this line
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// External includes
#include <avr/pgmspace.h>
#include <EEPROM.h>
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
#include <Menu.h>

// Internal includes
#include "./Constants.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Global configuration parameters
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Expert Mode Frames
//    units = count
//    minValue = 1
//    maxValue = 999
uint16_t expFrames;

// Expert Mode Steps
//    units = count
//    minValue = 1
//    maxValue = 9999
uint16_t expSteps;

// Total Distance - the total depth of the stack
//    units = millimeters 
//    minValue = 1
//    maxValue = 88 - physically limited by length of rails
uint16_t totalDist;

// Frame Overlap - how much each frame will overlap the next for alignment purposes
//    units = %
//    minValue = 1
//    maxValue = 99
uint16_t frameOverlap;

// Frame Pause - how long to wait after each frame cycle is complete
//    units = milliseconds
//    minValue = 0
//    maxValue = 999
uint16_t framePause;

// Safety Frames - how many frames to add on the beginning and end to ensure you get the complete result
//    units = each
//    minValue = 0
//    maxValue = 9
uint16_t safetyFrames;

// Circle of Confusion - the smallest part of the image that is acceptably sharp - comes from your camera manual
//    units = micrometers (millimeters x 1000), e.g. 0.03mm = 30um
//    minValue = 0
//    maxValue = 9999
uint16_t coc;

// Focus Pause - how long the focus aka "half-press" must be engaged
//    units = milliseconds
//    minValue = 0
//    maxValue = 999
uint16_t focusPause;

// Shutter Pause - how long the shutter aka "full press" must be engaged
//    units = milliseconds
//    minValue = 0
//    maxValue = 999
uint16_t shutterPause;

// Focal Length - the value of your lens
//    units = millimeters
//    minValue = 1
//    maxValue = 999
uint16_t focalLength;

// F-Number Scale - selects whether the F-Number selection is based on whole stops, half stops or third stops
//    values = Whole | Half | Third
uint16_t fNumberScale;

// F-Number Index - within the selected F-Number Scale, the index of the selected value
//    values = Whole = 13 | Half = 25 | Third = 37
uint16_t fNumberIndex;

// Focus Distance - the distance to which your lens is focused
//    units = millimeters
//    minValue = 0
//    maxValue = 65535
uint16_t focusDist;

// Revolutions per Minute - the desired spin rate of the stepper motor
//    units = each
//    minValue = 15
//    maxValue = 120
uint16_t revPerMin;

// Steps per Revolution - the number of steps per revolution of the stepper motor, usually 200 or 400
//    units = each
//    minValue = 1
//    maxValue = 65535 ** This is very high because geared motors can increased the effective number of steps
uint16_t stepsPerRev;

// Distance per Revolution - how far the macro rail moves per each revolution of the lead screw
//    units = micrometers (millimeters x 1000), e.g. 1.06mm = 1060um
//    minValue = 1
//    maxValue = 65535 ** This value is also very high due to the possibility of gearing
uint16_t distPerRev;

// Settle Pause - how long the camera and sled are allowed to come to rest after moving
//    units = milliseconds
//    minValue = 0
//    maxValue = 999
uint16_t settlePause;

// Use Backlight - whether or not to light the LCD for better visibility
//    values = True | False
bool useBacklight;

// Use Speaker - for future use if a speaker is included on the board
//    values = True | False
bool useSpeaker;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Global configuration calculations
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Distance per Step - how far the camera/sled travel for each step of the motor
//    units = millimeters
double distPerStep;

// F-Number - the ratio of the focal length to the aperture
//    units = n/a
double fNumber;

// Hyperfocal Distance - the distance between a camera lens and the closest object that is in focus
// when the lens is focused to infinity
//    units = millimeters
double hyperfocalDist;

// Near Focus Distance - based on the current settings, the closest point to the camera lens that is
// in focus
//    units = millimeters
double nearFocus;

// Far Focus Distance - based on the current settings, the farthes point to the camera lens that is
// in focus
//    units = millimeters
double farFocus;

// Depth of Field - distance between the nearest and farthest objects that appear in acceptably sharp focus
//    units = millimeters
double depthOfField;

// Distance per Frame - based on the Depth of Field and Frame Overlap values
//    units = millimeters
double depthOfFrame;

// Steps per Frame - calculated number of steps required for each frame
//    units = each
uint16_t stepsPerFrame;

// Total Frames - number of frames needed to cover the Total Distance, including the Safety Frames
uint16_t totalFrames;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// System state variables
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Does the configuration need to be reloaded because of a reset or change?
bool dirtyConfig = true;

// Does the display need to be updated?
bool dirtyDisplay = true;

// State machine
namespace State {  
  typedef enum SystemMode_e {
    None      = 0,
    Nav       = (1<<0),
    EditInt   = (1<<1),
    EditBool  = (1<<2),
    EditSel   = (1<<3),
    Normal    = (1<<4),
    Expert    = (1<<5),
    Abort     = (1<<6)
  } SystemMode;
};
uint8_t systemState;

uint16_t *currentIntParam;
double *currentDoubleParam;
bool *currentBoolParam;

uint16_t minValue;
uint16_t maxValue;
uint16_t currentPos;
uint16_t nextPos;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Pin configuration
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
uint8_t pinFocus = 9;
uint8_t pinShutter = 8;

// Initialize the motor, display and menu
Adafruit_MotorShield  AFMS =        Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor =    AFMS.getStepper(200, 1);
Adafruit_RGBLCDShield lcd =         Adafruit_RGBLCDShield();
Menu::Engine *engine;

#include "./Nav.h"

void setup() {

  // Initialize output
  Serial.begin(9600);

  // Initialize pins
  pinMode(pinFocus, OUTPUT);
  pinMode(pinShutter, OUTPUT);

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.clear();

  engine = new Menu::Engine(&navWelcome);
  ShowWelcome(Menu::actionDisplay);

  systemState = State::Nav;

  // Start the motor
  AFMS.begin();  // create with the default frequency 1.6KHz
  myMotor->setSpeed(DEFAULT_REV_PER_MIN);

}

void loop() {
  ConfigController();
  NavController();
  StackController();
  DisplayController();
}


