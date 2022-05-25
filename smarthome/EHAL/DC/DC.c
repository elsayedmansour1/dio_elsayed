
#include "../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../MCAL/DIO/Header/Dio_Config.h"
#include "../../MCAL/DIO/Header/Dio_Private.h"
#include "DC.h"

void DC_Init(void)
{
	DDRD_REG |= (1<<PIN_6);	 /* Make OC1A pin as output */
}
void DC_ON_OFF(uint8 State)
{
	if(State==ON)
	{
		DIO_VoidSetPinValue(PORTD,PIN_6,HIGH);
	}
	else if(State==OFF)
	{
		DIO_VoidSetPinValue(PORTD,PIN_6,LOW);
	}
}
