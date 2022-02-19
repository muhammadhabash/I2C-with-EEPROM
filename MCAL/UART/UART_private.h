#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/**************************************/
/*            UCSA_R BITS             */
/**************************************/

#define MPCM (0)
#define U2X  (1)
#define PE   (2)
#define DOR  (3)
#define FE   (4)
#define UDRE (5)
#define TXC  (6)
#define RXC  (7)

/**************************************/
/*            UCSB_R BITS             */
/**************************************/

#define TXB8  (0)
#define RXB8  (1)
#define UCSZ2 (2)
#define TXEN  (3)
#define RXEN  (4)
#define UDRIE (5)
#define TXCIE (6)
#define RXCIE (7)

/**************************************/
/*             UCSC_R BITS            */
/**************************************/

#define UCPOL (0)
#define UCSZ0 (1)
#define UCSZ1 (2)
#define USBS  (3)
#define UPM0  (4)
#define UPM1  (5)
#define UMSEL (6)
#define URSEL (7)

#endif 