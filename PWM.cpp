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
#include <avr/interrupt.h>
#include <avr/io.h>
#include "PWM.h"


    volatile byte pins[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    volatile byte tick;
    volatile byte mask;
    volatile byte lport;
    volatile byte hport;
    volatile byte i;
    volatile byte j;

PWM::PWM(byte pin)
{
  byte bitshift;
  //_pin = pin;
  bitshift= B00000001;
  if (pin<8) {
    bitshift= bitshift << pin;
    DDRD = DDRD | bitshift;
  }
  else {
    bitshift = bitshift << (pin-8);
    DDRB = DDRB | bitshift;
  }
}

ISR(TIMER2_OVF_vect) {
  if (tick==0) {
      hport = B11111111;
      lport = hport;
  }
  for (i=0; i<8; i++) {
      if (tick>=pins[i]) {
        j = mask << i;
        j = ~j;
        lport = lport & j;
      }
  }
  for (i=8; i<14; i++) {
      if (tick>=pins[i]) {
        j = mask << (i-8);
        j = ~j;
        hport = hport & j;
      }
  }
  PORTB = hport;
  PORTD = lport;  
  tick++;
  TCNT2 = 0xFE;
  TIFR2 = 0;
}


void PWM::begin() {
   // NORMAL MODE
  TCCR2A = (0<<COM2A1) | (0<<COM2A0) | (0<<COM2B1)| (0<<COM2B0) | (0<<3) | (0<<2) | (0<<WGM21) | (0<<WGM20);  

  TCCR2B = (0<<FOC2A) | (0<<FOC2B) | (0<<5) | (0<<4) | (0<<WGM22) | (0<<CS22) | (1<<CS21) | (1<<CS20); 
  
  // Activo Timer2 Overflow Interrupt
  TIMSK2 =(0<<7) | (0<<6) | (0<<5) | (0<<4) | (0<<3) | (0<<OCIE2B) | (0<<OCIE2A) | (1<<TOIE2);  
  
  TIFR2 =(0<<7) | (0<<6) | (0<<5) | (0<<4) | (0<<3) | (0<<OCF2B) | (0<<OCF2A) | (0<<TOV2);  
  
  // Oscilador interno
  ASSR = (0<<7) | (0<<EXCLK) | (0<<AS2) | (0<<TCN2UB) | (0<<OCR2AUB) | (0<<OCR2BUB) | (0<<TCR2AUB) | (0<<TCR2BUB) ;
  
  TCNT2 = 0xFE;
  
  OCR2A = 0xFF;
  OCR2B = 0xFF;
  
  tick = 0;
  mask = 1;
  lport = B11111111;
  hport = B11111111;
}

void PWM::write(byte pin, byte value) {
  pins[pin] = value;  
}
