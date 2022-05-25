


#include "../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../MCAL/DIO/Header/Dio_Config.h"
#include "../../MCAL/DIO/Header/Dio_Private.h"
#include "BUZZER.h"

void BUZZER_Init(void)
{
	DDRD_REG |= (1<<PIN_7);	 /* Make OC1A pin as output */
}
void BUZZER_ON_OFF(uint8 State)
{
	if(State==ON)
	{
		DIO_VoidSetPinValue(PORTD,PIN_7,HIGH);
	}
	else if(State==OFF)
	{
		DIO_VoidSetPinValue(PORTD,PIN_7,LOW);
	}
}
