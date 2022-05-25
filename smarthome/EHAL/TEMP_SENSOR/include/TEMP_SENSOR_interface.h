
/*
 * TEMP_SENSOR_interface.h
 *
 * Created: 2/7/2022 3:45:42 PM
 *  Author: Ebraheem El-Feshawy
 */ 
  #ifndef TEMP_SENSOR_INTERFACE_H
  #define TEMP_SENSOR_INTERFACE_H


  #include "TEMP_SENSOR_config.h"
  #include "TEMP_SENSOR_private.h"
 /***** SMART_HOME******/
#include "../../../MCAL/DIO/Header/Dio_Config.h"
#include "../../../MCAL/DIO/Header/Dio_Private.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"

  #include <util/delay.h>

  
uint8 TempSensor_Range(uint16 ADC_Value);
  #endif
