/*
 * APP.c
 *
 *  Created on: May 24, 2022
 *      Author: kareem ashraf
 */




#include "../../EHAL/LCD/Header/Lcd_Interface.h"
#include "../../EHAL/KEYBAD/Header/Keybad_Interface.h"
#include "../../EHAL/BUZZER/BUZZER.h"
#include "../../EHAL/DC/DC.h"
#include "../../EHAL/SEVEN-SEGMINT/Header/Seven_Seg_Interface.h"
#include "../../EHAL/LDR/LDR.h"
#include "../../EHAL/SERVO/servo.h"

#include "../../EHAL/LED/Header/Led_Interface.h"
#include "../../EHAL/LED/Header/Led_Private.h"


#include "../../MCAL/ADC/ADC_INT.h"
#include "../../MCAL/WATCH_DOG/WDT_interface.h"


#include "../../SERVICE/Std_Types.h"

#include "../../MCAL/GIE/Header/GIE_Interface.h"
#include "../../MCAL/EXT_INTERRUPTS/include/INTERRUPTS_interface.h"

#include "APP.h"

int keybad_System(void);
uint8 TOKEYBAD =0 ;
void project(void)
{

	LCD_Init();
	LED_VoidInit();
	ADC_VidINIT();

	DC_Init();
	BUZZER_Init();
	GIE_VoidEnable();
	EXT_INT_Void_INT0_Init();
	Servo_Init();


	uint8 ADC_DataReturnA0 ; // Channel of ldr sensor
	uint8 ADC_DataReturnA1 ; // Channel of Temprither sensor

	LCD_Commands(0X80);
	CLCD_voidWriteNumber(10);
	uint8 temp ;
	while(1)
	{

		BUZZER_ON_OFF(ON);
		/**
		 * @braif keybad
		 */
		ADC_Select_Channal(1);
		ADC_Start_Conversion();
		ADC_Get_Result(&temp);
		LCD_Commands(0X80);
		LCD_Write_String("Brightness = ");
		//CLCD_voidWriteNumber(ADC_readChannel(0));

		LCD_Commands(0Xc0);
		LCD_Write_String("Temprechar = ");
		CLCD_voidWriteNumber(temp/2);


		/*if( (LDR_Range(ADC_readChannel(0))) == LOW)// LDR SENSOR
		{
			LED_VoidOffLed(LED_ONEA2);
			LED_VoidOffLed(LED_TWOA3);
		}
		else if((LDR_Range(ADC_readChannel(0))) == HIGH)
		{
			LED_VoidOnLed(LED_ONEA2);
			LED_VoidOffLed(LED_TWOA3);
		}
		else if((LDR_Range(ADC_readChannel(0))) == HIGHHIGH)
		{
			LED_VoidOnLed(LED_ONEA2);
			LED_VoidOnLed(LED_TWOA3);
		}*/




		if(temp > 30 )
		{
			DC_ON_OFF(ON);
		}
		if(temp > (30)+5 )
		{
			DC_ON_OFF(ON);
			BUZZER_ON_OFF(ON);
		}
		if (temp < 30)
		{
			DC_ON_OFF(OFF);
		}

		//ADC_DataReturnA1 = ADC_readChannel(1); //TEMP SENSOR
	}

}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	Lcd_Clear();
	keybad_System();
}




int keybad_System(void)
{
	LCD_Init();
	LED_VoidInit();
	DC_Init();
	Servo_Init();

	while(1)
	{
		uint8 Flag1=0 ;
		static Counter = 0 ;
		LCD_Commands(0X80);
		LCD_Write_String("Enter your PASS");

		uint16 PASS , Sum ;
		float32 DIGIT ;

		LCD_Commands(0XC0);
		PASS = KEYBAD_ReturnData();
		_delay_ms(250);

		CLCD_voidWriteNumber(PASS);


		if(PASS==61)
		{
			Lcd_Clear();
			LCD_Commands(0X80);
			LCD_Write_String("SET PASS 4 DIGIT");
			LCD_Commands(0Xc0);
			for(uint8 i=0 ; i<4 ; i++)
			{
				PASS = KEYBAD_ReturnData() ;
				_delay_ms(250);
				CLCD_voidWriteNumber(PASS);
				if(PASS>=0 && PASS<=9)
				{
					Sum = Sum*10 + PASS;
				}
				else
				{
					LCD_Commands(0X80);
					LCD_Write_String("Your Input Is Wrong");
				}
			}
			_delay_ms(1000);
			Lcd_Clear();
			LCD_Commands(0X80);
			CLCD_voidWriteNumber(Sum);

			DIGIT = Sum ;
			if(DIGIT>8000)
			{
				DIGIT /= 40 ;
				Flag1=1;
			}
			else if(DIGIT>5000&& DIGIT<8000)
			{
				DIGIT /= 36 ;
				Flag1=2;
			}
			else if(DIGIT>5000&& DIGIT<8000)
			{
				DIGIT /= 32 ;
				Flag1=3;
			}
			else if(DIGIT>2000&& DIGIT<5000)
			{
				DIGIT /= 20 ;
				Flag1=4;
			}
			else if(DIGIT>999 && DIGIT<2000)
			{
				DIGIT /= 10 ;
				Flag1=5;
			}

			/*
					_delay_ms(1000);
					Lcd_Clear();
					LCD_Commands(0Xc8);
					CLCD_voidWriteNumber(DIGIT);
			 */

			// EEPROM_writeByte(DIGIT);


			if(Flag1==1)
			{
				DIGIT *= 40 ;

			}
			else if(Flag1==2)
			{
				DIGIT *= 36 ;
			}
			else if(Flag1==3)
			{
				DIGIT *= 32 ;
			}
			else if(Flag1==4)
			{
				DIGIT *= 20 ;
			}
			else if(Flag1==5)
			{
				DIGIT *= 10 ;
			}

			break;

		}
		else if(PASS>=0 && PASS<=9 && PASS!=43 && PASS!=42 && PASS!=45 && PASS!=46 && PASS!=67 && PASS!=61 ) // Check is ok or nok
		{
			LCD_Commands(0XC1);
			Sum = PASS;
			for(uint8 i=0 ; i<3 ; i++)
			{
				PASS = KEYBAD_ReturnData() ;
				_delay_ms(250);
				CLCD_voidWriteNumber(PASS);
				if(PASS>=0 && PASS<=9)
				{
					Sum = Sum*10 + PASS;
				}
				else
				{
					LCD_Commands(0X80);
					LCD_Write_String("Your Input Is Wrong");
				}
			}
			if(Sum==9999)
			{
				Sevro_Degre(0);
				_delay_ms(500);
				Sevro_Degre(90);
				_delay_ms(500);
				Sevro_Degre(0);
				Counter=0;

				Lcd_Clear();
				LCD_Commands(0X80);
				LCD_Write_String("Right pass ......");
				_delay_ms(500);
				LCD_Commands(0XC0);
				LCD_Write_String("Right pass ......");
				Lcd_Clear();
			}
			else if(Sum!=9999)
			{
				Counter++;
				SpetialSeven7(Counter);
				LCD_Commands(0X80);
				LCD_Write_String("Wrong PASS ");
				LCD_Commands(0XC0);
				LCD_Write_String("TRY AGAIN ");

				_delay_ms(700);

				Lcd_Clear();

				LCD_Commands(0X80);
				LCD_Write_String("Enter your PASS");

			}

			if(Counter==0 || Counter==3)
			{
				if(Counter==3)
				{
					SpetialSeven7(0);
					Lcd_Clear();
					LCD_Commands(0X80);
					LCD_Commands(0XC0);
					LCD_Write_String("TRY LATER....... ");

					BUZZER_ON_OFF(ON);

					_delay_ms(700);

					Lcd_Clear();

					LCD_Commands(0X80);
					LCD_Write_String("Enter your PASS");
					break;

				}
			}
		}
	}



}

