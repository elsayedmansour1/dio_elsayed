/*
 * Lcd_Interface.h
 *
 *  Created on: Jan 16, 2022
 *      Author: kareem ashraf
 */

#ifndef EHAL_LCD_HEADER_LCD_INTERFACE_H_
#define EHAL_LCD_HEADER_LCD_INTERFACE_H_

#include "../../../SERVICE/Std_Types.h"
#include "Lcd_Config.h"

void LCD_Write_String(uint8 Data[]);
void LCD_Init(void);
void LCD_Commands(uint8 Command);
void LCD_Write_Caracter(uint8 Caracter);
void LCD_Write_Number(uint32 Number);
void LCD_LOCATION_ROW_COLuM(uint8 Row , uint8 Colum);
void Lcd_Clear(void);
void SET_CGRAM(uint8 location , uint8 *Array);   // SET NEW DRAWING VALUE IN CGRAM
uint8 CLCD_voidWriteNumber(uint32 Copy_u8Number);

#endif /* EHAL_LCD_HEADER_LCD_INTERFACE_H_ */
