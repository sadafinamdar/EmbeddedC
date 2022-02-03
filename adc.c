/*
 * adc.c
 *
 *  Created on: 21-Jun-2019
 *      Author: 
 */

#include <avr/io.h>

	int main(void)
	{
		DDRB = 0xff;
		DDRD = 0xff;
		DDRA = 0x00;
		ADCSRA = 0x87;
		ADMUX = 0xc0;

		while(1)
		{
			ADCSRA |= (1<<ADSC);
			while( (ADCSRA &(0b00010000))== 0)
			{
				PORTD = ADCL;
				PORTB = ADCH;

			}




		}
	}
