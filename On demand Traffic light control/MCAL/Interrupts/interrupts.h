/*
 * interrupts.h
 *
 * Created: 11/5/2022 6:46:15 PM
 *  Author: eng_z
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/************************************************************************/
/*						    Interrupt Bits Macros			    		*/
/************************************************************************/

// MCUCR
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

// MCUCSR
#define ISC2 6

// GICR
#define INT2 5
#define INT0 6
#define INT1 7

// GIFR
#define INTF2 5
#define INTF0 6
#define INTF1 7

// SREG
#define GIE 7



/************************************************************************/
/*							Interrupts	Vectors				     		*/
/************************************************************************/

#define EXT_INT_0		__vector_1
#define TIMER_2_OVF		__vector_5
#define TIMER0_OVF		__vector_11



#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)


#endif /* INTERRUPTS_H_ */