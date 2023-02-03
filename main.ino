/**
 *  Maze Robot Main File for Arduino Due
 */

#include "motor.h"

// Motor Control Pins
#define PWMR  2 // Motor Sleep
#define PWML  9
#define ENR   4 // Motor Enable
#define ENL   5
#define PHR   6 // Motor Direction
#define PHL   7

// Bump Sensors
#define BMPS0 42 // All the way Right
#define BMPS1 44
#define BMPS2 46
#define BMPS3 48
#define BMPS4 50
#define BMPS5 52 // All the way Left

// Distance Sensors
#define DISTR A0
#define DISTC A1
#define DISTL A2

// Motor Setup
Motor motor = Motor(PWML, PWMR, ENL, ENR, PHL, PHR);


void setup() {

  // Bump Sensors
  pinMode(BMPS0, INPUT);
  pinMode(BMPS1, INPUT);
  pinMode(BMPS2, INPUT);
  pinMode(BMPS3, INPUT);
  pinMode(BMPS4, INPUT);
  pinMode(BMPS5, INPUT);

}

void loop() {

  
  motor.forward(255/4, 255/4); // 10%
  delay(3000);
  motor.coast();
  delay(4000);

  motor.backward(255/4, 255/4); // 10%
  delay(3000);
  motor.coast();
  delay(4000);

  motor.turn_left(255/4, 255/4); // 10%
  delay(3000);
  motor.coast();
  delay(4000);

  motor.turn_right(255/4, 255/4); // 10%
  delay(3000);
  motor.coast();
  delay(4000);

  motor.brake();
  
}
