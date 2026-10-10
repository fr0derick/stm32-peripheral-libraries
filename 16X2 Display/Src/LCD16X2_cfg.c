/*
 * LCD16X2_cfg.c
 *
 *  Created on: 9 Oct 2026
 *      Author: 725287
 */

#include "LCD16X2_cfg.h"

// Change the PORT, PIN below to match the pin layout of the MCU

// For 4-bit communication mode, D0-D3 are unused
// So we send 8 bit data MSB first.

const LCD16X2_CfgType LCD16X2_CfgParam[LCD16X2_MAX] =
{
		{
				LCD16X2_1,
				GPIOA, GPIO_PIN_5, // D4
				GPIOA, GPIO_PIN_6, // D5
				GPIOA, GPIO_PIN_7, // D6
				GPIOB, GPIO_PIN_0, // D7
				GPIOA, GPIO_PIN_4, // EN
				GPIOA, GPIO_PIN_3, // RS
		}
};
