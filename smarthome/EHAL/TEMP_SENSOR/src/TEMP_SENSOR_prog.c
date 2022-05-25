
/*
 * TEMP_SENSOR_prog.c
 *
 * Created: 2/7/2022 3:46:13 PM
 *  Author: Ebraheem El-Feshawy
 */
#include "../include/TEMP_SENSOR_interface.h" 
#include "../../../SERVICE/Std_Types.h"




uint8 TempSensor_Range(uint16 ADC_Value)
{
	uint16 Temperature       = (uint16)(((uint32)ADC_Value*256UL)/1024);;

	   if(ADC_Value< (Temperature/2) )
		{
		Temperature = LOW;
		}
		else
		{
			Temperature = HIGH;
		}

	return Temperature ;
}
