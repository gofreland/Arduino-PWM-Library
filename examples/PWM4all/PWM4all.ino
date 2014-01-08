/*
 *  PWM4all 1.1
 *  A library to Pulse-Width Modulation on any ATmega168/328 pinout
 *  Gofreeland
 *  www.gofreeland.org
 *  2014 Granada, Spain
 * 
 *  Example of pins 0 to 19 fade effect
 *  
 *  This is free software. You can redistribute it and/or modify it under
 *  the terms of Creative Commons Attribution 3.0 United States License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/us/ 
 *  or send a letter to Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
 *
 */

#include <PWM4all.h>
byte pin,duty_cycle;

void setup() {
}

void loop() {
  PWM4all pwm;
  pwm.pinout(0);
  pwm.pinout(1);
  pwm.pinout(2);
  pwm.pinout(3);
  pwm.pinout(4);
  pwm.pinout(5);
  pwm.pinout(6);
  pwm.pinout(7);
  pwm.pinout(8);
  pwm.pinout(9);
  pwm.pinout(10);
  pwm.pinout(11);
  pwm.pinout(12);
  pwm.pinout(13);
  pwm.pinout(14);  //pin 14 to 19 are marked as analog input pins on Arduino 
  pwm.pinout(15); 
  pwm.pinout(16);
  pwm.pinout(17);
  pwm.pinout(18);
  pwm.pinout(19);
  pwm.begin();
  for (pin=0; pin<20; pin++) {
    for (duty_cycle=0; duty_cycle<255;duty_cycle++) {
      pwm.write(pin,duty_cycle);
      delay(5);
    }
  }
  for (pin=19; pin>=0; pin--) {
    for (duty_cycle=255; duty_cycle>0;duty_cycle--) {
      pwm.write(pin,duty_cycle);
      delay(5);
    }
  }
} 
