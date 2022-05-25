/*
 * Keybad_Prog.c
 *
 *  Created on: Jan 18, 2022
 *      Author: kareem ashraf
 */


#include "../Header/Keybad_Interface.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../LCD/Header/Lcd_Interface.h"

#include "util/delay.h"

static uint8 KPD_u8adjust4x4KPD(uint8 KPD_u8CopyRowColNum);

static uint8 KPD_u8adjust4x4KPD(uint8 KPD_u8CopyRowColNum)
{
	switch (KPD_u8CopyRowColNum)
	{
		case 1	: return 7	  ; break;
		case 2	: return 8	  ; break;
		case 3	: return 9	  ; break;
		case 4	: return '/'  ; break; //0x2F
		case 5	: return 4	  ; break;
		case 6	: return 5	  ; break;
		case 7	: return 6	  ; break;
		case 8	: return 42  ; break; //0x2A
		case 9	: return 1	  ; break;
		case 10 : return 2	  ; break;
		case 11 : return 3	  ; break;
		case 12 : return '-'  ; break;//0x2D
		case 13 : return 'C'  ; break;
		case 14 : return 0    ; break;
		case 15 : return '='  ; break; //0x3D
		case 16 : return '+'  ; break; //0x2B
		default : return '%';
	}
}

uint8 KEYBAD_ReturnData(void)
{

	uint8 row , colume ;
	while(1)
	{

		for(colume = 0 ; colume<4 ; colume++)
		{
			DIO_VoidSetSpecialPortDir(PORT_USE1,(0b00010000<<colume)) ;
			DIO_VoidSetSpecialPortValue(PORT_USE1,(~(0b00010000<<colume))) ;

			for(row = 0 ; row<4 ; row++)
			{
				if(DIO_ReadPinValue(PORT_USE1,row) == 0)
				{
                    _delay_ms(30);
					return  KPD_u8adjust4x4KPD((row*4)+colume+1) ;
				}

			}
		}
	}
}





















