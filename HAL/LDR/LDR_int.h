/*
 * LM35_int.h
 *
 *  Created on: Jul 20, 2022
 *      Author: Abo El-Naga
 */

#ifndef HAL_LDR_LDR_INT_H_
#define HAL_LDR_LDR_INT_H_

#include"../../MCAL/ADC/ADC_int.h"
#include"../../MCAL/GIE/GIE_int.h"
#include"LDR_cfg.h"



void HLDR_vInit();
float32 HLDR_u16ReadValue(float32 A_u16AnalogVoltage);
void HLDR_vSetcallback(void(*fptr)(void));

#endif /* HAL_LDR_LDR_INT_H_ */
