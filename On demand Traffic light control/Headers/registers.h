/*
 * registers.h
 *
 * Created: 11/5/2022 6:46:36 PM
 *  Author: eng_z
 */ 
 

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "types.h"

// in this header file there will be all the micro controller registers



/************************************************************************/
/*	                      THE DIO REGISTERS                             */
/************************************************************************/


//PORTA
#define PORTA *((volatile uint8_t*)0x3B) //8 bit output register
#define DDRA  *((volatile uint8_t*)0x3A) //8 bit direction register
#define PINA  *((volatile uint8_t*)0x39) //8 bit input register


//PORTB
#define PORTB *((volatile uint8_t*)0x38) //8 bit output register
#define DDRB  *((volatile uint8_t*)0x37) //8 bit direction register
#define PINB  *((volatile uint8_t*)0x36) //8 bit input register

//PORTC
#define PORTC *((volatile uint8_t*)0x35) //8 bit output register
#define DDRC  *((volatile uint8_t*)0x34) //8 bit direction register
#define PINC  *((volatile uint8_t*)0x33) //8 bit input register

//PORTD
#define PORTD *((volatile uint8_t*)0x32) //8 bit output register
#define DDRD  *((volatile uint8_t*)0x31) //8 bit direction register
#define PIND  *((volatile uint8_t*)0x30) //8 bit input register


/************************************************************************/
/*							THE TIMER REGISTERS                         */
/************************************************************************/

#define TIFR *((volatile uint8_t*)0x58)   //Timer/Counter Interrupt Flag 8 bit Register.


//timer 0 registers (8 bit register)
#define TCCR0 *((volatile uint8_t*)0x53) //used to set up the Prescaler for timer
#define TCNT0 *((volatile uint8_t*)0x52) //hold and store the timer Count and it is incremented on every timer "tick"

//timer 2 registers (8 bit register)
#define TCCR2 *((volatile uint8_t*)0x45) //used to set up the Prescaler for timer
#define TCNT2 *((volatile uint8_t*)0x44) //hold and store the timer Count and it is incremented on every timer "tick"

//timer 1 registers (16 bit register )

#define TCCR1A  *((volatile uint8_t*)0x4F) //Timer/Counter1 Control Register A
#define TCCR1B  *((volatile uint8_t*)0x4E)
#define TCNT1H  *((volatile uint8_t*)0x4D)
#define TCNT1L  *((volatile uint8_t*)0x4C)


/************************************************************************/
/*						INTERUPTS REGISTERS                             */
/************************************************************************/

//The Interrupt Sense Control1 bits 1/0 (ISC11 and ISC10) in the MCU general Control Register
//(MCUCR) define whether the external interrupt is activated on rising and/or falling edge of the INT1 pin or level sensed.
// Activity on the pin will cause an interrupt request even if INT1 is configured as an output.
#define MCURC  *((volatile uint8_t*)0x55) 



//MCUCSR control and status register
//contains control bits for general mcu functions and provides information on which reset source caused an mcu reset
#define MCUCSR *((volatile uint8_t*)0x54)


//GICR used to enable INT0 and INT1 interrupts. 
//These interrupts correspond to the two physical pins PD3 and PD4 respectively
#define  GICR *((volatile uint8_t*)0x5B)

//GIFR You can operate on the external event in a polled fashion, without using an actual interrupt. That is the purpose of the GIFR register
// -- you can check it periodically to see if the event occured.
#define GIFR *((volatile uint8_t*)0x5A)



//SREG 
/*
It is the flag register in the AVR micro-controller.
It is a 8 – bit register. Only 6 of these 8 bits are called conditional flags.
They are C, Z, N, V, S, H.
 The value of these bits indicates some conditions
  that result after the execution of an instruction.Sep*/
#define SREG *((volatile uint8_t*)0x5F)


//timsk The Timer/Counter Interrupt Mask Register - TIMSK. Bit. 7.
#define TIMSK *((volatile uint8_t*)0x59)


#endif /* REGISTERS_H_ */