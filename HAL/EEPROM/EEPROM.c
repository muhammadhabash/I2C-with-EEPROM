#include "EEPROM.h"
#include "../../MCAL/I2C/I2C_interface.h"

void EEPROM_init(void)
{	
	I2C_masterInit();
}

void EEPROM_writeByte(uint8_t u8_dataWord, uint16_t u16_page, uint8_t u8_byte)
{	
	uint8_t u8_firstPacket, u8_secondPacket;
	u8_firstPacket  = (uint8_t)((u16_page - PAGE_SHIFTING_FACTOR) >> FIRST_PACKET_SHIFTING_FACTOR);
	u8_secondPacket = (uint8_t)(((u16_page - PAGE_SHIFTING_FACTOR) << SECOND_PACKET_SHIFTING_FACTOR) | (u8_byte));
	I2C_masterStart();
	I2C_masterWriteToAddress(EEPROM_ADDRESS);
	I2C_masterWriteData(u8_firstPacket);
	I2C_masterWriteData(u8_secondPacket);
	I2C_masterWriteData(u8_dataWord);
	I2C_masterStop();
} 

void EEPROM_writeString(uint8_t* pu8_buffer, uint16_t u16_page, uint8_t u8_byte)
{
	uint8_t u8_firstPacket, u8_secondPacket, u8_index = NULL;
	u8_firstPacket  = (uint8_t)((u16_page - PAGE_SHIFTING_FACTOR) >> FIRST_PACKET_SHIFTING_FACTOR);
	u8_secondPacket = (uint8_t)(((u16_page - PAGE_SHIFTING_FACTOR) << SECOND_PACKET_SHIFTING_FACTOR) | (u8_byte));
	I2C_masterStart();
	I2C_masterWriteToAddress(EEPROM_ADDRESS);
	I2C_masterWriteData(u8_firstPacket);
	I2C_masterWriteData(u8_secondPacket);
	do 
	{
		I2C_masterWriteData(pu8_buffer[u8_index]);
		u8_index++;
	} while(pu8_buffer[u8_index - INDEX_SHIFTING_FACTOR] != NULL_CHAR);
	I2C_masterStop();
}

void EEPROM_readByte(uint8_t* u8_receivedWord, uint16_t u16_page, uint8_t u8_byte)
{
	uint8_t u8_firstPacket, u8_secondPacket;
	u8_firstPacket  = (uint8_t)((u16_page - PAGE_SHIFTING_FACTOR) >> FIRST_PACKET_SHIFTING_FACTOR);
	u8_secondPacket = (uint8_t)(((u16_page - PAGE_SHIFTING_FACTOR) << SECOND_PACKET_SHIFTING_FACTOR) | (u8_byte));
	I2C_masterStart();
	I2C_masterWriteToAddress(EEPROM_ADDRESS);
	I2C_masterWriteData(u8_firstPacket);
	I2C_masterWriteData(u8_secondPacket);
	I2C_repeatedStart();
	I2C_masterReadFromAddress(EEPROM_ADDRESS);
	*(u8_receivedWord) = I2C_masterReadFinalData();
	I2C_masterStop();
}

void EEPROM_readString(uint8_t* pu8_buffer, uint8_t u8_buffSize, uint16_t u16_page, uint8_t u8_byte)
{
	uint8_t u8_firstPacket, u8_secondPacket, u8_dummy, u8_index = NULL;
	u8_firstPacket  = (uint8_t)((u16_page - PAGE_SHIFTING_FACTOR) >> FIRST_PACKET_SHIFTING_FACTOR);
	u8_secondPacket = (uint8_t)(((u16_page - PAGE_SHIFTING_FACTOR) << SECOND_PACKET_SHIFTING_FACTOR) | (u8_byte));
	I2C_masterStart();
	I2C_masterWriteToAddress(EEPROM_ADDRESS);
	I2C_masterWriteData(u8_firstPacket);
	I2C_masterWriteData(u8_secondPacket);
	I2C_repeatedStart();
	I2C_masterReadFromAddress(EEPROM_ADDRESS);
	do 
	{
		pu8_buffer[u8_index] = I2C_masterReadData();
		u8_index++;
	} while(pu8_buffer[u8_index - INDEX_SHIFTING_FACTOR] != NULL_CHAR && u8_index < u8_buffSize);
	u8_dummy = I2C_masterReadFinalData();
	I2C_masterStop();
}