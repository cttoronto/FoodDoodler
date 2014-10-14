// MultiStepper
// -*- mode: C++ -*-
//
// Control both Stepper motors at the same time with different speeds
// and accelerations. 
// Requires the AFMotor library (https://github.com/adafruit/Adafruit-Motor-Shield-library)
// And AccelStepper with AFMotor support (https://github.com/adafruit/AccelStepper)
// Public domain!

#include <AccelStepper.h>
#include <AFMotor.h>

// two stepper motors one on each port
AF_Stepper motor1(50, 0);
AF_Stepper motor2(50, 1);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {  
  motor2.onestep(FORWARD, SINGLE);
}
void backwardstep2() {  
  motor2.onestep(BACKWARD, SINGLE);
}
int i;
// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

void setup()
{  
    stepper1.setMaxSpeed(150.0);
    stepper1.setAcceleration(100.0);
    stepper1.moveTo(24);
    
    stepper2.setMaxSpeed(150.0);
    stepper2.setAcceleration(100.0);
    stepper2.moveTo(24);
    
//    stepper2.setMaxSpeed(150.0);
//    stepper2.setAcceleration(100.0);
//    stepper2.moveTo(1000000);
    i = 0;
}



void loop()
{
  
  i ++;
  
    // Change direction at the limits
//    if (stepper1.distanceToGo() == 0)
//	stepper1.moveTo();
//    if (i %2 == 0) stepper1.move(1);
//    if (i %2 == 1) stepper1.move(-1);
    stepper1.run();
    stepper2.run();
    delay(1000);
    //stepper2.run();
}
