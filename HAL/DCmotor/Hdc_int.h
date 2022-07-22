/*
 * Hdc_int.h
 *
 *  Created on: May 31, 2022
 *      Author: Abo El-Naga
 */

#ifndef HAL_DCMOTOR_HDC_INT_H_
#define HAL_DCMOTOR_HDC_INT_H_

#define NUMBER_OF_MOTORS      1
#include"../../MCAL/DIO/DIO_int.h"



typedef enum
{
	MOTOR1

}DCmotors_enum;
typedef enum
{
	CW,
	CCW

}DCmotorDir_enum;

typedef struct
{
	DIO_PortEnum port;
	DIO_PinEnum DCM_pin1;
	DIO_PinEnum DCM_pin2;

}DCproperties;


void HDCM_vInit(const DCproperties* config);
void HDCM_vDirCW(const DCproperties* config);
void HDCM_vDirCCW(const DCproperties* config);
void HDCM_vStop(const DCproperties* config);

extern const DCproperties  DCconfig[NUMBER_OF_MOTORS];





#endif /* HAL_DCMOTOR_HDC_INT_H_ */
