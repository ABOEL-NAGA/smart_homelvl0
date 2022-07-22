/*
 * DIO_prv.h
 *
 *  Created on: Jul 12, 2022
 *      Author: Abo El-Naga
 */

#ifndef MCAL_DIO_DIO_PRV_H_
#define MCAL_DIO_DIO_PRV_H_


#define PORTA_DIR_REG  ((volatile uint8*) 0x3AU)
#define PORTA_IN_REG   ((volatile uint8*) 0x39U)
#define PORTA_OUT_REG  ((volatile uint8*) 0x3BU)


#define PORTB_DIR_REG  ((volatile uint8*) 0x37U)
#define PORTB_IN_REG   ((volatile uint8*) 0x36U)
#define PORTB_OUT_REG  ((volatile uint8*) 0x38U)


#define PORTC_DIR_REG  ((volatile uint8*) 0x34U)
#define PORTC_IN_REG   ((volatile uint8*)0x33U)
#define PORTC_OUT_REG  ((volatile uint8*)0x35U)

#define PORTD_DIR_REG  ((volatile uint8* )0x31U)
#define PORTD_IN_REG   ((volatile uint8*)0x30U)
#define PORTD_OUT_REG  ((volatile uint8*)0x32U)

#endif /* MCAL_DIO_DIO_PRV_H_ */
