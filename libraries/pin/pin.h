#ifndef Pin_h
#define Pin_h

#include <StandardCplusplus.h>
#include <string>

using namespace std;

class Pin {

  string identity = "Hello.";
  int _state_;

  // Button Vars
  int pinState = 0;  // variable for reading the pushbutton status;

  public:

    Pin(string identity, int number); // assign name and pins
    Pin(string identity, int number, int inputOutput);
    Pin(string identity, int number, int inputOutput, int _state_); // assign name and pins
    
    void set(int _state_);
    void set(boolean _state_);
    int state(); // Button is Active or Other?
    int state(int _state_);
    boolean turnOn(int pin);
    boolean turnOn(string pinName);
   
  private:
    void pinSetup(int number, int inputOutput);
     
};

#endif
