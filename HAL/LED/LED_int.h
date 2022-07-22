/*
 * LED_int.h
 *
 *  Created on: Jul 22, 2022
 *      Author: Abo El-Naga
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_
#include"LED_cfg.h"

typedef enum
{
	LED_OFF=DIO_LOW,
	LED_ON=DIO_HIGH
}LedState_enuM;

void LED_Init();


void LED_SET(LedState_enuM STATE);


#endif /* HAL_LED_LED_INT_H_ */
