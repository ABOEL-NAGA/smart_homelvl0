/*
 * LM35_int.h
 *
 *  Created on: Jul 13, 2022
 *      Author: Abo El-Naga
 */

#ifndef HAL_LM35_LM35_INT_H_
#define HAL_LM35_LM35_INT_H_
#include "LM35_cfg.h"





void HLM35_vInit();
uint16 HLM35_vRead(uint16 A_u16Analogtemp);



#endif /* HAL_LM35_LM35_INT_H_ */
