/*
 * ADC_prv.h
 *
 *  Created on: Jul 12, 2022
 *      Author: Abo El-Naga
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

#include"../../LIB/Std_Types.h"



#define ADC_MUX_REG     ((volatile uint8*)0x27U)
#define ADC_CTRL_REG_A  ((volatile uint8*)0x26U)
#define ADC_DATA_REG  ((volatile uint16*)0x24U)

#define SPECIAL_FUN_REG ((volatile uint8*)0x50U)


#endif /* MCAL_ADC_ADC_PRV_H_ */
