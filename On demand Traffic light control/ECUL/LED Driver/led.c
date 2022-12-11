/*
 * led.c
 *
 * Created: 11/5/2022 7:57:29 PM
 *  Author: eng_z
 */ 
#include "led.h"
void LED_init (uint8_t ledPin ,uint8_t ledPort)
{
	DIO_init(ledPin,ledPort,OUTPUT);
}

//led on
void LED_on (uint8_t ledPin , uint8_t ledPort )
{
	DIO_write(ledPin,ledPort,HIGH);
	
}

//led off
void LED_off (uint8_t ledPin , uint8_t ledPort )
{
	DIO_write(ledPin,ledPort,LOW);
}

//led toggle
void LED_toggle (uint8_t ledPin , uint8_t ledPort )
{
	DIO_toggle(ledPin,ledPort);
}