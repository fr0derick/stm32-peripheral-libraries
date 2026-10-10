/*
 * delay.c
 *
 *  Created on: 9 Oct 2026
 *      Author: 725287
 */

// Delays by 'us' microseconds

#include "delay.h"

void delay_us(uint32_t us) {
	uint32_t remaining = us * (SystemCoreClock / 1000000U);
	uint32_t previous = SysTick->VAL;
	uint32_t period = SysTick->LOAD+1U;

	while (remaining > 0U) {
		uint32_t current = SysTick->VAL;

		uint32_t elapsed = (previous >= current)
				? previous - current
				: previous + period - current;

		if (elapsed >= remaining)
			break;

		remaining -= elapsed;
		previous = current;
	}
}
