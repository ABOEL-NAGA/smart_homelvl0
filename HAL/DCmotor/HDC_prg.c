/*
 * HDC_prg.c
 *
 *  Created on: May 31, 2022
 *      Author: Abo El-Naga
 */

#include "Hdc_int.h"




void HDCM_vInit(const DCproperties* config)
{
	DIO_vSetPinDir(config->port,config->DCM_pin1,DIO_OUTPUT);
	DIO_vSetPinDir(config->port,config->DCM_pin2,DIO_OUTPUT);

}

void HDCM_vDirCW(const DCproperties* config)
{
	DIO_vSetPinVal(config->port,config->DCM_pin1,DIO_HIGH);
	DIO_vSetPinVal(config->port,config->DCM_pin2,DIO_LOW);

}
void HDCM_vDirCCW(const DCproperties* config)
{

	DIO_vSetPinVal(config->port,config->DCM_pin1,DIO_LOW);
		DIO_vSetPinVal(config->port,config->DCM_pin2,DIO_HIGH);
}

void HDCM_vStop(const DCproperties* config)
{


	DIO_vSetPinVal(config->port,config->DCM_pin1,DIO_LOW);
			DIO_vSetPinVal(config->port,config->DCM_pin2,DIO_LOW);


}

