#include <button.h>
#include <pin.h>

const int inputTimeInitWindow = 150;

long holdTime           = 0;
// long resetStateStart    = 0;
  long timeSinceHoldStart = 0;
  Button mainButton = Button("main");

bool pressSession = false;  // I dont really need this if im tracking start time but meeeeh, i like booleans a lot.

// Cycle Vars
long cycles             = 0;
long currentStateCycles = 0;
long startTime          = 0;

// Vaping Vars
float ohms  = 0;
float volts = 0;
int watts   = 0; // in the future I want to read from persistant state
// hold total time in hours
// battery hours

// can i use a hash for juice stats?
int juiceRating   = 0;
int juiceNicLevel = 0;
String juiceName  = "No Juice";


// BUTTON CLASS CODE HERE
// Button interfaceButton = new Button("main", Pin(2, "read"), []); // name, Input Pin, Output Pins

void setup() {
  
  serialSetup();
  
  pinSetup();
  
  runStartupBehavior();

  promptNewSession(); // or skip to NEW NEW NEW NEW NEW session  so people can input later

}

void loop() {

  // since my only input right now is through this button let's do some wacky shit
  
  // read the state of the pushbutton value:
  // interfaceButton.state(digitalRead(buttonPin));
  // buttonState = digitalRead(buttonPin);
  cycles++;
  
  if (mainButton.state() == HIGH && mainButton.state() == mainButton.previousState()) {
    
    // turn on the mod if we've on encountered 1 press
    // we wait 1 cycle for state change to check if the button is still being pressed
    // might want to wait until the input session expires before triggering these actions
    if (mainButton.pressCount() == 2 && mainButton.holdTime() >= 250) {
      // define some behavior for 2 clicks
    } else if (mainButton.pressCount() == 1 && mainButton.holdTime() >= 250) {
      
      // modAdapterObject for controller mod + collecting data
      // digitalWrite(modOutputPin, HIGH);
      mainButton.start();
      mainButton.getPin("atomizer").set(HIGH);
      //PinRepository.get("atomizer")
    }
    
    mainButton.hold();
    
  } else if (mainButton.state() == LOW && mainButton.state() == mainButton.previousState()) {
 
    // an object at reset will stay at rest until I'm tryina vape dat
    // sleeeeeep screen ;)

    // turn off the mod if the mod is turned on
    mainButton.getPin("atomizer").set(LOW);
    
    if (mainButton.timeSinceHoldStart() >= mainButton.inputTimeWindow() && mainButton.start() != 0) {
      Serial.println("session expired");
    }
    
  } else {
    
    // reset vars or do things
    if (mainButton.state() == LOW && mainButton.previousState() == HIGH) {
      //set vape data && reset

      if (mainButton.pressCount() == 1) {
        Serial.print("held the button for:");
        Serial.print(holdTime);
        Serial.print(" milliseconds\n\n\n");
        clouds();
      }
      
      mainButton.stop(millis());  // not using but would be helpful in debouncing

    } else if(mainButton.state() == HIGH && mainButton.previousState() == LOW) {

      mainButton.start(millis());
      
      triggerPressBehavior();
      
    } else {
      // carry on;
    }
  }
  
  if (mainButton.previousState() != mainButton.state()) {
    mainButton.previousStateSetter(mainButton.state());
  }
}

void triggerPressBehavior () {
  if(mainButton.pressCount() == 2) {
    delay(250);
    Serial.println("2 press");
  } else if(mainButton.pressCount() == 1) {
    mainButton.start(millis());
  } else {
     Serial.println(mainButton.pressCount());
  }
}

// INIT
int fadeIn(int currentLevel, int level) {
  
  int newLevel = level + currentLevel;
  
  delay(50);

  // analogWrite(modOutputPin, newLevel);

  return newLevel;
}

void pinSetup() {

    // set pin numbers:
  int buttonPin = 2;     // the number of the pushbutton pin
  int modOutputPin = 11;   // the number of the MOD pin
  int statusLedPin = 8;

  Pin atomizer = Pin("atomizer", modOutputPin, OUTPUT, LOW);
  Pin button   = Pin("main", buttonPin, INPUT);

}

void promptNewSession() {
   Serial.println("What's that juice my dood.");
   Serial.println("How do you like it.");
   Serial.println("What is the nic level of that juice.");
}

bool runStartupBehavior() {
  
  bool startupComplete = false;
  long fadeLevel       = 0;
  
  Serial.println("Startup");
  
  while(startupComplete != true) {
    fadeLevel = fadeIn(fadeLevel, 5);

    if(fadeLevel >= 255 && true) {
      
      startupComplete == true;
      
      // digitalWrite(modOutputPin, LOW);
      Serial.println("Startup Complete.");
      break;
    }
  }

  startTime = millis();
  return true;
}

void serialSetup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // send an intro:
  Serial.println("\n\nLet's vape some juices!");
  Serial.println();

}

// Print Screens
void clouds() {
  
  Serial.println("        _ __");
  Serial.println("    (-       -  )__- -_");
  Serial.println("   (  -=  - )   -     _)");
  Serial.println("  (_-= _(    =-    _=-");
  Serial.println("   -(     -    -  _)");
  Serial.println("     -=__(__  _-)-");
  Serial.println("           -=-\n\n\n");

}
