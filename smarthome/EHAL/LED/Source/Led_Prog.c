/*
 * Led_Prog.c
 *
 * Created: 1/13/2022 1:56:34 PM
 *  Author: kareem ashraf
 */ 

#include <util/delay.h>
#include "../Header/Led_Interface.h"
#include "../Header/Led_Config.h"
#include "../Header/Led_Private.h"

#include "../../../SERVICE/Std_Types.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../LED/Header/Led_Interface.h"



/*******************SET DIERCTION OF PIN SHELL PORT , AND VALUE***************/
void LED_VoidInit(void)
{
	//DIO_VoidSetSpecialPortDir(LED_PORT,LED_Value);
	DIO_VoidSetPinDir(PORTA,PIN_2,OUTPUT);
	DIO_VoidSetPinDir(PORTA,PIN_3,OUTPUT);

}

/******************SET PIN VALUE HIGH TAKE LED COLLER**************************/
void LED_VoidOnLed(uint8 LED_VoidOnLed_Coller)
{
	DIO_VoidSetPinValue(LED_PORT,LED_VoidOnLed_Coller,HIGH) ;
}



/*****************SET PIN VALUE LOW TAKE LED COLLER**************************/
void LED_VoidOffLed(uint8 LED_VoidOffLed_Coller)
{
	DIO_VoidSetPinValue(LED_PORT,LED_VoidOffLed_Coller,LOW) ;
}


/*****************SET PIN VALUE ToggeL TAKE LED COLLER**************************/
void LED_VoidToggelLed(uint8 LED_VoidToggeLed_Coller)
{
	DIO_VoidSetToggelValue(LED_PORT ,LED_VoidToggeLed_Coller);
}


/*****************SET PIN VALUE Flash TAKE LED COLLER**************************/
void LED_VoidFlashLed(uint8 LED_VoidFlashLed_Coller)
{
	DIO_VoidSetPinValue(LED_PORT,LED_VoidFlashLed_Coller,HIGH) ;
	_delay_ms (500);
	DIO_VoidSetPinValue(LED_PORT,LED_VoidFlashLed_Coller,LOW) ;
	_delay_ms (500);
}


