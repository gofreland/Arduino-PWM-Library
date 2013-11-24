/*
 *  PWM library for 8 bit Timer2 on ATmega168/328
 *  Gofreeland
 *  2013 Granada, Spain
 * 
 *  This is free software. You can redistribute it and/or modify it under
 *  the terms of Creative Commons Attribution 3.0 United States License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/us/ 
 *  or send a letter to Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
 *
 */

#include "Arduino.h"

#ifndef PWM_h
#define PWM_h

class PWM {

  public:
    
    PWM(byte pin);
    void begin();
    void write(byte pin, byte value);
    void (*isrCallback)();
  private:
    byte _pin;
    byte _value;
};  

#endif
