/*
 * buzzer_int.h
 *
 *  Created on: Jul 22, 2022
 *      Author: Abo El-Naga
 */

#ifndef HAL_BUZZER_BUZZER_INT_H_
#define HAL_BUZZER_BUZZER_INT_H_
#include"buzzer_cfg.h"




typedef enum
{
	BUZZER_OFF=DIO_LOW,
	BUZZER_ON=DIO_HIGH
}BuzzerState_Enum;

void Buzzer_Init();
void BuzzerSet(BuzzerState_Enum A_state);






#endif /* HAL_BUZZER_BUZZER_INT_H_ */
