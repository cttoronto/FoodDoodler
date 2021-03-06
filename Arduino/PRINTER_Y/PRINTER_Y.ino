/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

int pos = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(250);
  myMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
  
  delay(1000);
  myMotor->run(BACKWARD);
  // turn on motor
  delay(1000);
  myMotor->run(RELEASE);
}

void loop() {
  uint8_t i;
  
  Serial.print("tick");

  myMotor->run(FORWARD);
//  for (i=0; i<255; i++) {
//    myMotor->setSpeed(100); 
  pos += 1;

    delay(32);
    if (pos == 16) {
        myMotor->run(RELEASE);
        myMotor->run(BACKWARD);
        delay (1000);
        pos = 0;
    }

//  Serial.print("tech");
  myMotor->run(RELEASE);
  delay(1000);
}
