#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/*********************************************/
/*             Files Inclusions              */
/*********************************************/


/*********************************************/
/*                 TWC_R BITS                */
/*********************************************/

#define TWIE  (0)
#define TWEN  (2)
#define TWWC  (3)
#define TWSTO (4)
#define TWSTA (5)
#define TWEA  (6)
#define TWINT (7)

/*********************************************/
/*                 TWS_R BITS                */
/*********************************************/

#define TWPS0 (0)
#define TWPS1 (1)
#define TWS3  (3)
#define TWS4  (4)
#define TWS5  (5)
#define TWS6  (6)
#define TWS7  (7)

/*********************************************/
/*                 TWA_R BITS                */
/*********************************************/

#define TWGCE (0)

/*********************************************/
/*                SLC Prescaler              */
/*********************************************/

#define PRESCALER_1  (1)
#define PRESCALER_4  (4)
#define PRESCALER_16 (16)
#define PRESCALER_64 (64)

/*********************************************/
/*             TWS_R Status Codes            */
/*********************************************/

#define MASTER_START                        (0x08)
#define MASTER_REPEATED_START               (0x10)
#define SLAVE_ADDRESS_WRITE_TRANSMITTED     (0x18)
#define SLAVE_ADDRESS_WRITE_NTRANSMITTED    (0x20)
#define MASTER_WRITE_DATA_TRANSMITTED       (0x28)
#define SLAVE_ADDRESS_READ_TRANSMITTED      (0x40)
#define SLAVE_ADDRESS_READ_NTRANSMITTED     (0x48)
#define MASTER_READ_DATA_ACK                (0x50)
#define MASTER_READ_DATA_NACK               (0x58)
#define SLAVE_READ_DATA_TRANSMITTED         (0x80)
#define SLAVE_DATA_TRANSMITTED              (0xC8)
#define SLAVE_READ_FROM_ADDRESS_TRANSMITTED (0xA8)
#define SLAVE_WRITE_TO_ADDRESS_TRANSMITTED  (0x60)
#define ACK                                 (1   )
#define NACK                                (0   )

/*********************************************/
/*             I2C Events Status             */
/*********************************************/

#define START_SUCCESS           (50)
#define REPEATED_START_SUCCESS  (51)
#define MASTER_TRANSMIT_SUCCESS (52)
#define MASTER_STOP_SUCCESS     (53)


#endif
