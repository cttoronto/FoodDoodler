// ConstantSpeed.pde
// -*- mode: C++ -*-
//
// Shows how to run AccelStepper in the simplest,
// fixed speed mode with no accelerations
// Requires the AFMotor library (https://github.com/adafruit/Adafruit-Motor-Shield-library)
// And AccelStepper with AFMotor support (https://github.com/adafruit/AccelStepper)
// Public domain!

#include <AccelStepper.h>
#include <AFMotor.h>

AF_Stepper motor1(200, 1);


// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
void forwardstep() {  
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep() {  
  motor1.onestep(BACKWARD, SINGLE);
}

AccelStepper stepper(forwardstep, backwardstep); // use functions to step
int i = 0;

void setup()
{  
   Serial.begin(9600);           // set up Serial library at 9600 bps
   Serial.println("Stepper test!");
  
   stepper.setSpeed(50);	
}

void loop()
{  
   i++;
  
  Serial.println(i);
  if (i == 1) {
    stepper.setSpeed(-150);	

  }  else if (i == 1000) {
    stepper.setSpeed(150);	

  }  else if (i > 2000) {
     i = 0;
  }
  
  stepper.runSpeed();
//  delay(10);
}
