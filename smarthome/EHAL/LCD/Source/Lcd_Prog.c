/*
 * Lcd_Prog.c
 *
 *  Created on: Jan 16, 2022
 *      Author: kareem ashraf
 */
#include "../../../MCAL/DIO/Header/Dio_Interface.h"
#include "util/delay.h"
#include "../Header/Lcd_Config.h"
#include "../Header/Lcd_Interface.h"
#include "../Header/Lcd_Private.h"
#include "../../../SERVICE/Bit_Math.h"




/************************************************************************************/
/************************LCD INITALICATION DDIRECTION OF PIN*************************/
/************************************************************************************/
void LCD_Init(void)
{
#if(LCD_TYPE == EIGHT_BIT)

	REGISTER_SELECT(DATA_MODE);
	READ_WRIT(1);
    ENABLEMODE(EIGHT_BIT);
                              //PORTD      // 0,1,2,3,4,5,6,7 PINS
	DIO_VoidSetSpecialPortDir(PORT_USED1,PIN_USED_IN_PORT1);
	                          //PORTC      // 1,2,3           PINS
	DIO_VoidSetSpecialPortDir(PORT_USED2,PIN_USED_IN_PORT2);
	_delay_ms(30);


	LCD_Commands(0x3);
		LCD_Commands(0x2);
		LCD_Commands(DISPLY_OFF_CURSOR_OFF);
	LCD_Commands(LINE_2_8BIT);
	LCD_Commands(CURSOR_OFF);
	LCD_Commands(CLEAR);
	_delay_ms(20);


#if DIRECTON_CURSOR == LIFT
	LCD_Commands(ENTRY_MODE_LEFT);

#elif DIRECTON_CURSOR == RIGHT
	 LCD_Commands(ENTRY_MODE_RIGHT);

#endif


#elif(LCD_TYPE == FOUR_BIT)
	DIO_VoidSetSpecialPortDir(PORT_USED1,PIN_USED_IN_PORT1);
	DIO_VoidSetSpecialPortDir(PORT_USED2,PIN_USED_IN_PORT2);
	LCD_Commands(0x3);
	LCD_Commands(0x2);
	LCD_Commands(DISPLY_OFF_CURSOR_OFF);
	LCD_Commands(LINE_2_4BIT);
	LCD_Commands(CLEAR);
	LCD_Commands(CURSOR_OFF);

#if DIRECTON_CURSOR == LIFT    //USE LIFT WHEN WRITE ENGLITH

	LCD_Commands(ENTRY_MODE_LEFT);

#elif DIRECTON_CURSOR ==RIGHT  //USE LIFT WHEN WRITE ARABIC
	LCD_Commands(ENTRY_MODE_RIGHT);
#endif
	_delay_ms(20);

#endif

}
//////////////////////////////////////////////////////////////////////////////////////




/************************************************************************************/
/************************SLECT LOCATION BY ROW AND COLUM*****************************/
/************************************************************************************/

void LCD_LOCATION_ROW_COLuM(uint8 Row , uint8 Colum)  // ROW 1 OR 2 ********* 16 COLUME ********
{
	switch(Row)
	{
	case 1:
		LCD_Commands(ROW_ONE + Colum); //0x82
		break;
	case 2:
		LCD_Commands(ROW_TWO + Colum);
		break;
	default:
		break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////




/************************************************************************************/
/************************SPECAL COMMAND USE WITH LCD*********************************/
/************************************************************************************/

void LCD_Commands(uint8 Command)
{
#if(LCD_TYPE == EIGHT_BIT)

	//DIO_VoidSetSpecialPortValue(PORT_USED1,PIN_USED_IN_PORT1);
	REGISTER_SELECT(COMMAND_MODE);
	READ_WRIT(WRITE_DATA);

	ENABLEMODE(ENABLE_LCD);
	_delay_ms(1);
	DIO_VoidSetSpecialPortValue(PORT_USED1,Command);
	_delay_ms(1);
	ENABLEMODE(DISABLE_LCD);
	_delay_ms(1);



#elif(LCD_TYPE == FOUR_BIT)
	REGISTER_SELECT(COMMAND_MODE);         // Command mode

	PIN44(DIO_ReadSegmentOfAddress(Command ,PIN_4 ));
	PIN55(DIO_ReadSegmentOfAddress(Command ,PIN_5 ));
	PIN66(DIO_ReadSegmentOfAddress(Command ,PIN_6 ));
	PIN77(DIO_ReadSegmentOfAddress(Command ,PIN_7 ));

	ENABLEMODE(ENABLE_LCD);                // ENABLE_LCD
	_delay_ms(2);
	ENABLEMODE(DISABLE_LCD);               // DISABLE_LCD

	PIN44(DIO_ReadSegmentOfAddress(Command ,PIN_0 ));
	PIN55(DIO_ReadSegmentOfAddress(Command ,PIN_1 ));
	PIN66(DIO_ReadSegmentOfAddress(Command ,PIN_2 ));
	PIN77(DIO_ReadSegmentOfAddress(Command ,PIN_3 ));

	ENABLEMODE(ENABLE_LCD);					// ENABLE_LCD
	_delay_ms(2);
	ENABLEMODE(DISABLE_LCD);  				// DISABLE_LCD
#endif

}
/////////////////////////////////////////////////////////////////////////////////////





/************************************************************************************/
/************************DISPLY CARACTER ON LCD**************************************/
/************************************************************************************/

void LCD_Write_Caracter(uint8 Caracter)
{
#if(LCD_TYPE == EIGHT_BIT)

	    REGISTER_SELECT(DATA_MODE);
		READ_WRIT(WRITE_DATA);
		ENABLEMODE(ENABLE_LCD);
		_delay_ms(1);
		DIO_VoidSetSpecialPortValue(PORT_USED1,Caracter);
		_delay_ms(1);
		ENABLEMODE(DISABLE_LCD);
		_delay_ms(1);


#elif(LCD_TYPE == FOUR_BIT)

	REGISTER_SELECT(DATA_MODE);           // DATA_MODE

	PIN44(DIO_ReadSegmentOfAddress(Caracter ,PIN_4 ));
	PIN55(DIO_ReadSegmentOfAddress(Caracter ,PIN_5 ));
	PIN66(DIO_ReadSegmentOfAddress(Caracter ,PIN_6 ));
	PIN77(DIO_ReadSegmentOfAddress(Caracter ,PIN_7 ));

	ENABLEMODE(ENABLE_LCD);                // ENABLE_LCD
	_delay_ms(2);
	ENABLEMODE(DISABLE_LCD);               // DISABLE_LCD

	PIN44(DIO_ReadSegmentOfAddress(Caracter ,PIN_0 ));
	PIN55(DIO_ReadSegmentOfAddress(Caracter ,PIN_1 ));
	PIN66(DIO_ReadSegmentOfAddress(Caracter ,PIN_2 ));
	PIN77(DIO_ReadSegmentOfAddress(Caracter ,PIN_3 ));

	ENABLEMODE(ENABLE_LCD);					// ENABLE_LCD
	_delay_ms(2);
	ENABLEMODE(DISABLE_LCD);
  #endif// DISABLE_LCD
}
//////////////////////////////////////////////////////////////////////////////////////




/************************************************************************************/
/*****************************DISPLY STRING ON LCD***********************************/
/************************************************************************************/

void LCD_Write_String(uint8 Data[])
{
	//uint8 Size = sizeof(Data)/sizeof(Data[0]);
	for(uint8 i=0 ; Data[i]!='\0' ; i++)
	{
		LCD_Write_Caracter(Data[i]);
	}

}
//////////////////////////////////////////////////////////////////////////////////////


/*****************************CLEAR ALL LCD****************************************/
void Lcd_Clear(void)
{
	LCD_Commands(CLEAR);
}

/*/////////////////////////////////////////////////////////////////////////////////*/



/**********************Saving New Drowing Varable In CGRAM ON LCD****************/
void SET_CGRAM(uint8 location , uint8 *Array)
{
	LCD_Commands(CGRAM+(location*8));

	for(uint8 i=0 ; i<8 ; i++)
	{
		LCD_Write_Caracter(Array[i]);
		_delay_ms(2);
	}
	// LCD_Commands(0x80);
	_delay_ms(20);
}
/////////////////////////////////////////////////////////////////////////////////////



/************************************************************************************/
/*****************************DISPLY NUMBER ON LCD***********************************/
/************************************************************************************/

void LCD_Write_Number(uint32 Number)
{

	sint8 txt[10] = {0};
	sint8 i = 0;
	if(Number == 0)
	{
		LCD_Write_Caracter('0');
		return;
	}

	for (i = 0; Number != 0; i++ )
	{
		txt[i] = Number%10 + 48;    // 25%10  == 5                (48+5 (Ascie code) =  5
		Number = Number  / 10 ;     // 25/10  == 2.5
	}

	i--;
	while(i >= 0)
	{
		LCD_Write_Caracter(txt[i]);  //25
		i--;
	}
	//return txt ;
}


/*

uint8 Send_CommandFourBit(uint8 Address)
{
	uint8 array[4];
	for(uint8 i=0 ; i<4 ; i++) //0b11001010
	{
		array[i] = Get_Bit(Address,i);
	}

	for(uint8 i=0 ; i<4 ; i++)
	{
		if(array[i]==1)
		{
			DIO_VoidSetPinValue(PORTA , i+4 , HIGH) ;
		}
		else
		{
			DIO_VoidSetPinValue(PORTA , i+4 , LOW) ;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////


	for(uint8 i=4 ; i<8 ; i++)
		{
			array[i-4] = Get_Bit(Address,i);
		}

		for(uint8 i=0 ; i<4 ; i++)
		{
			if(array[i]==1)
			{
				DIO_VoidSetPinValue(PORTA , i+4 , HIGH) ;
			}
			else
			{
				DIO_VoidSetPinValue(PORTA , i+4 , LOW) ;
			}
		}

}



 */





uint8 CLCD_voidWriteNumber(uint32 Copy_u8Number)
{

	uint8 Local_u8SplitNum;
		uint8 Local_u8Counter=0;
		uint8 Local_u8Array[10];
		uint8 returnnuber =  Copy_u8Number ;
		if(Copy_u8Number == 0)
		{
			LCD_Write_Caracter(Copy_u8Number+0x30);
		}
		else
		{
			while(Copy_u8Number >0)
			{
				Local_u8SplitNum = (Copy_u8Number % 10);
				Local_u8Array[Local_u8Counter]=Local_u8SplitNum;
				Copy_u8Number = Copy_u8Number/10;
				Local_u8Counter++;
			}
			for(Local_u8Counter=Local_u8Counter-1 ; Local_u8Counter>=0 ; Local_u8Counter--)
			{
				LCD_Write_Caracter(Local_u8Array[Local_u8Counter]+0x30);
				if(Local_u8Counter == 0)
				{
					break;
				}
			}

		}
		return returnnuber ;
}


























