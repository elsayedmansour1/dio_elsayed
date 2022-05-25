/*
 * Lcd_Private.h
 *
 *  Created on: Jan 16, 2022
 *      Author: kareem ashraf
 */

#ifndef EHAL_LCD_HEADER_LCD_PRIVATE_H_
#define EHAL_LCD_HEADER_LCD_PRIVATE_H_



/*****************************************************************/
/*****************************COMMANDS****************************/
/*****************************************************************/
#define ROW_ONE  			  (0x80)  // SET LOCATION ONE IN ROW ONE
#define ROW_TWO  			  (0xC0)  // SET LOCATION ONE IN ROW TWO

#define LINE_1_8BIT           (0x30)               //
#define LINE_2_8BIT           (0x38)
#define LINE_1_4BIT           (0x20)
#define LINE_2_4BIT           (0x28)
#define ENTRY_MODE_LEFT       (0x06)
#define ENTRY_MODE_RIGHT      (0x04)
#define DISPLY_OFF_CURSOR_OFF (0x08)
#define CURSOR_ON             (0x0E)
#define CURSOR_OFF            (0x0C)
#define BLINKING_CURSOR 	  (0x0F)
#define LEFT_SHIFT 		   	  (0x18)
#define RIGHT_SHIFT 		  (0x1C)
#define LEFT_CURSOR 		  (0x10)
#define RIGHT_CURSOR 		  (0x14)
#define CLEAR 				  (0x01)

#define CGRAM                 (0x40)


#define Heart                  Draw1




/*****************************************************************/
/****************************SET LCD *****************************/
/*****************************************************************/



/**********************LCD TYPE***********************************/
#define EIGHT_BIT 1
#define FOUR_BIT  2
/*////////////////////////////////////////////////////////////////*/


/**********************DIRECTION OF CURSOR ***********************/
#define LIFT    1
#define RIGHT   2
/*///////////////////////////////////////////////////////////////*/


/**********************MODE OF PIN  COMMAND OR DATA**********/
#define COMMAND_MODE      0
#define DATA_MODE         1
/*//////////////////////////////////////////////////////////////*/


/**********************WRITE OR READ DATA ***********************/
#define READ_DATA_FLAG    1 //SOME TIME CAN NOT SET THIS PIN
#define WRITE_DATA        0
/*///////////////////////////////////////////////////////////////*/


/****************ENABLE OR BISABLE PIN***************************/
#define ENABLE_LCD    1
#define DISABLE_LCD   0
/*///////////////////////////////////////////////////////////////*/



#endif /* EHAL_LCD_HEADER_LCD_PRIVATE_H_ */
