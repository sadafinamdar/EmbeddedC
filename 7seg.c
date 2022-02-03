/*
 * 7seg.c
 *
 *  Created on: 12-Jun-2019
 *      Author: 
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{	char array[] = {0x3F,0x30,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
	int i=0;
	int j=0;
	DDRD = 0b00000000;
	DDRB = 0b11111111;
	DDRA = 0b11111111;
	while(1)
	{	while(i!=10)

			{
				_delay_ms(1000);
				PORTB = array[i];
				{
					while(j!=10)
					{
						_delay_ms(1000);
						PORTA = array[j];
						_delay_ms(3000);
						j++;

					}
					j=0;
				}
				_delay_ms(3000);
				i++;
			}
	i=0;

	}
}

