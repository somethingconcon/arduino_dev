#ifndef Button_h
  #define Button_h 

  #include <pin.h>
  #include "Arduino.h"
  #include <StandardCplusplus.h>
  #include <serstream>
  #include <vector>

  using namespace std;

  namespace std
  {
    ohserialstream cout(Serial);
  }

  class Button {

    String identity = "Hello.";

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
    
    // Pins
    vector <Pin>controlledPins;

    // Init Button Input Session idle

    public:

      Button(); // assign in program
      Button(String identity); // assign name but not pins
      Button(String identity, Pin controlledPins[]); // assign name and pins
      
      int hold(); // during an evaluation cycle tell the instance that the button is still being held;
      int pressCount(); //return the number of times a button has been pressed
      int push(); 
      int pinState(int pinId); // Active or Other? for pin
      int pinState(String pinIdentity);
      int start(); // Start Time of Press
      int state(); // Button is Active or Other?
      int state(int _state_);
      
  //    boolean turnOn(int pin);
  //    boolean turnOn(String pinName);
      Pin getPin(String identituy);
      Pin getPin(int number);
     
    private:
    
      int setStart(int now);
      int setHoldStart(int now);
      void activate(); // start the button, yo!
       
  };

#endif
