/*
 * pwm.c
 *
 *  Created on: 26-Jun-2019
 *      Author:
 */

#include <avr/io.h>
#include <util/delay.h>

void pwm_init()
{
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
		DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}

int main(void)
{
	unsigned char duty;
	pwm_init();
	DDRB |=(1<<0)|(1<<7);

	while(1)
	{		PORTB = 0b10000000;
		for(duty = 255; duty>0; duty--)
	{
		OCR0 = duty;
		_delay_ms(50);
	}

		PORTB = 0b00000001;
		for(duty = 0; duty<255; duty++)
		{
			OCR0 = duty;
			_delay_ms(50);
		}
		PORTB = 0b00000010;

	}
}
