/*
 * led3.c
 *
 *  Created on: 12-Jun-2019
 *      Author: 
 */
//LED toggle using push
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0b00000000;
	DDRB = 0b11111111;
	PORTB = 0b00000001;
	while(1)
	{	while(PORTB != 0b10000000)
		{
			if ( (PIND &(0b00000001)) == 0)

			{
				_delay_ms(200);
				PORTB = (PORTB<<1);
				_delay_ms(1000);
			}

		}

		if ( PORTB == 0b10000000)
		{
			while(PORTB != 0b00000001)
			{
						if ( (PIND &(0b00000001)) == 0)

						{
							_delay_ms(200);
							PORTB = (PORTB>>1);
							_delay_ms(1000);
						}

			}
		}
	}
}





