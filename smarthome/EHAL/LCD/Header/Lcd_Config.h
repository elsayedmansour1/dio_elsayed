/*
 * Lcd_Config.h
 *
 *  Created on: Jan 16, 2022
 *      Author: kareem ashraf
 */

#ifndef EHAL_LCD_HEADER_LCD_CONFIG_H_
#define EHAL_LCD_HEADER_LCD_CONFIG_H_

#include "../../../SERVICE/Std_Types.h"
#include "../../../SERVICE/Bit_Math.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../../MCAL/DIO/Header/Dio_Private.h"
#include "Lcd_Private.h"


#define LCD_TYPE            FOUR_BIT
#define DIRECTON_CURSOR     LEFT

#if(LCD_TYPE == FOUR_BIT)

	#define PORT_USED1        PORTA //use pin 4,5,6,7
	#define PORT_USED2        PORTD //use pin 1,2,3
	#define PIN_USED_IN_PORT1  0xF0 //THIS VALUE **PIN 4,5,6,7 IN PORTA
    #define PIN_USED_IN_PORT2  0X1A //** AND **PIN 1,2,3 IN PORTB**//

#elif(LCD_TYPE == EIGHT_BIT)

	#define PORT_USED1        PORTA  //use pin 0,1,2,3,4,5,6,7
	#define PORT_USED2        PORTB  //use pin 1,2,3
	#define PIN_USED_IN_PORT1  0xFF  //THIS VALUE **PIN 0,1,2,3,4,5,6,7 IN PORTA//
    #define PIN_USED_IN_PORT2  0x07   //** AND **PIN 1,2,3 IN PORTB**//

#endif


#define REGISTER_SELECT(value) if(value==0)Clr_Bit(PORTD_REG,PIN_1); else Set_Bit(PORTD_REG,PIN_1);
#define READ_WRIT(value) if(value==0)Clr_Bit(PORTD_REG,PIN_3); else Set_Bit(PORTD_REG,PIN_3);
#define ENABLEMODE(value) if(value==0)Clr_Bit(PORTD_REG,PIN_4); else Set_Bit(PORTD_REG,PIN_4);

#define PIN44(value) if(value==0)Clr_Bit(PORTA_REG,PIN_4); else Set_Bit(PORTA_REG,PIN_4);
#define PIN55(value) if(value==0)Clr_Bit(PORTA_REG,PIN_5); else Set_Bit(PORTA_REG,PIN_5);
#define PIN66(value) if(value==0)Clr_Bit(PORTA_REG,PIN_6); else Set_Bit(PORTA_REG,PIN_6);
#define PIN77(value) if(value==0)Clr_Bit(PORTA_REG,PIN_7); else Set_Bit(PORTA_REG,PIN_7);




#endif /* EHAL_LCD_HEADER_LCD_CONFIG_H_ */
