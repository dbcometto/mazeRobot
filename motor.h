/**
 * Motor.cpp
 */

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"


class Motor {
  public:
    Motor(char pwmL_pin, char pwmR_pin, char EnL_pin, char EnR_pin, char PhL_pin, char PhR_pin);
    ~Motor(void);
    void forward(unsigned int left_speed, unsigned int right_speed);
    void backward(unsigned int left_speed, unsigned int right_speed);
    void turn_left(unsigned int left_speed, unsigned int right_speed);
    void turn_right(unsigned int left_speed, unsigned int right_speed);
    void coast(void);
    void brake(void);    
  private:
    char PwmL, PwmR, EnL, EnR, PhL, PhR;  
};

#endif
