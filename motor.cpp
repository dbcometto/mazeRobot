/**
 * Motor.cpp
 */

#include "Arduino.h"
#include "motor.h"

Motor::Motor(char pwmL_pin, char pwmR_pin, char EnL_pin, char EnR_pin, char PhL_pin, char PhR_pin) {

  PwmL = pwmL_pin;
  PwmR = pwmR_pin;
  EnL = EnL_pin;
  EnR = EnR_pin;
  PhL = PhL_pin;
  PhR = PhR_pin;  
  
  pinMode(PwmL, OUTPUT);
  pinMode(PwmR, OUTPUT);
  pinMode(EnL, OUTPUT);
  pinMode(EnR, OUTPUT);
  pinMode(PhL, OUTPUT);
  pinMode(PhR, OUTPUT);
}

void Motor::forward(unsigned int left_speed, unsigned int right_speed) {
  
  digitalWrite(EnL, HIGH);  // Forward/Backward & Coast 
  digitalWrite(EnR, HIGH);  // Forward/Backward & Coast 
  digitalWrite(PhL, LOW);   // Forward
  digitalWrite(PhR, LOW);   // Forward
  analogWrite(PwmL, left_speed);  
  analogWrite(PwmR, right_speed); 
}

void Motor::backward(unsigned int left_speed, unsigned int right_speed) {
  
  digitalWrite(EnL, HIGH);  // Forward/Backward & Coast 
  digitalWrite(EnR, HIGH);  // Forward/Backward & Coast 
  digitalWrite(PhL, HIGH);  // Reverse
  digitalWrite(PhR, HIGH);  // Reverse
  analogWrite(PwmL, left_speed);  
  analogWrite(PwmR, right_speed); 
}

void Motor::turn_left(unsigned int left_speed, unsigned int right_speed) {
  
  digitalWrite(EnL, HIGH);  // Forward/Backward & Coast 
  digitalWrite(EnR, HIGH);  // Forward/Backward & Coast 
  digitalWrite(PhL, HIGH);  // Reverse
  digitalWrite(PhR, LOW);   // Forward
  analogWrite(PwmL, left_speed);  
  analogWrite(PwmR, right_speed); 
}

void Motor::turn_right(unsigned int left_speed, unsigned int right_speed) {
  
  digitalWrite(EnL, HIGH);  // Forward/Backward & Coast 
  digitalWrite(EnR, HIGH);  // Forward/Backward & Coast 
  digitalWrite(PhL, LOW);   // Forward
  digitalWrite(PhR, HIGH);  // Backward
  analogWrite(PwmL, left_speed);  
  analogWrite(PwmR, right_speed); 
}



void Motor::coast(void) {
  
  analogWrite(PwmL, 0);  
  analogWrite(PwmR, 0); 
}

void Motor::brake(void) {
  
  digitalWrite(EnL, LOW);  // Forward/Backward & Coast 
  digitalWrite(EnR, LOW);  // Forward/Backward & Coast 
  analogWrite(PwmL, 255);  
  analogWrite(PwmR, 255); 
}

/* trivial destructor */
Motor::~Motor() {
}
