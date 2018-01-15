#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "HAL.h"

volatile uint8_t tick = 0;

ISR(TIM0_COMPA_vect) {
	tick = 1;
}

int main(void) {
	SystemInit();
	uint8_t currentLED = 0;

	for(;;) {
		while(tick == 0) {} //idle until Timer0 compare match interrupt
		tick = 0;

		illuminateLED(currentLED);
		currentLED++;
		if (currentLED > 100) {
			currentLED = 0;
		}
	}
}	
