/*
 * _7_Segmant.c
 *
 * Created: 1/13/2022 10:31:10 AM
 *  Author: kareem ashraf
 */ 
#include <util/delay.h>
#include "../../../SERVICE/Bit_Math.h"
#include "../../../SERVICE/Std_Types.h"

#include "../../../MCAL/DIO/Header/Dio_Private.h"
#include "../../../MCAL/DIO/Header/Dio_Config.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"

#include "../Header/Seven_Seg_Private.h"
#include "../Header/Seven_Seg_Config.h"
#include "../Header/Seven_Seg_Interface.h"

/****************************************************************************************************************/
/*************************************CONTENER HAVE VALUE WILL SHOW IN SEVEN SGMENT******************************/
/****************************************************************************************************************/
const uint8 array[10]={ Zero , One , Two , Three , Four , Five , Six , Seven , Eight , Nine };



/****************************************************************************************************************/
/*************************************SEVEN SEGMENT INIT*********************************************************/
/****************************************************************************************************************/
void SevenSeg_VoidSetOffOrON(uint8 SevenSeg_VoidSetState)
{
	DIO_VoidSetPinDir(ENABLE_PORT,ENABLE_ONES , OUTPUT);
	DIO_VoidSetPinDir(ENABLE_PORT,ENABLE_TENS , OUTPUT);
	DDRC_REG = 0xFF;
	if (SevenSeg_VoidSetState == ON )
	{
		switch (Port_Used)
		{
		case 0:
			DIO_VoidSetAllPortDir(PORTA ,OUTPUT);
			break;

		case 1:
			DIO_VoidSetAllPortDir(PORTB ,OUTPUT);
			break;

		case 2:
			DIO_VoidSetAllPortDir(PORTC ,OUTPUT);
			break;

		case 3:

			DIO_VoidSetAllPortDir(PORTD ,OUTPUT);
			break;

		default:

			break;
		}
	}
	else if (SevenSeg_VoidSetState == OFF)
	{
		switch (Port_Used)
		{
		case 0:
			DIO_VoidSetAllPortDir(PORTA ,INPUT);
			break;

		case 1:
			DIO_VoidSetAllPortDir(PORTB ,INPUT);
			break;

		case 2:
			DIO_VoidSetAllPortDir(PORTC ,INPUT);
			break;

		case 3:
			DIO_VoidSetAllPortDir(PORTD ,INPUT);
			break;

		default:

			break;
		}
	}

}


void SevenSeg_VoidDisplyNumber(uint8 SevenSeg_uint8SetNumber)
{
	//DIO_VoidSetAllPortValue(Port_Used , array[SevenSeg_uint8SetNumber]) ;
	DIO_VoidSetSpecialPortValue(Port_Used,array[SevenSeg_uint8SetNumber]);
	/*
	uint8 Size = sizeof(array)/sizeof(array[0]);

	for(uint8 i=0 ; i<Size ; i++)
	{
		if(array[SevenSeg_uint8SetNumber] == array[i])
		{
			Port_Used_Reg = array[i] ;
		}
	}
	 */

	/*
	switch (SevenSeg_uint8SetNumber)
	{
	case 0:

		Port_Used_Reg  =  Zero     ;
		break;

	case 1:
		Port_Used_Reg  =  One     ;
		break;

	case 2:
		Port_Used_Reg  =  Two     ;
		break;

	case 3:
		Port_Used_Reg  =  Three     ;
		break;

	case 4:
		Port_Used_Reg   =  Four     ;
		break;

	case 5:
		Port_Used_Reg    =  Five     ;
		break;

	case 6:
		Port_Used_Reg    =  Six     ;
		break;

	case 7:
		Port_Used_Reg   =  Seven     ;
		break;

	case 8:
		Port_Used_Reg    =  Eight     ;
		break;

	case 9:
		Port_Used_Reg    =  Nine     ;
		break;

	default:

		break;
	}

	 */


}


void Seven_Segment_Pin_0(uint8 state)
{
	if(state == OFF)
	{
		//DIO_VoidSetPinDir(PORTD,PIN_0,INPUT);
		DIO_VoidSetPinValue(PORTD,PIN_0,LOW);
	}
	else if(state == ON)
	{
		//DIO_VoidSetPinDir(PORTD,PIN_0,OUTPUT);
		DIO_VoidSetPinValue(PORTD,PIN_0,HIGH);
	}
}

void Seven_Segment_Pin_1(uint8 state)
{

	if(state == OFF)
	{
		//DIO_VoidSetPinDir(PORTD,PIN_1,INPUT);
		DIO_VoidSetPinValue(PORTD,PIN_1,LOW);
	}
	else if(state == ON)
	{
		//DIO_VoidSetPinDir(PORTD,PIN_1,OUTPUT);
		DIO_VoidSetPinValue(PORTD,PIN_1,HIGH);
	}

}


void Seven_Segment_Pin_00(uint8 state)
{

	if(state == ON)
	{
		DIO_VoidSetPinDir(PORTD,PIN_0,OUTPUT);
		//DIO_VoidSetPinValue(PORTD,PIN_0,HIGH);
	}
	else if(state == OFF)
	{
		DIO_VoidSetPinDir(PORTD,PIN_0,INPUT);
		//DIO_VoidSetPinValue(PORTD,PIN_0,LOW);
	}


}

void Seven_Segment_Pin_11(uint8 state)
{



	if(state == ON)
	{
		DIO_VoidSetPinDir(PORTD,PIN_1,OUTPUT);
		//DIO_VoidSetPinValue(PORTD,PIN_1,HIGH);
	}
	else if(state == OFF)
	{
		DIO_VoidSetPinDir(PORTD,PIN_1,INPUT);
		//DIO_VoidSetPinValue(PORTD,PIN_1,LOW);
	}

}











void SevenSeg_VoidDisplyNumberByBCD(uint8 SevenSeg_uint8SetNumber)
{


	uint8 Size = sizeof(array)/sizeof(array[0]);

	for(uint8 i=0 ; i<Size ; i++)
	{
		if(array[SevenSeg_uint8SetNumber] == array[i])
		{
			//Port_Used_Reg = array[i] ;
		}
	}

}


void print_seven_seg_2_digit(uint8 Number)
{
	uint8 index1 = Number%10 ;
	DIO_VoidSetPinValue(PORTD,PIN_1,LOW);
	DIO_VoidSetPinValue(PORTD,PIN_0,HIGH);
	DIO_VoidSetSpecialPortValue(PORTC , array[index1]);
	_delay_ms(50);

	uint8 index2 = Number/10 ;
	DIO_VoidSetPinValue(PORTD,PIN_0,LOW);
	DIO_VoidSetPinValue(PORTD,PIN_1,HIGH);
	DIO_VoidSetSpecialPortValue(PORTC , array[index2]);
	_delay_ms(50);


}



void SpetialSeven7(uint8 number)
{

	DIO_VoidSetPinDir(ENABLE_PORT,ENABLE_ONES , OUTPUT);


	if(number==0)
	{

		DIO_VoidSetPinDir(PORTC,PIN_3,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_4,OUTPUT);

		DIO_VoidSetPinValue(PORTC,PIN_3,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_4,INPUT);

		DIO_VoidSetPinValue(PORTC,PIN_2,OUTPUT);
		DIO_VoidSetPinValue(PORTC,PIN_5,OUTPUT);
		DIO_VoidSetPinValue(PORTC,PIN_6,OUTPUT);
		DIO_VoidSetPinValue(PORTC,PIN_7,OUTPUT);

	}
	if(number==1)
	{

		DIO_VoidSetPinDir(PORTC,PIN_3,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_4,OUTPUT);

		DIO_VoidSetPinValue(PORTC,PIN_3,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_4,INPUT);

		DIO_VoidSetPinValue(PORTC,PIN_2,OUTPUT);
		DIO_VoidSetPinValue(PORTC,PIN_5,OUTPUT);
		DIO_VoidSetPinValue(PORTC,PIN_6,OUTPUT);
		DIO_VoidSetPinValue(PORTC,PIN_7,OUTPUT);

	}
	else if (number==2)
	{
		DIO_VoidSetPinDir(PORTC,PIN_2,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_4,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_5,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_6,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_7,OUTPUT);


		DIO_VoidSetPinValue(PORTC,PIN_3,OUTPUT);

		DIO_VoidSetPinValue(PORTC,PIN_2,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_4,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_5,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_6,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_7,INPUT);
	}
	else if (number==3)
	{
		DIO_VoidSetPinDir(PORTC,PIN_2,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_3,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_4,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_5,OUTPUT);
		DIO_VoidSetPinDir(PORTC,PIN_7,OUTPUT);


		DIO_VoidSetPinValue(PORTC,PIN_2,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_3,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_4,INPUT);
		DIO_VoidSetPinValue(PORTC,PIN_5,INPUT);

		DIO_VoidSetPinValue(PORTC,PIN_6,OUTPUT);

		DIO_VoidSetPinValue(PORTC,PIN_7,INPUT);
	}
}



