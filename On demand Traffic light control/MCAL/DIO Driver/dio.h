/*
 * dio.h
 *
 * Created: 11/5/2022 7:55:39 PM
 *  Author: eng_z
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Headers/registers.h"
#include "../../Headers/types.h"

//all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// PIN Macros
#define PIN_0  0 
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7

//direction defines
#define INPUT  0
#define OUTPUT 1

// value defines
#define LOW   0
#define HIGH  1


/************************************************************************/
/*                       ALL Driver Function Prototypes                 */
/************************************************************************/ 

//DIO PIN Direction Initialization 
void DIO_init (uint8_t pinNumber, uint8_t portNumber , uint8_t direction );


//Write On DIO PIN
void DIO_write (uint8_t pinNumber ,uint8_t portNumber , uint8_t value );


//Toggle The DIO PIN 
void DIO_toggle (uint8_t pinNumber , uint8_t portNumber ); //toggle


//Read The DIO PIN value 
void DIO_read (uint8_t pinNumber , uint8_t portNumber ,uint8_t *value);






#endif /* DIO_H_ */