/*
 * Timer_prv.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Abo El-Naga
 */

#ifndef MCAL_TIMER_TIMER_PRV_H_
#define MCAL_TIMER_TIMER_PRV_H_

#include"../../LIB/Std_Types.h"

#define TIMER_CTRL_REG           ((volatileuint8*)0x53U)
#define TIMER_COUTNER_REG        ((volatileuint8*)0x52U)
#define TIMER_COMPARE_REG        ((volatileuint8*)0x5CU)
#define TIMER_INT_MASK_REG       ((volatileuint8*)0x59U)
#define TIMER_INT_FLAG_REG       ((volatileuint8*)0x58U)

#endif /* MCAL_TIMER_TIMER_PRV_H_ */
