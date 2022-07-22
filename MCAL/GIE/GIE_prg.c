/*
 * GIE_prg.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Abo El-Naga
 */

#include "GIE_int.h"
#include "../../LIB/BIT_MATH.h"
void MGIE_vGlobalIntEnable()
{
	SET_BIT(*GLOBAL_INT_REG,GLOBAL_INT_BIT);

}
void MGIE_vGlobalIntDisable()
{
	CLEAR_BIT(*GLOBAL_INT_REG,GLOBAL_INT_BIT);

}
