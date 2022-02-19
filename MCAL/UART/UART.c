#include "UART_interface.h"
#include "../../LIB/ATMEGA32.h"

void UART_init(void){
	
	UBRL_R  = BAUD_RATE;
	UCSB_R |= (1 << TXEN ) | (1 << RXEN);
	UCSC_R |= (1 << URSEL) | (1 << USBS) | (1 << UCSZ0) | (1 << UCSZ1); 
}

void UART_transmit(uint8_t u8_data){
	
	while (!(UCSA_R & (1 << UDRE)));
	UD_R = u8_data;
}

uint8_t UART_receive(void){
	
	while (!(UCSA_R & (1 << RXC)));
	
	return UD_R;
}

void UART_sendString(uint8_t* u8_string){
	
	uint8_t u8_index;
	for (u8_index = 0 ; u8_string[u8_index] != '\0' ; u8_index++){
		
		UART_transmit(u8_string[u8_index]);
	}
}

void UART_Flush(void){
	
	uint8_t u8_dummy;
	while ( UCSA_R & (1 << RXC) ){
		u8_dummy = UD_R;
	}
}

void UART_receiveString(uint8_t u8_terminator, uint8_t* u8_buffer, uint8_t u8_size){
	
	uint8_t u8_index = 0;
	while (u8_index < u8_size){
		
	    *(u8_buffer + u8_index) = UART_receive();
	    if (*(u8_buffer + u8_index) == u8_terminator){
			
		    *(u8_buffer + u8_index) = '\0';
			u8_index = u8_size;
	    }
	    else{
		    u8_index ++;
	    }
	}
}