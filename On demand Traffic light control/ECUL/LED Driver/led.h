/*
 * led.h
 *
 * Created: 11/5/2022 7:56:19 PM
 *  Author: eng_z
 */ 
#include "../../MCAL/DIO Driver/dio.h"


#ifndef LED_H_
#define LED_H_
//led initialization 
void LED_init (uint8_t ledPin ,uint8_t ledPort);

//led on 
void LED_on (uint8_t ledPin , uint8_t ledPort );

//led off
void LED_off (uint8_t ledPin , uint8_t ledPort );

//led toggle
void LED_toggle (uint8_t ledPin , uint8_t ledPort );

#endif /* LED_H_ */