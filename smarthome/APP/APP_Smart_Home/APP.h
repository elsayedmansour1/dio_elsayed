/*
 * APP.h
 *
 *  Created on: May 24, 2022
 *      Author: kareem ashraf
 */

#ifndef APP_APP_SMART_HOME_APP_H_
#define APP_APP_SMART_HOME_APP_H_

#include "../../SERVICE/Std_Types.h"
void project(void);
void keybad_System(void);
int FunctionCountM(uint8 Count);
void LDR_System(uint16 ADC_Value);
void TEMP_Sytem(uint16 TEMP_Value);

void Function_EntryNumber(uint8 *SUM, uint8 *PASS);
void Function_EntryNumber2(uint8 *SUM, uint8 *PASS);

uint8 Right_PASS(void);
uint8 Wrong_PASS(void);


#endif /* APP_APP_SMART_HOME_APP_H_ */
