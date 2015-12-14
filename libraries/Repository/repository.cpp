#include "Arduino.h"
#include <StandardCplusplus.h>
// #include <serstream>
#include <string>
#include <vector>
#include <pin.h>
#include "repository.h"

using namespace std;


Repository::Repository() {

}; // assign name but not pins

Repository::Repository(Pin controlledPins[]){

}; // assign name and pins

void Repository::add(Pin pin) {
  controlledPins.push_back(pin);
};

Pin Repository::getPin(string indetity) {
  Pin pin = find(indetity);
  return pin;
};

Pin Repository::getPin(int number) {
  Pin pin = find(number);
  return pin;
};

void Repository::remove(Pin pin) {
  // controlledPins.
};

Pin Repository::find(int number) {
  return controlledPins[0];
};

Pin Repository::find(string identity) {
  return controlledPins[0];
};
