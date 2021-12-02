
//----------------------//
//    Sullivan Dawson   //
//----------------------//


//-// Included Libraries //-//
#include <Stepper.h>
#include <IRremote.h>

//-=-// Global Vars //-=-//
const int dirPinTop = 4;
const int stepPinTop = 3;

const int dirPinMid = 7;
const int stepPinMid = 6;

const int dirPinBot = 12;
const int stepPinBot = 11;

const int reciever = 2;

//-// Stepepr Stuff //-//
const int stepsPerRevolution = 200;
Stepper myStepperTop = Stepper(stepsPerRevolution, dirPinTop, stepPinTop);
Stepper myStepperMid = Stepper(stepsPerRevolution, dirPinMid, stepPinMid);
Stepper myStepperBot = Stepper(stepsPerRevolution, dirPinBot, stepPinBot);
boolean finishedMovement;

//-// IR Stuff //-//
IRrecv irrecv(reciever);
decode_results results;
int inVal;

//-=-// Setup //-=-//
void setup() {
  Serial.begin(9600);
  Serial.println("Amogus");
  irrecv.enableIRIn();

  myStepperTop.setSpeed(200);
  myStepperMid.setSpeed(200);
  myStepperBot.setSpeed(200
                       );
  finishedMovement = true;
}

//-=-// Loop //-=-//
void loop() {

  moveStepper();
  //  myStepperTop.step(-500);
  //  delayMicroseconds(250);
  //  myStepperTop.step(500 );
  //  delayMicroseconds(250);

  //myStepperMid.step(1000);
  //delayMicroseconds(250);

  //myStepperBot.step(1000);
  //delayMicroseconds(250);

}

//-=-// Functions //-=-//

//-// Translate Func //-//

/*
   This Function translates the incoming code from the IR remote and attatches a corresponding
   value to the inVal that matches the button pressed on the remote. This allows for the user
   to select what state to initiate by selecting it on the remote.
*/

void translate() {
  if (results.value == 0xFF6897) {
    Serial.println("0");
    inVal = 0;
  }
  else if (results.value == 0xFF30CF) {
    Serial.println("1");
    inVal = 1;
  }
  else if (results.value == 0xFF18E7) {
    Serial.println("2");
    inVal = 2;
  }
  else if (results.value == 0xFF7A85) {
    Serial.println("3");
    inVal = 3;
  }
  else if (results.value == 0xFF10EF) {
    Serial.println("4");
    inVal = 4;
  }
  else if (results.value == 0xFF38C7) {
    Serial.println("5");
    inVal = 5;
  }
}

//-----------------------//

//-// Move Stepper Func //-//

/*
   This Function takes in the current inVal and moves the assigned steppers to where they are
   assigned to go. This allows for the simple addition of new states if desired.
*/

void moveStepper() {
  if (finishedMovement == true) {

    if (irrecv.decode(&results)) {
      translate();
      //Serial.println(results.value, HEX);
      irrecv.resume();
    }

    if (inVal == 0) {
      Serial.println("No Change");
    }

    if (inVal == 1) { //Up to flat wall
      finishedMovement = false;
      myStepperTop.step(200);
      delay(25);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-100);
      delay(1000);
      finishedMovement = true;
      inVal = 0;
    }

    if (inVal == 2) { //Reverse from 1
      finishedMovement = false;
      myStepperTop.step(100);
      delay(100);
      myStepperTop.step(50);
      delay(25);
      myStepperTop.step(-185);
      delay(1000);
      finishedMovement = true;
      inVal = 0;
    }

    if (inVal == 3) { //Up to 45deg slant or Ramp
      finishedMovement = false;
      myStepperTop.step(300);
      delay(25);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-100);
      delay(1000);
      finishedMovement = true;
      inVal = 0;
    }

    if (inVal == 4) { //Reverse from 3
      finishedMovement = false;
      myStepperTop.step(100);
      delay(25);
      myStepperTop.step(50);
      delay(100);
      myStepperTop.step(-275);
      delay(1000);
      finishedMovement = true;
      inVal = 0;
    }

    if (inVal == 5) { //PortalMode!
      finishedMovement = false;
      myStepperTop.step(100);
      delay(25);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(275);
      delay(2000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-25);
      delay(1000);
      myStepperTop.step(-10);
      delay(100);
      myStepperTop.step(100);
      delay(1000);
      myStepperTop.step(-50);
      delay(1000);
      myStepperTop.step(-25);
      delay(1000);
      myStepperTop.step(-12);
      delay(1000);
      myStepperTop.step(-6);
      delay(1000);
      myStepperTop.step(-3);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-6);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-10);
      delay(100);
      myStepperTop.step(100);
      delay(1000);
      myStepperTop.step(-100);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(100);
      delay(25);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(275);
      delay(2000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-25);
      delay(1000);
      myStepperTop.step(-10);
      delay(100);
      myStepperTop.step(100);
      delay(1000);
      myStepperTop.step(-50);
      delay(1000);
      myStepperTop.step(-25);
      delay(1000);
      myStepperTop.step(-12);
      delay(1000);
      myStepperTop.step(-6);
      delay(1000);
      myStepperTop.step(-3);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-6);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-10);
      delay(100);
      myStepperTop.step(100);
      delay(1000);
      myStepperTop.step(-100);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(100);
      delay(25);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(275);
      delay(2000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-25);
      delay(1000);
      myStepperTop.step(-10);
      delay(100);
      myStepperTop.step(100);
      delay(1000);
      myStepperTop.step(-50);
      delay(1000);
      myStepperTop.step(-25);
      delay(1000);
      myStepperTop.step(-12);
      delay(1000);
      myStepperTop.step(-6);
      delay(1000);
      myStepperTop.step(-3);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-6);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-10);
      delay(100);
      myStepperTop.step(100);
      delay(1000);
      myStepperTop.step(-100);
      delay(1000);
      myStepperTop.step(-50);
      delay(100);
      myStepperTop.step(-50);
      delay(100);
      finishedMovement = true;
      inVal = 0;
    }
  }
}
