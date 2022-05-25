/*********************************************************************/
/*********************************************************************/
/******** Author:   Ebraheem El-Feshawy  *****************************/
/******** Component: EEPROM				 *****************************/
/******** Layer:     HAL				 *****************************/
/******** Version:   1.0				 *****************************/
/*********************************************************************/
/*********************************************************************/
#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "../../../SERVICE/Std_Types.h"
#define EEPROM_FIXED_ADDRESS		0b1010000
/*Choose the hardware connection option for A2 Pin: 0 if connected to gnd,
 * 													1 if connected to VCC
 * 																			*/
#define A2_CONNECTION			0
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR   0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);
 
#endif /* EXTERNAL_EEPROM_H_ */
