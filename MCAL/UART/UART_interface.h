#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "UART_private.h"
#include "../../LIB/STD_types.h"

#define BAUD_RATE (51)

/**************************************/
/*              UART APIs             */
/**************************************/

void UART_init(void);
void UART_transmit(uint8_t u8_data);
uint8_t UART_receive(void);
void UART_sendString(uint8_t* u8_string);
void UART_Flush(void);
void UART_receiveString(uint8_t u8_terminator, uint8_t* u8_buffer, uint8_t u8_size);

#endif 