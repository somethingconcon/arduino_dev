// constants won't change. They're used here to

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int modOutput = 11;   // the number of the MOD pin

const int inputTimeInitWindow = 250;

// const Object modClient = new ModClient();

// variables will change:
// Button Vars
int buttonState         = 0;         // variable for reading the pushbutton status
int buttonPressCount    = 0;
int holdCount           = 0;
int holdCycles          = 0;
int previousButtonState = 0;
int inputTimeExtension  = 0;

// Button Timers
long holdStartTime      = 0;
long holdTime           = 0;
long resetStateStart    = 0;
long timeSinceHoldStart = 0;

bool pressSession = false;  // I dont really need this if im tracking start time but meeeeh, i like booleans a lot.

// Cycle Vars
long cycles             = 0;
long currentStateCycles = 0;
long startTime          = 0;

// Vaping Vars
float ohms  = 0;
float volts = 0;
int watts   = 0; // in the future I want to read from persistant state

// can i use a hash for juice stats?
int juiceRating   = 0;
int juiceNicLevel = 0;
String juiceName  = "No Juice";

void setup() {
  
  serialSetup();
  pinSetup();
  runStartupBehavior();

  promptNewSession(); // or skip to NEW NEW NEW NEW NEW session so people can input later
}

void loop() {

  // since my only input right now is through this button let's do some wacky shit
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  timeSinceHoldStart = millis() - holdStartTime;
  
  if (buttonState == HIGH && buttonState == previousButtonState) {
    
    holdTime = millis() - holdStartTime;
    
    // turn on the mod if we've on encountered 1 press
    // we wait 1 cycle for state change to check if the button is still being pressed
    // might want to wait until the input session expires before triggering these actions
    if (buttonPressCount == 2 && holdTime >= 250) {
    
    } else if (buttonPressCount == 1 && holdTime >= 250) {
      // modAdapterObject for controller mod + collecting data
      digitalWrite(modOutput, HIGH);
    }
    
    holdCycles++;
    
  } else if (buttonState == LOW && buttonState == previousButtonState) {
 
    // and object at reset will stay at rest until I'm try to vape dat
    // sleeeeeep screen ;)

    // turn off the mod
    digitalWrite(modOutput, LOW);
    
    delay(150);
    Serial.println("I'm sleepy");
    
    if (timeSinceHoldStart >= inputTimeInitWindow && holdStartTime != 0) {
      
      resetHoldData();
      
      Serial.println("session expired");
    }
    
  } else {
    
    // reset vars or do things
    if (buttonState == LOW && previousButtonState == HIGH) {
      //set vape data && reset

      if (buttonPressCount == 1) {
        Serial.print("held the button for:");
        Serial.print(holdTime);
        Serial.print(" milliseconds\n\n\n");
        clouds();
      }
      
      resetStateStart = millis();  // not using but would be helpful in debouncing

    } else if(buttonState == HIGH && previousButtonState == LOW) {

      holdCycles = 1;
      buttonPressCount++;
      
      triggerPressBehavior();
      
    } else {
      // carry on;
    }
  }
  
  if (previousButtonState != buttonState) {
    previousButtonState = buttonState;
  }
}

// Mod Control
void modControl() {}
void triggerPressBehavior () {
  if(buttonPressCount == 2) {
    delay(250);
    Serial.println("2 press");
  } else if(buttonPressCount == 1) {
    holdStartTime = millis();
  } else {
     Serial.println(buttonPressCount);
  }
}

// Vape Data
void resetHoldData() {    
  buttonPressCount = 0;
  timeSinceHoldStart = 0;
  holdStartTime = 0;
}


// INIT
int fadeIn(int currentLevel, int level) {
  
  int newLevel = level + currentLevel;
  
  delay(50);

  analogWrite(modOutput, newLevel);

  return newLevel;
}

void pinSetup() {
  
  // initialize the MOD pin as an output:
  pinMode(modOutput, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
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
      
      digitalWrite(modOutput, LOW);
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
