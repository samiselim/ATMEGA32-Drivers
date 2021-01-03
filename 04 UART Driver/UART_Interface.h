/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 01 JAN 2021 							*/
/****************************************************** */

#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

#include "DATA_TYPES.h"
#include "MACRO_FUNCTIONS.h"


void UART_voidInit(u32 Copy_u32BaudRate);


void UART_voidSendCharacterPolling(u8 Copy_u8Charcter);

void UART_voidRecieveCharacter(u8 *Copy_u8Charcter);

void UART_voidSendStringPolling(u8 *String);




#endif
