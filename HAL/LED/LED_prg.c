/*
 * LED_prg.c
 *
 *  Created on: Jul 22, 2022
 *      Author: Abo El-Naga
 */


#include"LED_int.h"




void LED_Init()
{
	DIO_vSetPinDir(LED_PORT,LED_PIN,DIO_OUTPUT);
}


void LED_SET(LedState_enuM STATE)
{
	switch(STATE)
	{
	case LED_OFF:
		DIO_vSetPinVal(LED_PORT,LED_PIN,DIO_LOW);
		break;
	case LED_ON:
		DIO_vSetPinVal(LED_PORT,LED_PIN,DIO_HIGH);
break;
	default:
		break;
	}
}
