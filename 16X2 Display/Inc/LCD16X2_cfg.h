/*
 * LCD16X2_cfg.h
 *
 *  Created on: 9 Oct 2026
 *      Author: 725287
 */

#ifndef INC_LCD16X2_CFG_H_
#define INC_LCD16X2_CFG_H_

#include "main.h"

#define LCD16X2_MAX 1 // Number of LCD modules in the project
#define LCD16X2_1 0 // This is the instance index for the first LCD module
typedef struct {
	uint8_t LCD16X2_Instance;

	GPIO_TypeDef* D4_GPIOx;
	uint16_t D4_PINx;

	GPIO_TypeDef* D5_GPIOx;
	uint16_t D5_PINx;

	GPIO_TypeDef* D6_GPIOx;
	uint16_t D6_PINx;

	GPIO_TypeDef* D7_GPIOx;
	uint16_t D7_PINx;

	GPIO_TypeDef* EN_GPIOx;
	uint16_t EN_PINx;

	GPIO_TypeDef* RS_GPIOx;
	uint16_t RS_PINx;
} LCD16X2_CfgType;

extern const LCD16X2_CfgType LCD16X2_CfgParam[LCD16X2_MAX];

#endif /* INC_LCD16X2_CFG_H_ */
