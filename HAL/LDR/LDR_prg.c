/*
 * LDR_prg.c
 *
 *  Created on: Jul 20, 2022
 *      Author: Abo El-Naga
 */


#include"LDR_int.h"






void HLDR_vInit()
{
	MADC_vInit(&gStr_ADC_Configuration);


}
float32 HLDR_u16ReadValue(float32 A_u16AnalogVoltage)
{

	float32 L_u16LDRresistance;

	float32 L_u16ActualVoltage=(A_u16AnalogVoltage*Voltage_Ref)/(1024);

	 L_u16LDRresistance=((Voltage_Ref*Serial_resistance)/L_u16ActualVoltage)-Serial_resistance;

return L_u16LDRresistance;
}

