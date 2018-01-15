/* 

Released under the terms of the MIT License.

The MIT License (MIT)
Copyright (c) 2016 by Zach Fredin
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.	

Charlieplexing!

PB3		LED_BOTTOM_0
PB4		LED_BOTTOM_1
PB2		LED_TOP_0
PB0		LED_TOP_1
PB1		Switch (pull up)

					  |----|<D0----|
				 |----|			   |--------------------|	
				 |	  |----D1>|----|					|
LED_BOTTOM_0 ----|										|----LED_TOP_0
				 |    |----|<D2----|	 				|
				 |----|			   |----|				|
					  |----D3>|----|	|		 		|
										|				|
										|----LED_TOP_1	|
										|				|
					  |----|<D4----|	|				|
				 |----|			   |----|				|
				 |	  |----D5>|----|					|
LED_BOTTOM_1 ----|										|
				 |    |----|<D6----|		 			|
				 |----|			   |--------------------|	 
					  |----D7>|----|		 





*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "HAL.h"

void SystemInit(void) {
	DDRB = 0; //set everything to an input for now
	PORTB |= (1<<PB1); //switch pullup

	// set up tick timer:
	TCCR0A |= (1<<WGM01); //CTC at OCR0A
	TCCR0B |= ((1<<CS02) | (1<<CS00)); //clk/1024
	OCR0A = 30; //sets tick to ~1ms
	TIMSK |= (1<<OCIE0A); //output compare match 0A interrupt enable

	sei();
}

void illuminateLED(uint8_t LED) {
	//	PB3		LED_BOTTOM_0
	//	PB4		LED_BOTTOM_1
	//	PB2		LED_TOP_0
	//	PB0		LED_TOP_1

	DDRB = 0;
	PORTB &= ~((1<<PB0) | (1<<PB2) | (1<<PB3) | (1<<PB4));
	switch(LED) {
		case 0:
			DDRB |= ((1<<PB3) | (1<<PB2));
			PORTB &= ~(1<<PB2);
			PORTB |= (1<<PB3);
			break;
			
		case 1:
			DDRB |= ((1<<PB3) | (1<<PB2));
			PORTB &= ~(1<<PB3);
			PORTB |= (1<<PB2);
			break;

		case 2:
			DDRB |= ((1<<PB3) | (1<<PB0));
			PORTB |= (1<<PB3);
			PORTB &= ~(1<<PB0);
			break;

		case 3:
			DDRB |= ((1<<PB3) | (1<<PB0));
			PORTB &= ~(1<<PB3);
			PORTB |= (1<<PB0);
			break;

		case 4:
			DDRB |= ((1<<PB4) | (1<<PB0));
			PORTB |= (1<<PB4);
			PORTB &= ~(1<<PB0);
			break;

		case 5:
			DDRB |= ((1<<PB4) | (1<<PB0));
			PORTB &= ~(1<<PB4);
			PORTB |= (1<<PB0);
			break;
	
		case 6:
			DDRB |= ((1<<PB4) | (1<<PB2));
			PORTB &= ~(1<<PB2);
			PORTB |= (1<<PB4);
			break;

		case 7:
			DDRB |= ((1<<PB4) | (1<<PB2));
			PORTB |= (1<<PB2);
			PORTB &= ~(1<<PB4);
			break;
	}
}
