/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 21 DEC 2020							*/
/****************************************************** */




#ifndef _MACRO_FUNCTIONS_H
#define _MACRO_FUNCTIONS_H

#define _MMIO_BYTE(mem_addr) *((volatile u8 *)(mem_addr))

#define SET_BIT(REG , PIN)		REG |= (1<<PIN)
#define CLEAR_BIT(REG , PIN)	REG &=~ (1<<PIN)

#define TOGGLE_BIT(REG , PIN) 	REG ^= (1<<PIN)
#define CHECK_BIT(REG , PIN)	REG & (1<<PIN)




#endif

