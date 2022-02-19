#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "I2C_private.h"

/********************************************/
/*            Options for PRESCALER         */
/********************************************/
/*  1 - PRESCALER_1                         */
/*  2 - PRESCALER_4                         */
/*  3 - PRESCALER_16                        */
/*  4 - PRESCALER_64                        */
/********************************************/

#define PRESCALER PRESCALER_1

/********************************************/
/*          Transmission Bit Rate           */
/********************************************/

#define BIT_RATE (0x46) // make SCL freq equal 50 kHZ

/*****************************************************/
/*            Protoypes for I2C Master               */
/*****************************************************/

void I2C_masterInit(void);
void I2C_masterStart(void);
void I2C_repeatedStart(void);
void I2C_masterWriteToAddress(uint8_t);
void I2C_masterReadFromAddress(uint8_t);
void I2C_masterWriteData(uint8_t);
uint8_t I2C_masterReadData(void);
uint8_t I2C_masterReadFinalData(void);
void I2C_masterStop(void);

/*****************************************************/
/*             Protoypes for I2C Slave               */
/*****************************************************/

void I2C_slaveInit(uint8_t u8_ownAddress);
void I2C_slaveAckRead(void);
uint8_t I2C_slaveRead(void);
void I2C_slaveAckWrite(void);
void I2C_slaveWrite(uint8_t u8_data);



#endif
