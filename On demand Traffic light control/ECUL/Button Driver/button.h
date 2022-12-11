/*
 * button.h
 *
 * Created: 11/5/2022 7:56:30 PM
 *  Author: eng_z
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupts/interrupts.h"
#include "../../MCAL/Timer Driver/timer.h"


//button values
#define LOW  0
#define HIGH 1


//functions prototypes 

void BUTTON_init(uint8_t buttonPin , uint8_t buttonPort);

void BuTTON_read(uint8_t buttonPin ,uint8_t buttonPort ,uint8_t *value);


#endif /* BUTTON_H_ */