/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 27 DEC 2020 							*/
/****************************************************** */


#ifndef _TIMER0_PRIVATE_H
#define _TIMER0_PRIVATE_H

#include "MACRO_FUNCTIONS.h"


/* OFFSET ADDRESS FOR SFR */
#define __SFR_OFFSET   0x20


#define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
    void vector (void)


#define TIMER0_OVF_VECTOR	__vector_11

#define TIMER0_COMP_VECTOR	__vector_10


#define  TCCR0	_MMIO_BYTE(0x33 + __SFR_OFFSET)


#define  FOC0 		7
#define  WGM00 		6
#define  COM01		5
#define  COM00		4
#define  WGM01		3
#define  CS02 		2
#define  CS01 		1
#define  CS00		0

#define TCNT0	_MMIO_BYTE(0x32 + __SFR_OFFSET)

#define	OCR0	_MMIO_BYTE(0x3C + __SFR_OFFSET)

#define TIMSK	_MMIO_BYTE(0x39 + __SFR_OFFSET)

#define OCIE0		1
#define TOIE0 		0

#define TIFR	_MMIO_BYTE(0x38 + __SFR_OFFSET)

#define OCF0		1
#define TOV0 		0


#endif
