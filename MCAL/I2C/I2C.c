#include "../../LIB/ATMEGA32.h"
#include "I2C_private.h"
#include "I2C_interface.h"


void I2C_masterInit(void)
{                                                                                         
	TWBR = BIT_RATE;                    
	#if PRESCALER == PRESCALER_1             
	TWSR = (0 << TWPS1) | (0 << TWPS0);
	#elif PRESCALER == PRESCALER_4     
	TWSR = (0 << TWPS1) | (1 << TWPS0);
	#elif PRESCALER == PRESCALER_16   
	TWSR = (1 << TWPS1) | (0 << TWPS0);  
	#elif PRESCALER == PRESCALER_64   
	TWSR = (1 << TWPS1) | (1 << TWPS0);  
	#else                            
	#error "Invalid Prescaler"                                                                                
	#endif                                                                                        
}  

void I2C_masterStart(void)
{                                                                                           	
	TWCR = 0;                                                 
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));                   
	while( (TWSR & 0xF8) != MASTER_START);           
}                                                    
void I2C_repeatedStart(void)
{	
	TWCR= (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));                  
	while( (TWSR & 0xF8) != MASTER_REPEATED_START); 
}                                                   
		
void I2C_masterWriteToAddress(uint8_t u8_slaveAddress)
{                                     
	TWDR = (u8_slaveAddress << 1);                            
	TWCR = (1 << TWINT) | (1 << TWEN);                        
	while (!(TWCR & (1 << TWINT)));                           
	while ((TWSR & 0xF8) != SLAVE_ADDRESS_WRITE_TRANSMITTED)
	{
		I2C_repeatedStart();
		TWDR = (u8_slaveAddress << 1);
		TWCR = (1 << TWINT) | (1 << TWEN);
		while (!(TWCR & (1 << TWINT)));
	}
}                
			
void I2C_masterReadFromAddress(uint8_t u8_slaveAddress)
{                            
	TWDR = (u8_slaveAddress << 1);                                                                  
	TWDR |= (1 << 0);                                                            
	TWCR |= (1 << TWINT) | (1 << TWEN);                                                
	while (!(TWCR & (1 << TWINT)));                                  
	while ( (TWSR & 0xF8) != SLAVE_ADDRESS_READ_TRANSMITTED) 
	{
		I2C_repeatedStart();
		TWDR = (u8_slaveAddress << 1);
		TWDR |= (1 << 0);
		TWCR |= (1 << TWINT) | (1 << TWEN);
		while (!(TWCR & (1 << TWINT)));
	}
}                   

void I2C_masterWriteData(uint8_t u8_data)
{                                                           					
	TWDR = u8_data;                                                                                     
	TWCR = (1 << TWINT) | (1 << TWEN);                                            
	while (!(TWCR & (1 << TWINT)));                                                
	while ( (TWSR & 0xF8) != MASTER_WRITE_DATA_TRANSMITTED);
}
                                                           
uint8_t I2C_masterReadData(void)
{					
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);        
	while (!(TWCR & (1 << TWINT)));                                                     
	while ( (TWSR & 0xF8) != MASTER_READ_DATA_ACK);        
	return TWDR;                                           
}                                                              

uint8_t I2C_masterReadFinalData(void)
{                                                                                                        							
	TWCR = (1 << TWINT) | (1 << TWEN);                   
    while (!(TWCR & (1 << TWINT)));                       
	while ( (TWSR & 0xF8) != MASTER_READ_DATA_NACK);       
	return TWDR;                                           
}

void I2C_masterStop(void)
{                                                                        							
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO); 
	while (!(TWCR != (1 << TWSTO)));                 
}              
					
void I2C_slaveInit(uint8_t u8_ownAddress)
{                                                                                                								
	TWAR = (u8_ownAddress << 1); 
}                             
							
void I2C_slaveWrite(uint8_t u8_data)
{                                                      
	TWDR = u8_data;                                                                            
	TWCR = (1 << TWEN) | (1 << TWINT);                                         
	while  ((TWSR & 0xF8) != SLAVE_DATA_TRANSMITTED); 
}                                                   
								
void I2C_slaveAckWrite(void)
{                                                                                   										
	while((TWSR & 0xF8) != SLAVE_READ_FROM_ADDRESS_TRANSMITTED)
	{                                                                         
		TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWINT); 
		while  (!(TWCR & (1 << TWINT)));                 
	}                                                 
}                                                                                                                                        
									
uint8_t I2C_slaveRead(void)
{                                                                                                          											
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);      
	while  (!(TWCR & (1 << TWINT)));                      
	while  ((TWSR & 0xF8) != SLAVE_READ_DATA_TRANSMITTED); 
	return TWDR;                                           
}
											
void I2C_slaveAckRead(void)
{                                                                                
	while((TWSR & 0xF8) != SLAVE_WRITE_TO_ADDRESS_TRANSMITTED)
	{        									                                                                     
		TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWINT);        
		while  (!(TWCR & (1 << TWINT)));                        
	}                                                           
}