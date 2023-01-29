/**
 * Arduino Due 
 */

#include "motor.h"
 
#define LED   13
#define PWMR  2
#define PWML  3
#define ENR   4 
#define ENL   5
#define PHR   6
#define PHL   7


Motor motor = Motor(PWML, PWMR, ENL, ENR, PHL, PHR);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

}


void loop() {

  
  motor.forward(255/4, 255/4); // 25%
  delay(3000);
  motor.coast();
  delay(1000);
    
  motor.backward(255/4, 255/4); // 25%
  delay(3000);
  motor.coast();
  delay(1000);

  motor.turn_left(255/4, 255/4); // 25%
  delay(3000);
  motor.coast();
  delay(1000);
  
  motor.turn_right(255/4, 255/4); // 25%
  delay(3000);
  motor.brake();
  delay(1000);

  
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  delay(1000);  // wait for a second
  digitalWrite(LED, LOW);
  delay(1000);  // wait for a second
  
}
