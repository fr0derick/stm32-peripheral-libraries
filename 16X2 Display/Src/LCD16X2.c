/*
 * LCD16X2.c
 *
 *  Created on: 9 Oct 2026
 *      Author: 725287
 */

#include "LCD16X2.h"
#include <stdio.h>

static void lcd_enable_pulse(const LCD16X2_CfgType* lcd) {
	HAL_GPIO_WritePin(lcd->EN_GPIOx, lcd->EN_PINx, GPIO_PIN_SET);
	delay_us(2);
	HAL_GPIO_WritePin(lcd->EN_GPIOx, lcd->EN_PINx, GPIO_PIN_RESET);
	delay_us(50);
}

static void lcd_write_nibble(const LCD16X2_CfgType* lcd, uint8_t nibble) {
	HAL_GPIO_WritePin(lcd->D4_GPIOx, lcd->D4_PINx, (nibble & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->D5_GPIOx, lcd->D5_PINx, (nibble & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->D6_GPIOx, lcd->D6_PINx, (nibble & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->D7_GPIOx, lcd->D7_PINx, (nibble & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);

	lcd_enable_pulse(lcd);
}

static void lcd_send_cmd(const LCD16X2_CfgType* lcd, uint8_t cmd) {
	HAL_GPIO_WritePin(lcd->RS_GPIOx, lcd->RS_PINx, GPIO_PIN_RESET);
	// so we need to send MSB first, then the LSB using the bitwise masks and operators
	lcd_write_nibble(lcd, (cmd >> 4) & 0x0F);
	lcd_write_nibble(lcd, cmd & 0x0F);

	if (cmd == 0x01 || cmd == 0x02) {
		HAL_Delay(2);
	}
}

static void lcd_send_data(const LCD16X2_CfgType* lcd, uint8_t data) {
	HAL_GPIO_WritePin(lcd->RS_GPIOx, lcd->RS_PINx, GPIO_PIN_SET);

	lcd_write_nibble(lcd, (data >> 4) & 0x0F);
	lcd_write_nibble(lcd, data & 0x0F);
}

void LCD16X2_Init(uint8_t lcd_index) {
	const LCD16X2_CfgType* lcd= &LCD16X2_CfgParam[lcd_index];
	HAL_Delay(20);

	// need to force 4-bit communication instead of 8 bit communication
	HAL_GPIO_WritePin(lcd->RS_GPIOx, lcd->RS_PINx, GPIO_PIN_RESET);
	lcd_write_nibble(lcd, 0x03);
	HAL_Delay(5);
	lcd_write_nibble(lcd, 0x03);
	delay_us(150);
	lcd_write_nibble(lcd, 0x03);
	lcd_write_nibble(lcd, 0x02);

	lcd_send_cmd(lcd, 0x28); // this sets 4-bit, 2 line, 5x8
	lcd_send_cmd(lcd, 0x0C); // display control
	lcd_send_cmd(lcd, 0x01); // 0x01 command clears display
	lcd_send_cmd(lcd, 0x06); // entry mode set: increment cursor
}

void LCD16X2_Clear(uint8_t lcd_index) {
	const LCD16X2_CfgType* lcd = &LCD16X2_CfgParam[lcd_index];
	lcd_send_cmd(lcd, 0x01);
}

void LCD16X2_SetCursor(uint8_t lcd_index, uint8_t row, uint8_t col) {
	const LCD16X2_CfgType* lcd = &LCD16X2_CfgParam[lcd_index];
	uint8_t address = 0;

	if (row == 1) {
		address = 0x80 + (col - 1); // the 1st row ddram base address begins at 0x80
	}
	else if (row == 2) {
		address = 0xC0 + (col - 1); // the 2nd row ddram base address = 0xC0
	}

	lcd_send_cmd(lcd, address);
}

void LCD16X2_WriteChar(uint8_t lcd_index, char ch) {
	const LCD16X2_CfgType* lcd = &LCD16X2_CfgParam[lcd_index];
	lcd_send_data(lcd, (uint8_t)ch);
}

void LCD16X2_WriteString(uint8_t lcd_index, const char * str) {
	while (*str) {
		LCD16X2_WriteChar(lcd_index, *str++);
	}
}

void LCD16X2_WriteInt(uint8_t lcd_index, int number) {
	char buffer[16];
	snprintf(buffer, sizeof(buffer), "%d", number);
	LCD16X2_WriteString(lcd_index, buffer);
}

void LCD16X2_ShiftLeft(uint8_t lcd_index) {
	const LCD16X2_CfgType* lcd= &LCD16X2_CfgParam[lcd_index];
	lcd_send_cmd(lcd, 0x18);
}

void LCD16X2_ShiftRight(uint8_t lcd_index) {
	const LCD16X2_CfgType* lcd= &LCD16X2_CfgParam[lcd_index];
	lcd_send_cmd(lcd, 0x1C);
}

