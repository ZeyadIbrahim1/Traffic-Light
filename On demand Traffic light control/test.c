/*
 * test.c
 *
 * Created: 12/5/2022 1:34:01 AM
 *  Author: eng_z
 */ 



#include "MCAL/DIO Driver/dio.h"
#include "MCAL/Timer Driver/timer.h"
#include "Headers/macros.h"

void test_init()

{

	DIO_init(PIN_0, PORT_A, OUTPUT);
	TIMER0_init(NORMAL_MODE);


}

void test_start()
{
	
	while (1)
	{
		
		DIO_write(PIN_0,PORT_A,HIGH);
		TIMER0_delay(PRESCALER_64,120,21);
		DIO_write(PIN_0,PORT_A,LOW);
		TIMER0_delay(PRESCALER_64,120,21);
		
		
		
		
		
	}
}