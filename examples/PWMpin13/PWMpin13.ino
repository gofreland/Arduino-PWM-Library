/*
 *  PWM4all 1.1
 *  A library to Pulse-Width Modulation on any ATmega168/328 pinout
 *  Gofreeland
 *  www.gofreeland.org
 *  2014 Granada, Spain
 * 
 *  PWM at pin 13 (you can change from 0 to 19 pin);
 *
 *  This is free software. You can redistribute it and/or modify it under
 *  the terms of Creative Commons Attribution 3.0 United States License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/us/ 
 *  or send a letter to Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
 *
 */

#include <PWM4all.h>

void setup() {
  PWM4all pwm;
  pwm.pinout(13);
  pwm.begin();
  pwm.write(13,10);
}

void loop() {
}
