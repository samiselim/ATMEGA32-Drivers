/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 01 JAN 2021 							*/
/****************************************************** */


#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

#include "MACRO_FUNCTIONS.h"

#define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
    void vector (void)


#define UART_RX_VECTOR	__vector_13

#define UDR		_MMIO_BYTE(0x0C + __SFR_OFFSET)
#define UBRRH	_MMIO_BYTE(0x20 + __SFR_OFFSET)

#define UCSRA	_MMIO_BYTE(0x0B + __SFR_OFFSET)

#define RXC		7
#define TXC		6
#define UDRE 	5
#define FE		4
#define DOR		3
#define PE 		2
#define U2X 	1
#define MPCM	0

#define UCSRB	_MMIO_BYTE(0x0A + __SFR_OFFSET)
       
#define RXCIE 	7
#define TXCIE 	6
#define UDRIE 	5
#define RXEN 	4
#define TXEN 	3
#define UCSZ2 	2
#define RXB8 	1
#define TXB8	0

#define UCSRC	UBRRH

#define URSEL 	7
#define UMSEL 	6
#define UPM1 	5
#define UPM0 	4
#define USBS 	3
#define UCSZ1 	2
#define UCSZ0 	1
#define UCPOL	0

#define UBRRL 	_MMIO_BYTE(0x09 + __SFR_OFFSET)



#define No_Parity 	0
#define Odd_Parity	1
#define Even_Parity 2


#endif
