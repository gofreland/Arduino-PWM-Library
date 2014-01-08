/*
 *  PWM4All 1.1
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
#include <avr/interrupt.h>
#include <avr/io.h>
#include "PWM4all.h"

    volatile byte pin_duty_cycle[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    volatile byte tick;
    volatile byte i;
 
PWM4all::PWM4all(void) {
}

PWM4all::~PWM4all(void) {
}

ISR(TIMER2_OVF_vect) {
  if (tick==0) {
      PORTB = B11111111;
      PORTD = B11111111;
      PORTC = B11111111;
  }
  for (i=0; i<8; i++) {
    if (tick>=pin_duty_cycle[i]) {
      PORTD = PORTD & ~(_BV(i));
    }
  }
  for (i=0; i<6; i++) {
    if (tick>=pin_duty_cycle[i+8]) {
      PORTB = PORTB & ~(_BV(i));
    }
  }
  for (i=0; i<6; i++) {
    if (tick>=pin_duty_cycle[i+14]) {
      PORTC = PORTC & ~(_BV(i));
    }
  }
  tick++;
  TCNT2 = 0xFF;
}

void PWM4all::pinout(byte pin) {
  byte bitshift= B00000001;
  if (pin<8) {
    bitshift = bitshift << pin;
    DDRD = DDRD | bitshift;
  }
  if ((pin>8) & (pin<14)) {
    bitshift = bitshift << (pin-8);
    DDRB = DDRB | bitshift;
  }
  if (pin>13) {
    bitshift = bitshift << (pin-14);
    DDRC = DDRC | bitshift;
  }
}

void PWM4all::begin() {
   // NORMAL MODE
  TCCR2A = (0<<COM2A1) | (0<<COM2A0) | (0<<COM2B1)| (0<<COM2B0) | (0<<3) | (0<<2) | (0<<WGM21) | (0<<WGM20);  

  TCCR2B = (0<<FOC2A) | (0<<FOC2B) | (0<<5) | (0<<4) | (0<<WGM22) | (0<<CS22) | (1<<CS21) | (1<<CS20); 
  
  // Timer2 Overflow Interrupt
  TIMSK2 =(0<<7) | (0<<6) | (0<<5) | (0<<4) | (0<<3) | (0<<OCIE2B) | (0<<OCIE2A) | (1<<TOIE2);  
  
  TIFR2 =(0<<7) | (0<<6) | (0<<5) | (0<<4) | (0<<3) | (0<<OCF2B) | (0<<OCF2A) | (0<<TOV2);  
}

void PWM4all::write(byte pin, byte value) {
  pin_duty_cycle[pin] = value;  
}
