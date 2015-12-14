#ifndef Button_h
  #define Button_h 

  #include <pin.h>
  #include "Arduino.h"
  #include <StandardCplusplus.h>
  #include <string>
  // #include <serstream>
  #include <vector>

#include <repository.h>

  using namespace std;

  class Button {

    string identity;

    int inputTimeExtension;
  
    Repository repo;

    // Init Button Input Session idle

    public:

      Button(); // assign in program
      Button(string identity); // assign name but not pins
      Button(string identity, Pin controlledPins[]); // assign name and pins
      
      int hold(); // during an evaluation cycle tell the instance that the button is still being held;
      int holdCount();
      int holdCycles();
      long holdTime();
      int pressCount(); //return the number of times a button has been pressed
      int push(); 
      int pinState(int pinId); // Active or Other? for pin
      int pinState(string pinIdentity);
      int previousState();
      void previousStateSetter(int _state_);
      void reset();  // count return something useful...
      void reset(int time);  // count return something useful...
      int start(); // Start Time of Press
      int start(int time); // Start Time of Press also set the press count to 1
      int state(); // Button is Active or Other?
      int state(int _state_);
      int stop(int time);
      int timeSinceHoldStart();
    
      Pin getPin(string identituy);
      Pin getPin(int number);
     
      // should be session vars but I'm too lazy to write a session class yet.
      int inputTimeWindow();

    private:
    
      int setStart(int now);
      int setHoldStart(int now);
      void activate(); // start the button, yo!
      void restart();
       
  };

#endif
