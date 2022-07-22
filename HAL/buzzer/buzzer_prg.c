/*
 * buzzer_prg.c
 *
 *  Created on: Jul 22, 2022
 *      Author: Abo El-Naga
 */


#include"buzzer_int.h"


void Buzzer_Init()
{
	DIO_vSetPinDir(BUZZER_PORT,BUZZER_PIN,DIO_OUTPUT);
}

void BuzzerSet(BuzzerState_Enum A_state)
{

	DIO_vSetPinVal(BUZZER_PORT,BUZZER_PIN,A_state);



}
