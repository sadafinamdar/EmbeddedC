/*
 * 7seg1.c
 *
 *  Created on: 13-Jun-2019
 *      Author: 
 */
#include <avr/io.h>

#define F_CPU	16000000UL
#include <util/delay.h>

int main(void)
{
	DDRB= 0xFF;	// Configure port B as output
    DDRA= 0xFF;
    while(1)
    {
        //TODO:: Please write your application code

    	_delay_ms(2000);
    	PORTB = 0b00110000;
    				        _delay_ms(1000);		// Wait for 1s
    						PORTB = 0b01011011;		// Display Number 2
    						_delay_ms(1000);		// Wait for 1s
    						PORTB = 0b01001111;		// Display Number 3
    						_delay_ms(1000);		// Wait for 1s
    						PORTB = 0b01100110;		// Display Number 4
    						_delay_ms(1000);		// Wait for 1s

    						PORTB = 0b01101101;
    						_delay_ms(1000);
    						PORTB = 0b01111101;		// Display Letter C
    						_delay_ms(1000);		// Wait for 1s
    						PORTB= 0b00000111;		// Display Letter E
    						_delay_ms(1000);		// Wait for 1s
    						PORTB = 0b01111111;		// Display Letter F
    						_delay_ms(1000);
    						PORTB = 0b01100111;		// Display Letter F
    						_delay_ms(1000);      // Wait for 1s

		PORTB = 0b00110000;
		while(PORTB == 0b00110000)
		{

			        PORTA = 0b00110000;
			        _delay_ms(1000);		// Wait for 1s
					PORTA = 0b01011011;		// Display Number 2
					_delay_ms(1000);		// Wait for 1s
					PORTA = 0b01001111;		// Display Number 3
					_delay_ms(1000);		// Wait for 1s
					PORTA = 0b01100110;		// Display Number 4
					_delay_ms(1000);		// Wait for 1s

					PORTA = 0b01101101;
					_delay_ms(1000);
					PORTA = 0b01111101;		// Display Letter C
					_delay_ms(1000);		// Wait for 1s
					PORTA = 0b00000111;		// Display Letter E
					_delay_ms(1000);		// Wait for 1s
					PORTA = 0b01111111;		// Display Letter F
					_delay_ms(1000);
					PORTA = 0b01100111;		// Display Letter F
					_delay_ms(1000);      // Wait for 1s

					break;

		}

		PORTB = 0b01011011 ;
				while(PORTB == 0b01011011 )
				{

					        PORTA = 0b00110000;
					        _delay_ms(1000);		// Wait for 1s
							PORTA = 0b01011011;		// Display Number 2
							_delay_ms(1000);		// Wait for 1s
							PORTA = 0b01001111;		// Display Number 3
							_delay_ms(1000);		// Wait for 1s
							PORTA = 0b01100110;		// Display Number 4
							_delay_ms(1000);		// Wait for 1s

							PORTA = 0b01101101;
							_delay_ms(1000);
							PORTA = 0b01111101;		// Display Letter C
							_delay_ms(1000);		// Wait for 1s
							PORTA = 0b00000111;		// Display Letter E
							_delay_ms(1000);		// Wait for 1s
							PORTA = 0b01111111;		// Display Letter F
							_delay_ms(1000);
							PORTA = 0b01100111;		// Display Letter F
							_delay_ms(1000);      // Wait for 1s

							break;

				}

				PORTB = 0b01001111  ;
						while(PORTB == 0b01001111)
						{

							        PORTA = 0b00110000;
							        _delay_ms(1000);		// Wait for 1s
									PORTA = 0b01011011;		// Display Number 2
									_delay_ms(1000);		// Wait for 1s
									PORTA = 0b01001111;		// Display Number 3
									_delay_ms(1000);		// Wait for 1s
									PORTA = 0b01100110;		// Display Number 4
									_delay_ms(1000);		// Wait for 1s

									PORTA = 0b01101101;
									_delay_ms(1000);
									PORTA = 0b01111101;		// Display Letter C
									_delay_ms(1000);		// Wait for 1s
									PORTA = 0b00000111;		// Display Letter E
									_delay_ms(1000);		// Wait for 1s
									PORTA = 0b01111111;		// Display Letter F
									_delay_ms(1000);
									PORTA = 0b01100111;		// Display Letter F
									_delay_ms(1000);      // Wait for 1s

									break;

						}

						PORTB = 0b01100110  ;
												while(PORTB == 0b01100110)
												{

													        PORTA = 0b00110000;
													        _delay_ms(1000);		// Wait for 1s
															PORTA = 0b01011011;		// Display Number 2
															_delay_ms(1000);		// Wait for 1s
															PORTA = 0b01001111;		// Display Number 3
															_delay_ms(1000);		// Wait for 1s
															PORTA = 0b01100110;		// Display Number 4
															_delay_ms(1000);		// Wait for 1s

															PORTA = 0b01101101;
															_delay_ms(1000);
															PORTA = 0b01111101;		// Display Letter C
															_delay_ms(1000);		// Wait for 1s
															PORTA = 0b00000111;		// Display Letter E
															_delay_ms(1000);		// Wait for 1s
															PORTA = 0b01111111;		// Display Letter F
															_delay_ms(1000);
															PORTA = 0b01100111;		// Display Letter F
															_delay_ms(1000);      // Wait for 1s

															break;

												}


												PORTB = 0b01101101  ;
																		while(PORTB == 0b01101101)
																		{

																			        PORTA = 0b00110000;
																			        _delay_ms(1000);		// Wait for 1s
																					PORTA = 0b01011011;		// Display Number 2
																					_delay_ms(1000);		// Wait for 1s
																					PORTA = 0b01001111;		// Display Number 3
																					_delay_ms(1000);		// Wait for 1s
																					PORTA = 0b01100110;		// Display Number 4
																					_delay_ms(1000);		// Wait for 1s

																					PORTA = 0b01101101;
																					_delay_ms(1000);
																					PORTA = 0b01111101;		// Display Letter C
																					_delay_ms(1000);		// Wait for 1s
																					PORTA = 0b00000111;		// Display Letter E
																					_delay_ms(1000);		// Wait for 1s
																					PORTA = 0b01111111;		// Display Letter F
																					_delay_ms(1000);
																					PORTA = 0b01100111;		// Display Letter F
																					_delay_ms(1000);      // Wait for 1s

																					break;

																		}
																		PORTB = 0b01111101  ;
																																				while(PORTB == 0b01111101)
																																				{

																																					        PORTA = 0b00110000;
																																					        _delay_ms(1000);		// Wait for 1s
																																							PORTA = 0b01011011;		// Display Number 2
																																							_delay_ms(1000);		// Wait for 1s
																																							PORTA = 0b01001111;		// Display Number 3
																																							_delay_ms(1000);		// Wait for 1s
																																							PORTA = 0b01100110;		// Display Number 4
																																							_delay_ms(1000);		// Wait for 1s

																																							PORTA = 0b01101101;
																																							_delay_ms(1000);
																																							PORTA = 0b01111101;		// Display Letter C
																																							_delay_ms(1000);		// Wait for 1s
																																							PORTA = 0b00000111;		// Display Letter E
																																							_delay_ms(1000);		// Wait for 1s
																																							PORTA = 0b01111111;		// Display Letter F
																																							_delay_ms(1000);
																																							PORTA = 0b01100111;		// Display Letter F
																																							_delay_ms(1000);      // Wait for 1s

																																							break;

																																				}
																																				PORTB = 0b00000111 ;
																																																																								while(PORTB == 0b00000111)
																																																																								{

																																																																									        PORTA = 0b00110000;
																																																																									        _delay_ms(1000);		// Wait for 1s
																																																																											PORTA = 0b01011011;		// Display Number 2
																																																																											_delay_ms(1000);		// Wait for 1s
																																																																											PORTA = 0b01001111;		// Display Number 3
																																																																											_delay_ms(1000);		// Wait for 1s
																																																																											PORTA = 0b01100110;		// Display Number 4
																																																																											_delay_ms(1000);		// Wait for 1s

																																																																											PORTA = 0b01101101;
																																																																											_delay_ms(1000);
																																																																											PORTA = 0b01111101;		// Display Letter C
																																																																											_delay_ms(1000);		// Wait for 1s
																																																																											PORTA = 0b00000111;		// Display Letter E
																																																																											_delay_ms(1000);		// Wait for 1s
																																																																											PORTA = 0b01111111;		// Display Letter F
																																																																											_delay_ms(1000);
																																																																											PORTA = 0b01100111;		// Display Letter F
																																																																											_delay_ms(1000);      // Wait for 1s

																																																																											break;

																																																																								}
																																																																								PORTB = 0b01111111;
																																																																																																																																															while(PORTB == 0b01111111)
																																																																																																																																															{

																																																																																																																																																        PORTA = 0b00110000;
																																																																																																																																																        _delay_ms(1000);		// Wait for 1s
																																																																																																																																																		PORTA = 0b01011011;		// Display Number 2
																																																																																																																																																		_delay_ms(1000);		// Wait for 1s
																																																																																																																																																		PORTA = 0b01001111;		// Display Number 3
																																																																																																																																																		_delay_ms(1000);		// Wait for 1s
																																																																																																																																																		PORTA = 0b01100110;		// Display Number 4
																																																																																																																																																		_delay_ms(1000);		// Wait for 1s

																																																																																																																																																		PORTA = 0b01101101;
																																																																																																																																																		_delay_ms(1000);
																																																																																																																																																		PORTA = 0b01111101;		// Display Letter C
																																																																																																																																																		_delay_ms(1000);		// Wait for 1s
																																																																																																																																																		PORTA = 0b00000111;		// Display Letter E
																																																																																																																																																		_delay_ms(1000);		// Wait for 1s
																																																																																																																																																		PORTA = 0b01111111;		// Display Letter F
																																																																																																																																																		_delay_ms(1000);
																																																																																																																																																		PORTA = 0b01100111;		// Display Letter F
																																																																																																																																																		_delay_ms(1000);      // Wait for 1s

																																																																																																																																																		break;
																																																																																																																																															}







    }

	return 0;
}
