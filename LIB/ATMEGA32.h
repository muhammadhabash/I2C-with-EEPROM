#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include "STD_types.h"

/****************************************************************************/
/*                                                                          */
/*                           GPIO Registers                                 */
/*                                                                          */
/****************************************************************************/

#define SFIO_R      (0x50)
#define GPIO_DATA_R (0x3B)
#define GPIO_DIR_R  (0x3A)
#define GPIO_BITS_R (0x39)


/****************************************************************************/
/*                                                                          */
/*                           Timers Registers (TIMER0)                      */
/*                                                                          */
/****************************************************************************/

#define TIMER0_CTL_R (*((volatile uint8_t*) 0x53))
#define TIMER0_CNT_R (*((volatile uint8_t*) 0x52))
#define TIMER0_OC_R  (*((volatile uint8_t*) 0x5C))


/****************************************************************************/
/*                                                                          */
/*                           Timers Registers (TIMER1)                      */
/*                                                                          */
/****************************************************************************/

#define TIMER1_CTL_A_R    (*((volatile uint8_t*) 0x4F))
#define TIMER1_CTL_B_R    (*((volatile uint8_t*) 0x4E))
#define TIMER1_CNT_A_L_R  (*((volatile uint8_t*) 0x4D))
#define TIMER1_CNT_A_H_R  (*((volatile uint8_t*) 0x4C))
#define TIMER1_OC_A_H_R   (*((volatile uint8_t*) 0x4B))
#define TIMER1_OC_A_L_R   (*((volatile uint8_t*) 0x4A))
#define TIMER1_OC_B_H_R   (*((volatile uint8_t*) 0x49))
#define TIMER1_OC_B_L_R   (*((volatile uint8_t*) 0x48))
#define TIMER1_IC_H_R     (*((volatile uint8_t*) 0x47))
#define TIMER1_IC_L_R     (*((volatile uint8_t*) 0x46))

/****************************************************************************/
/*                                                                          */
/*                           Timers Registers (TIMER2)                      */
/*                                                                          */
/****************************************************************************/

#define TIMER2_CTL_R  (*((volatile uint8_t*) 0x45))
#define TIMER2_CNT_R  (*((volatile uint8_t*) 0x44))
#define TIMER2_OC_R   (*((volatile uint8_t*) 0x43))
#define TIMER2_ASS_R  (*((volatile uint8_t*) 0x42))

/****************************************************************************/
/*                                                                          */
/*                   Timers Interrupts and Flags Registers                  */
/*                                                                          */
/****************************************************************************/

#define TIMSK_R (*((volatile uint8_t*) 0x59))
#define TIF_R   (*((volatile uint8_t*) 0x58))

/****************************************************************************/
/*                                                                          */
/*                           Status Register                                */
/*                                                                          */
/****************************************************************************/

#define STATUS_R (*((volatile uint8_t*) 0x5F))

/****************************************************************************/
/*                                                                          */
/*                           ADC Registers                                  */
/*                                                                          */
/****************************************************************************/

#define ADMUX_R (*((volatile uint8_t*)0x27))
#define ADCSA_R (*((volatile uint8_t*)0x26))
#define ADCH_R  (*((volatile uint8_t*)0x25))
#define ADCL_R  (*((volatile uint8_t*)0x24))

/****************************************************************************/
/*                                                                          */
/*                           TWI Registers                                  */
/*                                                                          */
/****************************************************************************/

#define TWCR  (*((volatile uint8_t*)0x56))
#define TWDR  (*((volatile uint8_t*)0x23))
#define TWAR  (*((volatile uint8_t*)0x22))
#define TWSR  (*((volatile uint8_t*)0x21))
#define TWBR  (*((volatile uint8_t*)0x20))

/****************************************************************************/
/*                                                                          */
/*                           UART Registers                                 */
/*                                                                          */
/****************************************************************************/

#define UD_R   (*((volatile uint8_t*)0x2C))
#define UCSA_R (*((volatile uint8_t*)0x2B))
#define UCSB_R (*((volatile uint8_t*)0x2A))
#define UBRL_R (*((volatile uint8_t*)0x29))
#define UBRH_R (*((volatile uint8_t*)0x40))
#define UCSC_R (*((volatile uint8_t*)0x40))

#endif 