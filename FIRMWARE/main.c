#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "HAL.h"

volatile uint8_t tick = 0;
uint8_t direction = 1; //1 = pos, 0 = neg
uint8_t count = 0;
uint8_t count_reset = 3;

ISR(TIM0_COMPA_vect) {
	tick = 1;
}

ISR(PCINT0_vect) {
	count = 0;
	currentLED = 0;
}

int main(void) {
	SystemInit();
	uint8_t currentLED = 0;

	for(;;) {
		while(tick == 0) {} //idle until Timer0 compare match interrupt
		tick = 0;

		illuminateLED(currentLED);

		if (direction == 1) {
			currentLED++;
		}
		else {
			currentLED--;
		}

		if (currentLED == 50) {
			direction = 0;
			count++;
		}
		if (currentLED == 0) {
			direction = 1;
		}

		if (count == count_reset) {
			set_sleep_mode(SLEEP_MODE_PWR_DOWN);
			sleep_enable();
			sleep_cpu();
		}
	}
}	
