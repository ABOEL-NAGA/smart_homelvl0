/*
 * Timer_prg.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Abo El-Naga
 */

#include"../../LIB/BIT_MATH.h"
#include"Timer_prv.h"
#include"Timer_int.h"


void (*G_TIMER0_OVF)(void);
void MTIMER_vinit(const Timerconfig* config)
{

}
void MTIMER_vSetPreloadValue(uint16 A_u16PreLoad)
{

}
void MTIMER_vSetInterval(uint16 A_u16IntervalCounts,void(*A_fptr)(void))
{
	G_TIMER0_OVF=A_fptr;

}
void MTIMER_vStartTimer()
{

}
	void MTIMER_vStopTimer()
{

}

/*
	void __vector_11(void)  __attribute__((signal));
	void __vector_11(void)
	{
		if(G_TIMER0_OVF()!=NULL)
		{

		}
	}
*/
