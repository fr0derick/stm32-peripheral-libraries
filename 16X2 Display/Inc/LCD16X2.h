/*
 * LCD16X2.h
 *
 *  Created on: 9 Oct 2026
 *      Author: 725287
 */

#ifndef INC_LCD16X2_H_
#define INC_LCD16X2_H_

#include "LCD16X2_cfg.h"
#include "delay.h"

// Prototypes for the API functions
void LCD16X2_Init(uint8_t lcd_index);
void LCD16X2_Clear(uint8_t lcd_index);
void LCD16X2_SetCursor(uint8_t lcd_index, uint8_t row, uint8_t col);
void LCD16X2_WriteChar(uint8_t lcd_index, char ch);
void LCD16X2_WriteString(uint8_t lcd_index, const char* str);
void LCD16X2_WriteInt(uint8_t lcd_index, int number);
void LCD16X2_ShiftLeft(uint8_t lcd_index);
void LCD16X2_ShiftRight(uint8_t lcd_index);

#endif /* INC_LCD16X2_H_ */
