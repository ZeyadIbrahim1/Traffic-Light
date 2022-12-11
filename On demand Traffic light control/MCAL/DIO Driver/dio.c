/*
 * dio.c
 *
 * Created: 11/5/2022 7:57:19 PM
 *  Author: eng_z
 */ 
#include "dio.h"
#include "../../Headers/macros.h"


//DIO PIN Direction Initialization
void DIO_init (uint8_t pinNumber, uint8_t portNumber , uint8_t direction )
	
	{
	switch(portNumber)
	{
		//******* PORT A  ********//
		case PORT_A:
		if (direction==OUTPUT)
		{
			SET_BIT(DDRA,pinNumber);
		}
		else if (direction==INPUT)
		{
			CLR_BIT(DDRA,pinNumber);
		}
		
		else
		{
			//error handling
		}
		break;
		
		//******* PORT B  ********//
		case PORT_B:
		if(direction==OUTPUT)
		{
			SET_BIT(DDRB,pinNumber);
		}
		
		else if (direction==INPUT)
		{
			CLR_BIT(DDRB,pinNumber);
		}
		else
		{
			//error handling
		}
		break;
		
		//******* PORT c  ********//
		case PORT_C:
		if (direction==OUTPUT)
		{
			SET_BIT(DDRC,pinNumber);
		}
		else if (direction==INPUT)
		{
			CLR_BIT(DDRC,pinNumber);
		}
		else
		{
			//error handling
		}
		break;

		//******* PORT D  ********//
	
		case PORT_D:
		if (direction==OUTPUT)
		{
			SET_BIT(DDRD,pinNumber);	
		}
		
		else if (direction==INPUT)
		{
			CLR_BIT(DDRD,pinNumber);
		}
		
		else
		{
			//error handling
		}
	
	}
	
	
	
	
	
}


//Write On DIO PIN
void DIO_write (uint8_t pinNumber ,uint8_t portNumber , uint8_t value )

	{
	switch (portNumber)
	{

		//******* PORT A  ********//

		case PORT_A:
		if (value==HIGH)
		{
			SET_BIT(PORTA,pinNumber);
		}
		else if (value==LOW)
		{
			CLR_BIT(PORTA,pinNumber);
		}
		
		else
		{
		//error handling	
		}
		break;
		
		//******* PORT B  ********//

		case PORT_B:
		if (value==HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else if (value==LOW)
		{
			CLR_BIT(PORTB,pinNumber);
		}
		
		else
		{
			//error handling
		}
		break;
		
		
		//******* PORT C  ********//

		case PORT_C:
		if (value==HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else if (value==LOW)
		{
			CLR_BIT(PORTC,pinNumber);
		}
		
		else
		{
			//error handling
		}
		break;
	
		//******* PORT D  ********//

		case PORT_D:
		if (value==HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else if (value==LOW)
		{
			CLR_BIT(PORTD,pinNumber);
		}
		
		else
		{
			//error handling
		}
		break;	
	}
	
	
}


//Toggle The DIO PIN
void DIO_toggle (uint8_t pinNumber , uint8_t portNumber )
	
	{

		switch(portNumber)
		{
			case PORT_A:
			TOGGLE_BIT(PORTA,pinNumber);
			break;
			
			case PORT_B:
			TOGGLE_BIT(PORTB,pinNumber);
			break;
			
			
			case PORT_C:
			TOGGLE_BIT(PORTC,pinNumber);
			break;
			
			
			case PORT_D:
			TOGGLE_BIT(PORTD,pinNumber);
			break;
			
			default:
			//error handling
			break;
			
			
			
		}
	
	}


//Read The DIO PIN value
void DIO_read (uint8_t pinNumber , uint8_t portNumber ,uint8_t *value)
	
	{
	switch(portNumber)
	{
		case PORT_A:
		*value =GET_BIT(PINA,pinNumber);
		break;
		
		case PORT_B:
		*value =GET_BIT(PINB,pinNumber);
		break;
		
		case PORT_C:
		*value= GET_BIT(PINC,pinNumber);
		break;
		
		case PORT_D:
		*value= GET_BIT(PIND,pinNumber);
		break;
		
		default:
		//error handling
		break;
	}
}

