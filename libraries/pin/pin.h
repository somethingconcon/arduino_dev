#ifndef Pin_h
#define Pin_h

#include "Arduino.h"

class Pin {

  String identity = "Hello.";

  // Button Vars
  int pinState = 0;  // variable for reading the pushbutton status;

  // Init Button Input Session idle

  public:

    Pin(); // assign in program
    Pin(String identity); // assign name but not pins
    Pin(String identity, int number); // assign name and pins
    
    int state(); // Button is Active or Other?
    int state(int _state_);
   
  private:
     
};

#endif
