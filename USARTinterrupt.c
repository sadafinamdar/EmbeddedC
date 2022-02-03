/*
 * USARTinterrupt.c
 *
 *  Created on: 06-Jul-2019
 *      Author: 
 */

#include<avr/io.h>
#include<util/delay.h>
#include<stdlib.h>
#include<avr/interrupt.h>
#include "lcd4bit.h"
#define F_CPU 8000000UL
#define BAUDRATE 9600
#define UBBR_val (((F_CPU)/(16*9600))-1)
char data;
void USARTinit()
{
	UCSRB |= (1<<RXEN)|(1<<RXCIE)|(1<<TXEN);

	UCSRC |= (1<<URSEL)|(3<<UCSZ0);
	UBRRL = 0x67;
	UBRRH = 0x00;
}
ISR(USART_RXC_vect)
{
	unsigned char value;
	value = UDR;
	UDR = value;
	while(!(UCSRA & (1<<RXC)));
	if(UDR == 'x')
			PORTB = 0xff;
		if(UDR == 'y')
			PORTB = 0x00;
}

int main()
{
	USARTinit();	// initialization of USART
	DDRB = 0xff;
	sei();		// Enable global interrupt
	for (;;)		// infinite loop
	{
		// Do Nothing
	}
}

