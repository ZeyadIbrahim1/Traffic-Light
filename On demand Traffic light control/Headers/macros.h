/*
 * macros.h
 *
 * Created: 11/5/2022 6:45:52 PM
 *  Author: eng_z
 */ 


#ifndef MACROS_H_
#define MACROS_H_

//set bit  

#define SET_BIT(x,n)   ((x) |= ( 1 << (n)))

//clear the bit define CLR_BIT(p,n) ((p) &= ~((1) << (n)))
#define CLR_BIT(x,n)   ((x) &= ~((1) <<(n) ))

//get bit
#define GET_BIT(x,n)   (( (x) >> (n) ) & 1)

//toggle bit
#define TOGGLE_BIT(x,n) ((x) ^= ( 1 << (n)))



#endif /* MACROS_H_ */
