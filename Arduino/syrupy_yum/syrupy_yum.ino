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
AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
  motor1.onestep(FORWARD, DOUBLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, DOUBLE);
}
// wrappers for the second motor!
void forwardstep2() {  
  motor2.onestep(FORWARD, DOUBLE);
}
void backwardstep2() {  
  motor2.onestep(BACKWARD, DOUBLE);
}

// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

void setup()
{  
    stepper1.setMaxSpeed(150.0);
    stepper1.setAcceleration(150.0);
    stepper1.moveTo(100000);
    
    stepper2.setMaxSpeed(150.0);
    stepper2.setAcceleration(150.0);
    stepper2.moveTo(100000);
    
}

void loop()
{
    // Change direction at the limits
//    if (stepper1.distanceToGo() == 0)
//	stepper1.moveTo(stepper1.currentPosition() + 1500);

//    if (stepper2.distanceToGo() == 0)
//	stepper2.moveTo(stepper2.currentPosition() + 1500);

    stepper1.run();
    stepper2.run();
    
//    delay(1000);
    
}
