/*
 * Exercise4.c
 *
 *  Created on: Jun 21, 2017
 *  Author: Mohamed Tarek
 */

//al7al bta3y t7t//

#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>	/* Include Delay header file */
#include "../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../MCAL/DIO/Header/Dio_Private.h"
#include "../../MCAL/DIO/Header/Dio_Config.h"

#include "../../MCAL/TIMER1/TIMER_Interface.h"

void Servo_Init(void)
{
	DDRD_REG |= (1<<PIN_5);	/* Make OC1A pin as output */
}
void Sevro_Degre(uint8 Position)
{
	if(Position==0)
	{
		Set_Duty_Cycle_TIMER_1_A(3);	/* Set Servo shaft at 0° position by 1 ms pulse */
	}
	else if(Position==90)
	{
		Set_Duty_Cycle_TIMER_1_A(7.5);	/* Set Servo shaft at 90° position by 1.5 ms pulse */
	}
	else if(Position==180)
	{
		Set_Duty_Cycle_TIMER_1_A(12.5);	/* Set Servo shaft at 180° position by 2 ms pulse */
	}
}



