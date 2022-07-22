/*
 * LM35_prg.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Abo El-Naga
 */

#include "LM35_int.h"
#include"../HLCD/HLCD_int.h"

/*
void HLM35_vInit()
{
	MADC_vInit(&gStr_ADC_Configuration);

}
float32 HLM35_vRead()
{
	float32 L_f32temp;
	float32 L_f32AnalogTemp=MADC_u16AnalogRead(LM35_Pin);




	L_f32temp=((L_f32AnalogTemp*Voltage_Ref)/(1<<10U))*100;


	return L_f32temp;
}*/



void HLM35_vInit()
{
	MADC_vInit(&gStr_ADC_Configuration);
}
uint16 HLM35_vRead(uint16 A_u16Analogtemp)
{
	uint16 L_u16temp=0;


	L_u16temp=((A_u16Analogtemp*Voltage_Ref*100)/(1<<10U));


	return L_u16temp;
}

