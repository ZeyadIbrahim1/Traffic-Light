/*
 * timer.c
 *
 * Created: 11/5/2022 7:57:07 PM
 *  Author: eng_z
 */ 
#include "timer.h"
#include "../../Headers/macros.h"
#include "../Interrupts/interrupts.h"
//timer 0 initialization
void TIMER0_init(uint8_t timerMode)
{
	switch(timerMode)

	{
		case NORMAL_MODE:
		TCCR0 =0x00;
		break;
		
		case PHASE_CORRECT_MODE:
		TCCR0=0x40;
		break;
		
		case CTC_MODE:
		TCCR0=0x08;
		break;
		
		case FAST_PWM_MODE:
		TCCR0=0x48;
		break;
		
		default:
		{
			//error handeling
		}
	}

}

//timer 0 start
void TIMER0_start(uint8_t timerPrescaler , uint8_t initial_Value)
{
	TCNT0 =initial_Value;
	
	if(timerPrescaler <= PRESCALER_1024)
	{
		switch(timerPrescaler)
		{
			case NO_PRESCALER:

				SET_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
				break;
			
			case PRESCALER_8:
				CLR_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
				break;
			
			case PRESCALER_64:
				SET_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
				break;
			
			case PRESCALER_256:
				CLR_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS02);
				break;
			
			
			case PRESCALER_1024:
				SET_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS02);
				break;
			
			default:
			{
				//error handling
				break;
			}
		}	
	}
	
	
	
}

//timer stop
void TIMER0_stop (void){
		TCCR0 = 0x00;
}


//timer 0 delay
void TIMER0_delay (uint8_t timerPrescaler , uint8_t initial_Value ,uint8_t numberOfOverFlows)
{
		// Reset The Over Flow Counter
uint32_t overFlowCounter   = 0;
		
		// Start TIMER 0
TIMER0_start(timerPrescaler, initial_Value);
		 
	
	while(overFlowCounter<numberOfOverFlows)
	{
		while(GET_BIT(TIFR,TOV0)==0);
		
		CLR_BIT(TIFR,TOV0);
		
		overFlowCounter++;
	}
	
overFlowCounter=0;
TIMER0_stop();
}





//timer 2 initialization
void TIMER2_init(uint8_t timerMode)
{
	switch(timerMode)

	{
		case NORMAL_MODE:
		TCCR0 =0x00;
		break;
		
		case PHASE_CORRECT_MODE:
		TCCR0=0x40;
		break;
		
		case CTC_MODE:
		TCCR0=0x08;
		break;
		
		case FAST_PWM_MODE:
		TCCR0=0x48;
		break;
		
		default:
		{
			//error handeling
		}
	}
}


//timer 2 start
void TIMER2_start(uint8_t timerPrescaler , uint8_t initial_Value)
{
	TCNT0 =initial_Value;
	
	switch(timerPrescaler)
	{
		case NO_PRESCALER:
							SET_BIT(TCCR2,CS20);
							CLR_BIT(TCCR2,CS21);
							CLR_BIT(TCCR2,CS22);
							break;
		
		case PRESCALER_8:
							CLR_BIT(TCCR2,CS20);
							SET_BIT(TCCR2,CS21);
							CLR_BIT(TCCR2,CS22);
							break;
		
		case PRESCALER_64:
							SET_BIT(TCCR2,CS20);
							SET_BIT(TCCR2,CS21);
							CLR_BIT(TCCR2,CS22);
							break;
		
		case PRESCALER_256:
							CLR_BIT(TCCR2,CS20);
							CLR_BIT(TCCR2,CS21);
							SET_BIT(TCCR2,CS22);
							break;
		
		
		case PRESCALER_1024:
							SET_BIT(TCCR2,CS20);
							CLR_BIT(TCCR2,CS21);
							SET_BIT(TCCR2,CS22);
							break;
		
		default:
		{
			//error handling
		}
	}
	
}


//timer stop
void TIMER2_stop (void)
{
		TCCR2 = 0x00;

}


//timer 2 delay
void TIMER2_delay (uint8_t timerPrescaler , uint8_t initial_Value ,uint8_t numberOfOverFlows)
{
	uint32_t overFlowCounter = 0;
	
	// Start TIMER 2
	TIMER2_start(timerPrescaler, initial_Value);
	
	while(overFlowCounter<numberOfOverFlows)
	{
		while(GET_BIT(TIFR,TOV2)==0);
		
		CLR_BIT(TIFR,TOV2);
		
		overFlowCounter++;
	}
	
	overFlowCounter=0;
	TIMER0_stop();
}