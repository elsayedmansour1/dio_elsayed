/*
 * _7_Seg_Interface.h
 *
 * Created: 1/13/2022 10:38:10 AM
 *  Author: kareem ashraf
 */ 


#ifndef Seven_SEG_INTERFACE_H_
#define Seven_SEG_INTERFACE_H_


#include "../../../SERVICE/Std_Types.h"
#include "Seven_Seg_Config.h"


void SevenSeg_VoidSetOffOrON(uint8 SevenSeg_VoidSetState);
void SevenSeg_VoidDisplyNumber(uint8 SevenSeg_uint8SetNumber);
void SevenSeg_VoidState(uint8 SevenSeg_uint8State);

void Seven_Segment_Pin_0(uint8 state);
void Seven_Segment_Pin_1(uint8 state);
void Seven_Segment_Pin_00(uint8 state);
void Seven_Segment_Pin_11(uint8 state);

void SevenSeg_VoidDisplyNumberByBCD(uint8 SevenSeg_uint8SetNumber);
void print_seven_seg_2_digit(uint8 Number);

void SpetialSeven7(uint8 number);
#endif /* 7_SEG_INTERFACE_H_ */
