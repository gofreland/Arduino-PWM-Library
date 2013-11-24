/*  
 *  PWM library for 8 bit Timer2 on ATmega168/328
 *  Gofreeland
 *  2013 Granada, Spain
 * 
 *  Example of pins 3 to 13 fade effect
 *  
 *  This is free software. You can redistribute it and/or modify it under
 *  the terms of Creative Commons Attribution 3.0 United States License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/us/ 
 *  or send a letter to Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
 *
 */

#include <PWM.h>
byte z;

void setup() {
}

void loop() {

  PWM pwm3(3);
  PWM pwm4(4);
  PWM pwm5(5);
  PWM pwm6(6);
  PWM pwm7(7);
  PWM pwm8(8);
  PWM pwm9(9);
  PWM pwm10(10);
  PWM pwm11(11);
  PWM pwm12(12);
  PWM pwm13(13);
  pwm3.begin();
  pwm4.begin();
  pwm5.begin();
  pwm6.begin();
  pwm7.begin();
  pwm8.begin();
  pwm9.begin();
  pwm10.begin();
  pwm11.begin();
  pwm12.begin();
  pwm13.begin();
  for (z=0; z<255;z++) {
    pwm3.write(3,z);
    pwm13.write(13,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm4.write(4,z);
    pwm3.write(3,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm5.write(5,z);
    pwm4.write(4,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm6.write(6,z);
    pwm5.write(5,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm7.write(7,z);
    pwm6.write(6,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm8.write(8,z);
    pwm7.write(7,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm9.write(9,z);
    pwm8.write(8,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm10.write(10,z);
    pwm9.write(9,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm11.write(11,z);
    pwm10.write(10,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm12.write(12,z);
    pwm11.write(11,254-z);
    delay(2);
  }
  for (z=0; z<255;z++) {
    pwm13.write(13,z);
    pwm12.write(12,254-z);
    delay(2);
  }
}
