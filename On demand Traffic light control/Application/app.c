/*
 * app.c
 *
 * Created: 11/5/2022 7:57:53 PM
 *  Author: eng_z
 */ 



#include "app.h"
#include "../ECUL/Button Driver/button.h"
#include "../ECUL/LED Driver/led.h"
#include "../Headers/macros.h"


//counters initializations
uint8_t OF1_counter=0;
uint8_t OF2_counter=0;
uint8_t sec_counter=0;

//flags initializations
uint8_t car_leds	 =0;
uint8_t yellow_flag	 =0;
uint8_t button_flag	 =0;

void app_init()

{

	//led initialization
	DIO_init(car_G_pin,car_port,OUTPUT);
	DIO_init(car_Y_pin,car_port,OUTPUT);
	DIO_init(car_R_pin,car_port,OUTPUT);
		
	DIO_init(ped_G_pin,ped_port,OUTPUT);
	DIO_init(ped_Y_pin,ped_port,OUTPUT);
	DIO_init(ped_R_pin,ped_port,OUTPUT);
	
	//button initialization
	DIO_init(Button_pin,button_port,INPUT);


	

	
	//INTERRUPTS
	
	SET_BIT(SREG,GIE); // global enable
	
	SET_BIT(MCUCSR,ISC00);
	CLR_BIT(MCUCSR,ISC01);  //to differ btwn long and short press
	
	SET_BIT(GICR,INT0); //INT0 enable		

//overflow interrupts for timer0 and 2
	SET_BIT(TIMSK,TOIE0);
	SET_BIT(TIMSK,TOIE2); 
	

//timers 
TIMER0_init(NORMAL_MODE);
TIMER2_init(NORMAL_MODE);
TIMER0_start(PRESCALER_256,TIMER0_initial_value);


}



void app_start()
{
	
	while (1)
	{
		//normal loop green then yellow then red
		if (car_leds>car_Y2_s)
		{
			car_leds=car_G_s;
		}
		else
		{
			switch (car_leds)
			{
				case car_G_s:
				//first green ( car green led on rest is off)
				
			//	TIMER0_delay(PRESCALER_64,1,0.01);
				LED_on(car_G_pin,car_port);
				LED_off(car_Y_pin,car_port);
				LED_off(car_R_pin,car_port);
				
				
				LED_off(ped_G_pin,ped_port);
				LED_off(ped_Y_pin,ped_port);
				LED_on(ped_R_pin,ped_port);
				yellow_flag=0;
				
				break;
				
				case car_Y1_s: //secondly ''first yellow'' (both yellow
				
				yellow_flag=1;
				LED_off(car_G_pin,car_port);
	//			LED_off(car_Y_pin,car_port);
				LED_off(car_R_pin,car_port);
				
				LED_off(ped_G_pin,ped_port);
			//	LED_off(ped_Y_pin,ped_port);
				LED_off(ped_R_pin,ped_port);
				break;
				
				case car_R_s://thirdly red

				LED_off(car_G_pin,car_port);
				LED_off(car_Y_pin,car_port);
				LED_on(car_R_pin,car_port);
				
				LED_on(ped_G_pin,ped_port);
				LED_off(ped_Y_pin,ped_port);
				LED_off(ped_R_pin,ped_port);
				yellow_flag=0;
				break;
				
				case car_Y2_s://fourthly ''second yellow''
				
				yellow_flag=1;
				LED_off(car_G_pin,car_port);
		//		LED_off(car_Y_pin,car_port);
				LED_on(car_R_pin,car_port);
				
				LED_off(ped_G_pin,ped_port);
		//		LED_off(ped_Y_pin,ped_port);
				LED_off(ped_R_pin,ped_port);	
				break;
				
				default:
				//error handeling
				break;
				
			}
		}
		
		
		
	
	}
}


ISR(TIMER0_OVF)
{
	
	if (OF1_counter<TIMER0_Num_of_overflows)
	
	{
		OF1_counter++;
	}

	
	else if (OF1_counter>= TIMER0_Num_of_overflows)
	{
		sec_counter++;
		
		if (yellow_flag==1)
		{
			LED_toggle(car_Y_pin,car_port);
			LED_toggle(ped_Y_pin,ped_port);
		}
		
		
		if (sec_counter == 5)
		{
			car_leds++;
			sec_counter=0;
		}
		
		
		OF1_counter=0;	
	}
	 
}

//timer 2 overflow isr
 ISR(TIMER_2_OVF)
{
	OF2_counter++;
}


//interrupt to handel logical changes in rising edge and falling edge
 ISR(EXT_INT_0)
{
	//start button flag with 1
	button_flag++;

//first button will be pressed
	switch(button_flag)
	{	
		case pressed://rising edge
			TIMER2_start(PRESCALER_256,TIMER2_initial_value);
			break;	
	
	
		case released:
			//counter overflow check if more than 0.5 sec
			if (OF2_counter>TIMER2_Num_of_overflows)
			{
				//null 
			}
			else 
				{
					if (car_leds==car_G_s)
						{
							car_leds++;
							//reset counter
							sec_counter=0;
							OF1_counter=0;
						}
					else
						{
							//error handeling
						}
		
				}
		
	   //stop timer 2
	   TIMER2_stop();
	   //flag and counter reset
	   OF2_counter=0;
	   button_flag=0;
	   break;

	}
}

