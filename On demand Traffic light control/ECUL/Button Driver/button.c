/*
 * button.c
 *
 * Created: 11/5/2022 7:57:44 PM
 *  Author: eng_z
 */ 

#include "button.h"

void BUTTON_init(uint8_t buttonPin , uint8_t buttonPort)
{
	
	DIO_init(buttonPin,buttonPort,INPUT);
}

void BuTTON_read(uint8_t buttonPin ,uint8_t buttonPort ,uint8_t *value)
{
	DIO_read(buttonPin,buttonPort,value);
}
