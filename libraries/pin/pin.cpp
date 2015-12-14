#include "Arduino.h"
#include <StandardCplusplus.h>
#include <string>
#include "pin.h"

using namespace std;


// Pin::Pin(string indentity, int inputOutput) {
//   pinSetup(number, inputOutput);
// };
Pin::Pin(string identity, int number, int inputOutput) {
  identity = identity;
  pinSetup(number, inputOutput);
};

Pin::Pin(string indentity, int number, int inputOutput, int state) {
  identity = identity;
  pinSetup(number, inputOutput);
};

void Pin::set(int level){
  _state_ = level;
};

void Pin::set(boolean level){
  
  if(level == true) {
    _state_ = 1;
  } else {
    _state_ = 0;
  }

};

int Pin::state() {
  return _state_;
}

boolean Pin::turnOn(int pin) {
  digitalWrite(pin, HIGH);
};

void Pin::pinSetup(int number, int inputOutput) {
  pinMode(number, inputOutput);
};

// pinMode(modOutputPin, OUTPUT);
// // initialize the pushbutton pin as an input:
// pinMode(buttonPin, INPUT);

// pinMode(8, OUTPUT);

//  digitalWrite(modOutputPin, LOW);