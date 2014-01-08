/*
 *  PWM4all 1.1
 *  A library to Pulse-Width Modulation on any ATmega168/328 pinout
 *  Gofreeland
 *  www.gofreeland.org
 *  2014 Granada, Spain
 * 
 *  This is free software. You can redistribute it and/or modify it under
 *  the terms of Creative Commons Attribution 3.0 United States License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/us/ 
 *  or send a letter to Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
 *
 */

#include "Arduino.h"

#ifndef PWM4all_h
#define PWM4all_h

class PWM4all {

  public:
    
    PWM4all(void);
    ~PWM4all(void);
    void pinout(byte pin);
    void begin();
    void write(byte pin, byte value);
    void (*isrCallback)();
  private:
    byte _pin;
    byte _value;
};  

#endif
