/*
 * ADC_int.h
 *
 *  Created on: Jul 11, 2022
 *      Author: Abo El-Naga
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "ADC_prv.h"
#include"../GIE/GIE_int.h"


#define ADC_ENABLE_BIT  7U
#define ADC_START_CONV_BIT 6U
#define ADC_INT_FLAG       4U


typedef enum
{
	ADC_PIN0,
	ADC_PIN1,
	ADC_PIN2,
	ADC_PIN3,
	ADC_PIN4,
	ADC_PIN5,
	ADC_PIN6,
	ADC_PIN7

}ADC_ChannelEnum;

typedef enum
{
	INTERNAL_VOLTAGE=0x00U,
	AVCC =0x40U,
	AREFF=0xC0U
}ADC_RefVoltEnum;



typedef enum
{
  PRESCALE_2=0x01,
  PRESCALE_4=0x02,
  PRESCALE_8=0x03,
  PRESCALE_16=0x04,
  PRESCALE_32=0x05,
  PRESCALE_64=0x06,
  PRESCALE_128=0x07

}ADC_PreScaleEnum;

typedef enum
{
	RIGHT_ALIGHNMENT=0x00U,
	LEFT_ALIGHNMENT=0x20U

}ADC_DataAlighnmentEnum;

typedef enum
{
	ADC_INT_DISABLE=0X00U,
	ADC_INT_ENABLED=0x08U

}ADC_IntStateEnum;

typedef enum
{
	AUTO_TRIGGER=0x20U,
	SINGLE_TRIGGER=0x00U
}ADC_TriggerModeEnum;

typedef enum
{
	FREE_RUNNING_MODE=0x00U,
    ANALOG_COMPARATOR=0x20U,
	EXTERNAL_INT_REQ=0x40U,
	TIMER0_CMP_MATCH=0x60U,
	TIMER0_OVF=0x80U,
	TIMER1_CMP_MATCH_B=0xA0U,
	TIMER1_OVF=0xC0U,
	TIMER1_CAPTURE_EVENT=0xE0U

}ADC_AutoTriggerModeEnum;

typedef struct
{
	ADC_DataAlighnmentEnum ALIGN;
	ADC_RefVoltEnum        REF;
	ADC_PreScaleEnum       Prescale;
	ADC_IntStateEnum       IntState;
	ADC_TriggerModeEnum    TriggerMode;
	ADC_AutoTriggerModeEnum AutoTriggerSource;
}configuration;


void MADC_vInit(const configuration* config);
uint16 MADC_u16AnalogRead(ADC_ChannelEnum A_u8ChannelNo);
void MADC_vStartConversion(ADC_ChannelEnum A_u8ChannelNo);
uint16 MADC_u16GetResult();
void MADC_vSetCallback(void(*A_fptr)(void));

extern const configuration gStr_ADC_Configuration;




#endif /* ADC_INT_H_ */
