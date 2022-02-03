/*
 * USART.c
 *
 *  Created on: 04-Jul-2019
 *      Author: 
 */
#include<avr/io.h>
#include<util/delay.h>
#include<stdlib.h>
#include "lcd4bit.h"
#define F_CPU 8000000UL
#define BAUDRATE 9600
#define UBBR_val (((F_CPU)/(16*9600))-1)
char data;
void UARTinit()
{
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1<<URSEL)|(3<<UCSZ0);
	UBRRL = 0x67;
	UBRRH = 0x00;
}

char UART_RX()

{	DDRB = 0xff;
	while((UCSRA &(1<<RXC))==0);

	if(UDR == 'x')
		PORTB = 0xff;
	if(UDR == 'y')
		PORTB = 0x00;
	return(UDR);
}

void UART_TX(char data)
{

	while(!(UCSRA & (1<<UDRE)));
	UDR = data;


}

void UART_string(char *str)
{
	int j=0;

	while(str[j]!='\0')
	{
		UART_TX(str[j]);
		j++;
	}
}
int main()
{	lcd_init();
	UARTinit();
	lcd_string("USART initiated");
	//UART_string("E SPIN");
	while(1)
	{
		data = UART_RX();
		UART_TX(data);

	}

}




