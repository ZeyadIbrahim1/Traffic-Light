/*
 * timers.h
 *
 * Created: 11/5/2022 7:55:56 PM
 *  Author: eng_z
 */


#ifndef TIMERS_H_
#define TIMERS_H_
#include "../../Headers/registers.h"
#include "../Interrupts/interrupts.h"


//timer modes
#define NORMAL_MODE			 0
#define PHASE_CORRECT_MODE   1
#define CTC_MODE			 2
#define FAST_PWM_MODE		 3


//Prescaler Macros

#define NO_PRESCALER	0
#define PRESCALER_8		1
#define PRESCALER_64	2
#define PRESCALER_256	3
#define PRESCALER_1024	4

//TIMSK
#define TOIE0	0
#define OCIE0	1
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5
#define TOIE2	6
#define OCIE2	7

// TCCR0
#define CS00 0
#define CS01 1
#define CS02 2

// TCCR2
#define CS20 0
#define CS21 1
#define CS22 2

// TIFR
#define TOV0 0
#define TOV2 6


//timer 0 initialization
void TIMER0_init(uint8_t timerMode);

//timer 0 start
void TIMER0_start(uint8_t timerPrescaler , uint8_t initial_Value);

//timer stop
void TIMER0_stop (void);


//timer 0 delay
void TIMER0_delay (uint8_t timerPrescaler , uint8_t initial_Value ,uint8_t numberOfOverFlows);




//timer 2 initialization
void TIMER2_init(uint8_t timerMode);


//timer 2 start
void TIMER2_start(uint8_t timerPrescaler , uint8_t initial_Value);


//timer stop
void TIMER2_stop (void);


//timer 2 delay
void TIMER2_delay (uint8_t timerPrescaler , uint8_t initial_Value ,uint8_t numberOfOverFlows);


#endif /* TIMERS_H_ */