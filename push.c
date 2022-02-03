/*
 * push.c
 *
 *  Created on: 12-Jun-2019
 *      Author: 
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0b00000000;
	DDRB = 0b11111111;
	PORTB = 0b00000001;
	while(1)
	{
		if ( (PIND &(0b00000001)) == 0)
		{
			_delay_ms(200);
			PORTB = (PORTB<<1);
			_delay_ms(1000);
		}


	}
}
