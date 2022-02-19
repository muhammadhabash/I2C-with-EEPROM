#include "./HAL/EEPROM/EEPROM.h"
#include "./MCAL/UART/UART_interface.h"
#include "./LIB/STD_types.h"
#include <string.h>
#include <math.h>

#define DATA_ARR_SIZE    (20)
#define COMMAND_ARR_SIZE (7)
#define PAGE_ARR_SIZE    (4)
#define BYTE_ARR_SIZE    (3)
#define EQUAL_STR        (0)

uint32_t u32extractNumbers(uint8_t* au8_buffer, uint8_t u8_buffSize)
{
	uint8_t u8_index = 0, u8_weight;
	uint32_t u32_number = 0;
	u8_weight = strlen((const char*)au8_buffer) - 1;
	while((u8_index < u8_buffSize) && (au8_buffer[u8_index]) != NULL_CHAR)
	{
		u32_number += ( (au8_buffer[u8_index] - '0' ) * pow(10,u8_weight) );
		u8_weight--;
		u8_index++;
	}
	return u32_number;
}

int main()
{
	uint8_t au8_command[COMMAND_ARR_SIZE];
	uint8_t au8_page[PAGE_ARR_SIZE];
	uint8_t au8_byte[BYTE_ARR_SIZE];
	uint8_t au8_data[DATA_ARR_SIZE];
	uint8_t u8_byte;
	uint16_t u16_page;
	EEPROM_init();
	UART_init();
	while(1)
	{
		UART_receiveString('\r',au8_command,COMMAND_ARR_SIZE);
		
		if (strcmp((const char*)au8_command,"WRITE") == EQUAL_STR)
		{
			UART_receiveString('\r',au8_page,PAGE_ARR_SIZE);
			UART_receiveString('\r',au8_byte,BYTE_ARR_SIZE);
			u16_page = u32extractNumbers(au8_page,PAGE_ARR_SIZE);
			u8_byte  = u32extractNumbers(au8_byte,BYTE_ARR_SIZE);
			UART_sendString((uint8_t*)"OK\r");
			UART_receiveString('\r',au8_data,DATA_ARR_SIZE);
			EEPROM_writeString(au8_data,u16_page,u8_byte);
			UART_sendString((uint8_t*)"OK\r");
			au8_page[0] = '\0';
			au8_byte[0] = '\0';
			au8_data[0] = '\0';
		}
		else if (strcmp((const char*)au8_command,"READ") == EQUAL_STR){
			UART_receiveString('\r',au8_page,PAGE_ARR_SIZE);
			UART_receiveString('\r',au8_byte,BYTE_ARR_SIZE);
			u16_page = u32extractNumbers(au8_page,PAGE_ARR_SIZE);
			u8_byte  = u32extractNumbers(au8_byte,BYTE_ARR_SIZE);
			UART_sendString((uint8_t*)"OK\r");
			EEPROM_readString(au8_data,DATA_ARR_SIZE,u16_page,u8_byte);
			UART_sendString(au8_data);
			au8_page[0] = '\0';
			au8_byte[0] = '\0';
			au8_data[0] = '\0';
		}
	}
}