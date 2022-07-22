/*
 * Timer_int.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Abo El-Naga
 */

#ifndef MCAL_TIMER_TIMER_INT_H_
#define MCAL_TIMER_TIMER_INT_H_


typedef enum
{
	NO_CLK_SOURCE,
	NO_PRESCALE,
	PRESCALE_8,
	PRESCALE_64,
	PRESCALE_256,
	PRESCALE_1024,
	EXT_CLK_SOURCE_RISING_EDGE,
	EXT_CLK_SOURCE_FALLING_EDGE

}TimerPrescale_enum;

typedef enum
{
	TIMER_INT_DISABLE,
	TIMER_INT_ENABLE
};





typedef struct {
	TimerPrescale_enum Prescale;





}Timerconfig;
void MTIMER_vinit(const Timerconfig* config);
void MTIMER_vSetPreloadValue(uint16 A_u16PreLoad);
void MTIMER_vSetInterval(uint16 A_u16IntervalCounts,void(*A_fptr)(void));
void MTIMER_vStartTimer();
void MTIMER_vStopTimer();











#endif /* MCAL_TIMER_TIMER_INT_H_ */
