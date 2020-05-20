/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() 
{
	ADCSRA |= ( 1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned short val = ADC;
	unsigned short max = 255;
	ADC_init();
	val = ADC;
    /* Insert your solution below */
    while (1) {
	   val = ADC;
		if(val >= 32)
		{
			PORTB = 0x01;
		}
		if(val >= 64)
		{
			PORTB = 0x03;
		}
                if(val >= 96)
                {
                        PORTB = 0x07;
		}
                if(val >= 128)
                {
                        PORTB = 0x0F;
                }
                if(val >= 160)
                {
                        PORTB = 0x1F;
                }
                if(val >= 192)
                {
                        PORTB = 0x3F;
                }
                if(val >= 224)
                {
                        PORTB = 0x7F;
                }
                if(val >= 256)
                {
                        PORTB = 0xFF;
                }
		else
		{
			PORTB = 0x00;
		}



	//	PORTB = (char)val;
	//	PORTD = (char)(val >>  8);
    }
    return 1;
}
