/*
 * stepper.c
 *
 *  Created on: 25-Jun-2019
 *      Author: 
 */
#ifndef stepper
#define stepper
#include <avr/io.h>
#include <util/delay.h>

void stepper_func()
{
	DDRD = 0b11111111;
	while(1)
	{
	PORTD |= (1<<3)|(1<<0);
	_delay_ms(3000);
	PORTD &= ~(1<<0);
	_delay_ms(3000);
		PORTD |= (1<<3)|(1<<2);
		_delay_ms(3000);
			PORTD |= (1<<2);
			_delay_ms(3000);
				PORTD |= (1<<2)|(1<<1);
				_delay_ms(3000);
					PORTD = 0b00000010;
					_delay_ms(1000);
						PORTD = 0b00000011;
						_delay_ms(100);
						PORTD = 0b00000001;
						_delay_ms(100);
	}
}
#endif
