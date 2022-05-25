/*********************************************************************/
/*********************************************************************/
/******** Author:    Ebraheem El-Feshawy    ***********************************/
/******** Component: EEPROM        ***********************************/
/******** Layer:     HAL           ***********************************/
/******** Version:   Student       ***********************************/
/*********************************************************************/
/*********************************************************************/
#include "../include/EXT_EEPROM.h"
#include "../../../MCAL/I2C/include/TWI_interface.h"


#include <util/delay.h>

#define SLA_W	0b10100000
#define SLA_R	0b10100001 
uint8 EEPROM_writeByte(uint16 u16addr, uint8 u8data)
{
	//u8 CombinedAddress = (SLA_W) | (u8) ( ( (u16addr) & (u16)(0x0300) )>> 7);
	
	uint8 Local_u8AddressPacket;
 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8)(u16addr >>8);
	/*if 24C02 :
	 * 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */
	/* Send the Start Bit */
	 TWI_SendStartCondition();
	/*check error status*/
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
	
	 TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);
	 /*check error status*/		 
    /* Send the required memory location address */
	 TWI_MasterWriteDataByte((uint8)u16addr);
	 /*check error status*/
    /* write byte to eeprom */
	 TWI_MasterWriteDataByte(u8data);
	 /*check error status*/
    /* Send the Stop Bit */
	 TWI_SendStopCondition();
	 /*Delay until the write cycle is finished*/
	 _delay_ms(10);
}

uint8 EEPROM_readByte(uint16 u16addr, uint8 *u8data)
{
	//u8 CombinedAddress = (SLA_R) | (u8) ( ( (u16addr) & (u16)(0x0300) )>> 7);
	
	uint8 Local_u8AddressPacket;
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8)(u16addr >>8);

	/*if 24C02 :
	 * 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	/* Send the Start Bit */
	   TWI_SendStartCondition();
	 /*check error status*/
       /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
	   TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);
	 /*check error status*/
        /* Send the required memory location address */
	   TWI_MasterWriteDataByte((uint8)u16addr);
	 /*check error status*/
    /* Send the Repeated Start Bit */
	   TWI_SendRepeatedStart();
	 /*check error status*/	
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
	   TWI_SendSlaveAddressWithRead(Local_u8AddressPacket);
	 /*check error status*/
    /* Read Byte from Memory without send ACK */
	   TWI_MasterReadDataByte(u8data);
	 /*check error status*/
    /* Send the Stop Bit */
	 TWI_SendStopCondition();
}
