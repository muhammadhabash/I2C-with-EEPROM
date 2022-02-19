#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../LIB/STD_types.h"

#define EEPROM_ADDRESS                (0x50)
#define FIRST_PACKET_SHIFTING_FACTOR  (2)
#define SECOND_PACKET_SHIFTING_FACTOR (6)
#define PAGE_SHIFTING_FACTOR          (1)
#define INDEX_SHIFTING_FACTOR         (1)

void EEPROM_init(void);
void EEPROM_writeByte(uint8_t u8_dataWord, uint16_t u16_page, uint8_t u8_byte);
void EEPROM_writeString(uint8_t* pu8_buffer, uint16_t u16_page, uint8_t u8_byte);
void EEPROM_readByte(uint8_t* u8_receivedWord, uint16_t u16_page, uint8_t u8_byte);
void EEPROM_readString(uint8_t* pu8_buffer, uint8_t u8_buffSize, uint16_t u16_page, uint8_t u8_byte);



#endif 