#include "Arduino.h"
#include <StandardCplusplus.h>
// #include <serstream>
#include <string>
#include <vector>

#include <pin.h>
#include <repository.h>
#include "button.h"

using namespace std;

Button::Button(string identity) {

}; // assign name but not pins

Button::Button(string identity, Pin controlledPins[]){

}; // assign name and pins

int Button::inputTimeWindow(){};
int Button::hold() {};
int Button::holdCount() {};
int Button::holdCycles() {};
long Button::holdTime() {};
int Button::pressCount() {};
int Button::push() {};
int Button::previousState() {};
void Button::previousStateSetter(int _state_) {};
void Button::reset() {};
void Button::reset(int _time_) {};
int Button::start() {};
int Button::start(int _time_) {};
int Button::state() {};
int Button::state(int _state_) {};
int Button::stop(int _time_) {};
int Button::timeSinceHoldStart() {};

Pin Button::getPin(string indetity) {
  Pin pin = repo.getPin(identity);
  return pin;
};

Pin Button::getPin(int number) {
  Pin pin = repo.getPin(number);
  return pin;
};

