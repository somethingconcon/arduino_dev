class Button {

  // Button Vars
  int buttonState         = 0;  // variable for reading the pushbutton status
  int buttonPressCount    = 0;
  int holdCount           = 0; // dupe?
  int holdCycles          = 0;
  int previousButtonState = 0;
  int inputTimeExtension  = 0;
  
  // Button Timers
  long holdStartTime      = 0;
  long holdTime           = 0;
  long resetStateStart    = 0;
  long timeSinceHoldStart = 0;

  
} button;
