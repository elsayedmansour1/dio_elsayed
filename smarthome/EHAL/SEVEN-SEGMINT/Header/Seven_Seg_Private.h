/*
 * _7_Seg_Private.h
 *
 * Created: 1/13/2022 10:38:42 AM
 *  Author: kareem ashraf
 */ 


#ifndef Seven_SEG_PRIVATE_H_
#define Seven_SEG_PRIVATE_H_

#include "../Header/Seven_Seg_Interface.h"
#include "../Header/Seven_Seg_Config.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"


/***************************************ENABLE WHITCH MODE YOU USE*****************************************/
#define ANODE  1
#define CTHOD  2

#define BCD_OFF   3
#define BCD_ON    4


/*****************************************SET PORT*********************************************************/
#define ENABLE_PORT PORTD

/******************************************SET  TWO DIGIT OF SEGMENT***************************************/
#define ENABLE_ONES PIN_0
#define ENABLE_TENS PIN_1


/********************************************SET PIN OFF OR ON **********************************************/
#define OFF  1
#define ON   2


/*************************************************************************************************************/
/********************************************CHECK MODE OF SEVEN SEGMENT**************************************/
/*************************************************************************************************************/

#if(BCD_MODE == BCD_OFF)
    #if(Seven_SEG_State==CTHOD)

        #define Zero  0x3F
        #define One   0x06
        #define Two   0x5B
        #define Three 0x4F
        #define Four  0x66
        #define Five  0x6D
        #define Six   0x7D
        #define Seven 0x07
        #define Eight 0xFF
        #define Nine  0x6F




    #elif(Seven_SEG_State==ANODE)

        #define Zero  (~0x3F)
        #define One   (~0x06)
        #define Two   (~0x5B)
        #define Three (~0x4F)
        #define Four  (~0x66)
        #define Five  (~0x6D)
        #define Six   (~0x7D)
        #define Seven (~0x07)
        #define Eight (~0xFF)
        #define Nine  (~0x6F)

    #endif

#elif(BCD_MODE==BCD_ON)

#define Zero  (0b00001000)
#define One   (0b00011000)
#define Two   (0b00101000)
#define Three (0b00111000)
#define Four  (0x48)
#define Five  (0x58)
#define Six   (0x68)
#define Seven (0x78)
#define Eight (0x88)
#define Nine  (0x98)

#endif



#endif /* 7_SEG_PRIVATE_H_ */
