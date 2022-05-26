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


#include "../../MCAL/ADC_G/adc.h"
#include "../../MCAL/WATCH_DOG/WDT_interface.h"


#include "../../SERVICE/Std_Types.h"

#include "../../MCAL/GIE/Header/GIE_Interface.h"
#include "../../MCAL/EXT_INTERRUPTS/include/INTERRUPTS_interface.h"

#include "../../EHAL/EXT_EEPROM/include/EXT_EEPROM.h"

#include "APP.h"

uint8 TOKEYBAD =0 ;
static uint8 Counter = 0 ;
uint8 temp ;

uint8 Address_EEBROM = 0 ;

uint8 flag=0 ;

void project(void)
{

	LCD_Init();
	LED_VoidInit();
	ADC_init();
	DC_Init();
	BUZZER_Init();
	GIE_VoidEnable();
	EXT_INT_Void_INT0_Init();
	Servo_Init();

	BUZZER_ON_OFF(OFF);

	LCD_Commands(0X80);
	CLCD_voidWriteNumber(10);

	while(1)
	{

		LCD_Commands(0X80);
		LCD_Write_String("Brightness = ");
		CLCD_voidWriteNumber(ADC_readChannel(0));

		LCD_Commands(0XC0);
		LCD_Write_String("Temprechar = ");
		CLCD_voidWriteNumber(ADC_readChannel(1)/2);


		LDR_System(LDR_Range(ADC_readChannel(0)));


		TEMP_Sytem(ADC_readChannel(1));

	}

}



/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	Lcd_Clear();
	keybad_System();
}


/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/

void keybad_System(void)
{
	static uint8 DATA ;
	EXT_INT_Void_INT0_Init();
	LCD_Init();
	LED_VoidInit();
	DC_Init();
	Servo_Init();
	BUZZER_Init();
	TWI_voidInitMaster(0);
	SpetialSeven7(0);
	while(1)
	{
		uint8 Flag1=0 ;

		LCD_Commands(0X80);
		LCD_Write_String("Enter your PASS");

		uint8 PASS , Sum ;
		float32 DIGIT ;

		LCD_Commands(0XC0);
		PASS = KEYBAD_ReturnData();
		_delay_ms(250);

		//CLCD_voidWriteNumber(PASS);
		LCD_Write_String("*");


		if(PASS==61)
		{
			Lcd_Clear();
			LCD_Commands(0X80);
			LCD_Write_String("SET PASS 4 DIGIT");
			LCD_Commands(0Xc0);
			PASS = 0 ;
			Sum = PASS ;
			Function_EntryNumber(&Sum,&PASS);

			if(Address_EEBROM<1)
			{
				EEPROM_writeByte(1,Sum);
				EEPROM_readByte(1,&DATA);
				Address_EEBROM++;
			}
			else
			{
				Lcd_Clear();
				LCD_Commands(0X80);
				LCD_Write_String("NO more one new PASS");
			}


			/*for(uint8 i=0 ; i<4 ; i++)
			{
				PASS = KEYBAD_ReturnData() ;
				_delay_ms(250);
				//CLCD_voidWriteNumber(PASS);
				LCD_Write_String("*");
				if(PASS>=0 && PASS<=9)
				{
					Sum = Sum*10 + PASS;
				}
				else
				{
					LCD_Commands(0X80);
					LCD_Write_String("Your Input Is Wrong");
				}
			}*/


			/*DIGIT = Sum ;
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
			 */
			break;

		}


		/***************************************************************************/
		/***************************************************************************/
		/***************************************************************************/
		else if(PASS>=0 && PASS<=9 && PASS!=43 && PASS!=42 && PASS!=45 && PASS!=46 && PASS!=67 && PASS!=61 ) // Check is ok or nok
		{
			// uint8 data ;
			LCD_Commands(0XC1);
			Sum = PASS;
			Function_EntryNumber2(&Sum,&PASS);



			/*for(uint8 i=0 ; i<Address_EEBROM ; i++)
			{

				if(Sum==EEPROM_readByte(0,&Data))
				{
					flag=1;
				}
				else
				{
					flag=2;
				}
				LCD_Commands(0xc8);
				LCD_Write_String("hhh");
			}*/




			if(Sum==DATA)
			{
				if( Right_PASS()==0 )
				{
					break;
				}
			}
			else if(Sum!=DATA)
			{
				Wrong_PASS();
			}

			if(FunctionCountM(Counter)==0)
			{
				break;
			}
		}
	}
}


/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/
int FunctionCountM(uint8 Count)
{
	uint8 INDEX ;
	if(Counter==0 || Counter==3)
	{
		if(Counter==3)
		{
			BUZZER_ON_OFF(ON);
			SpetialSeven7(0);
			Lcd_Clear();
			LCD_Commands(0X80);
			LCD_Commands(0XC0);
			LCD_Write_String("TRY LATER....... ");

			BUZZER_ON_OFF(ON);

			_delay_ms(1000);

			Lcd_Clear();
			BUZZER_ON_OFF(OFF);

			INDEX = 0 ;
		}
	}
	return INDEX ;
}


/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/


void LDR_System(uint16 ADC_Value)
{
	if(ADC_Value == LOW)// LDR SENSOR
	{
		LED_VoidOffLed(LED_ONEA2);
		LED_VoidOffLed(LED_TWOA3);
	}
	else if(ADC_Value == HIGH)
	{
		LED_VoidOnLed(LED_ONEA2);
		LED_VoidOffLed(LED_TWOA3);
	}
	else if(ADC_Value == HIGHHIGH)
	{
		LED_VoidOnLed(LED_ONEA2);
		LED_VoidOnLed(LED_TWOA3);
	}
}


/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/


void TEMP_Sytem(uint16 TEMP_Value)
{
	if(TEMP_Value > 30*2 )
	{
		DC_ON_OFF(ON);
	}
	if(TEMP_Value > (30*2)+5 )
	{
		DC_ON_OFF(ON);
		BUZZER_ON_OFF(ON);
	}
	if (TEMP_Value < 30*2)
	{
		DC_ON_OFF(OFF);
		BUZZER_ON_OFF(OFF);
	}
}



/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief function to open the door and close it ,when
 * @return ZERO
 */
uint8 Right_PASS(void)
{
	Sevro_Degre(90);   // Servo move to 90 degree , open the door
	_delay_ms(1000);
	Sevro_Degre(0);	   // Servo move to 0 degree , Close the door  after 1000 ms
	Counter=0;

	Lcd_Clear();
	LCD_Commands(0X80);
	LCD_Write_String("Right pass ......");
	_delay_ms(500);
	LCD_Commands(0XC0);
	LCD_Write_String("Right pass ......");
	Lcd_Clear();
	return ZERO ;
}


/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief function to count the wrong input max counter 3
 * @return ZERO
 */
uint8 Wrong_PASS(void)
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
	return ZERO ;
}




/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/
/**
 * @brief Function loop to entry 4 Digit of password and sumition it to one number
 *        and show the digit in LCD drow '*'
 * @param SUM
 * @param PASS
 */

void Function_EntryNumber(uint8 *SUM, uint8 *PASS)
{
	for(uint8 i=0 ; i<3 ; i++)
	{
		*PASS = KEYBAD_ReturnData() ;  /* Keybad return value in PASS */
		_delay_ms(250);
		//CLCD_voidWriteNumber(PASS);
		LCD_Write_String("*");
		if(*PASS>=0 && *PASS<=9)       /* Should password digit between 0 to 9 */
		{
			*SUM = (*SUM)*10 + *PASS;  /* Equation to change from 4 digit to one number and stor it in SUM */
		}
		else
		{
			LCD_Commands(0X80);
			LCD_Write_String("Your Input Is Wrong");
		}
	}
}




/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief Function loop to entry 4 Digit of password and sumition it to one number
 *        and show the digit in LCD drow '*' but lenght of loob 2 item only
 *        because user inter one digit in first code
 * @param SUM
 * @param PASS
 */
void Function_EntryNumber2(uint8 *SUM, uint8 *PASS)
{
	for(uint8 i=0 ; i<2 ; i++)
	{
		*PASS = KEYBAD_ReturnData() ;  /* Keybad return value in PASS */
		_delay_ms(250);
		//CLCD_voidWriteNumber(PASS);
		LCD_Write_String("*");
		if(*PASS>=0 && *PASS<=9)       /* Should password digit between 0 to 9 */
		{
			*SUM = (*SUM)*10 + *PASS;  /* Equation to change from 4 digit to one number and stor it in SUM */
		}
		else
		{
			LCD_Commands(0X80);
			LCD_Write_String("Your Input Is Wrong");
		}
	}
}
