/*
 * test.h
 *
 * Created: 12/5/2022 1:39:26 AM
 *  Author: eng_z
 */ 


#ifndef TEST_H_
#define TEST_H_



#define car_port	PORT_A
#define ped_port	PORT_B
#define button_port PORT_D


#define car_G_pin PIN_0 
#define car_Y_pin PIN_1
#define car_R_pin PIN_2

#define ped_G_pin PIN_0
#define ped_Y_pin PIN_1
#define ped_R_pin PIN_2

#define Button_pin PIN_2

#define car_G_s  0
#define car_Y1_s 1
#define car_R_s  2
#define car_Y2_s 3

/* T tick = Prescaler / FCPU
		 * FCPU = 1 000 000
		 t=1 micro
		 tmax  delay
		 * One Overflow 256 microsecond      ( PRESCALER 1)
		 * One Overflow  2 048 microsecond    ( PRESCALER 8 )
		 * One Overflow 16 384 microsecond   ( PRESCALER 64 ) 
		 * One Overflow  65 536 microsecond   ( PRESCALER 256 )
		 * One Overflow 262 144 microsecond  ( PRESCALER 1024 )
		 */
		
		/*
		using 256 prescaler 
		 1 000 000 / 65536 = 16 FULL Overflows  
		 * 1 000 000 % 65536 = 16960
		 * 65536 - 16960 = 48576
		 * 48576 / 256 = 185 (Initial Value )
		 */

#define TIMER0_initial_value 185
#define TIMER0_Num_of_overflows 16

#define TIMER2_initial_value 185
#define TIMER2_Num_of_overflows 16

#define pressed 1
#define released 0



void test_init(void);
void test_start(void);


#endif /* TEST_H_ */