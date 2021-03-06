/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 21 DEC 2020							*/
/****************************************************** */




#ifndef _MACRO_FUNCTIONS_H
#define _MACRO_FUNCTIONS_H

/* OFFSET ADDRESS FOR SFR */
#define __SFR_OFFSET   0x20

#define _MMIO_BYTE(mem_addr) *((volatile u8 *)(mem_addr))

#define SET_BIT(REG , PIN)		REG |= (1<<PIN)
#define CLEAR_BIT(REG , PIN)	REG &=~ (1<<PIN)

#define TOGGLE_BIT(REG , PIN) 	REG ^= (1<<PIN)
#define CHECK_BIT(REG , PIN)	REG & (1<<PIN)

#define sei()  __asm__ __volatile__ ("sei" ::)
#define cli()  __asm__ __volatile__ ("cli" ::)


#endif

