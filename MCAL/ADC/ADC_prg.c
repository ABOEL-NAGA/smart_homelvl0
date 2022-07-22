/*
 * ADC_prg.c
 *
 *  Created on: Jul 11, 2022
 *      Author: Abo El-Naga
 */


#include"ADC_int.h"
#include"../../LIB/BIT_MATH.h"
#include"ADC_cgf.h"


void(*ADC_Callback)(void);
void MADC_vInit(const configuration* config)
{
	*ADC_MUX_REG=0X00;
	*ADC_CTRL_REG_A=0X00;
	*SPECIAL_FUN_REG&=0X1F;

	//reference voltage selection & adjustment direction
*ADC_MUX_REG|=config->REF|config->ALIGN;

	//prescaler selection &auto trigger enable & interrupt enable
*ADC_CTRL_REG_A|= config->Prescale|config->TriggerMode|config->IntState;

	//auto trigger source
*SPECIAL_FUN_REG|=config->AutoTriggerSource;

    //adc enable
SET_BIT(*ADC_CTRL_REG_A,ADC_ENABLE_BIT);

}
uint16 MADC_u16AnalogRead(ADC_ChannelEnum A_u8ChannelNo)
{
	*ADC_MUX_REG&=0xE0;
	*ADC_MUX_REG|=A_u8ChannelNo;
	SET_BIT(*ADC_CTRL_REG_A,ADC_START_CONV_BIT);
	while(READ_BIT(*ADC_CTRL_REG_A,ADC_INT_FLAG)==0)
	{
		//DO NOTHING
	}

SET_BIT(*ADC_CTRL_REG_A,ADC_INT_FLAG);


	return *ADC_DATA_REG;
}


void MADC_vStartConversion(ADC_ChannelEnum A_u8ChannelNo)
{

	*ADC_MUX_REG&=0xE0;
	*ADC_MUX_REG|=A_u8ChannelNo;
	MGIE_vGlobalIntEnable();
	SET_BIT(*ADC_CTRL_REG_A,ADC_START_CONV_BIT);


}

void MADC_vSetCallback(void(*A_fptr)(void))
{
	ADC_Callback=A_fptr	;

}

void __vector_16(void)   __attribute__((signal));
void __vector_16(void)
{

  ADC_Callback();

}

uint16 MADC_u16GetResult()
{
	return *ADC_DATA_REG;
}

