
#include "../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../MCAL/DIO/Header/Dio_Config.h"
#include "../../MCAL/DIO/Header/Dio_Private.h"

#include "../../SERVICE/Std_Types.h"


#include "LDR.h"


uint16 LDR_Range(uint16 ADC_Value)
{
	uint16 ReturnValue ;
	if(ADC_Value< (325) )
	{
		ReturnValue = LOW;
	}
	else if(ADC_Value>(325) && (ADC_Value< (650) ))
	{
		ReturnValue = HIGH;
	}
	else
	{
		ReturnValue = HIGHHIGH;
	}

	return ReturnValue ;
}
