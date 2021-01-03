/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 01 JAN 2021 							*/
/****************************************************** */

#include "USART_Private.h"
#include "USART_Interface.h"
#include "UART_Config.h"


u8 Buffer;
ISR(UART_RX_VECTOR)
{
	Buffer = UDR;
}

void UART_voidInit(u32 Copy_u32BaudRate)
{
	/* Asynchronous Mode */
	CLEAR_BIT(UCSRC , UMSEL);

	/* Parity Mode */
#if Parity_Mode == No_Parity
	CLEAR_BIT(UCSRC , UPM1);
	CLEAR_BIT(UCSRC , UPM0);
#elif Parity_Mode == Odd_Parity
	SET_BIT(UCSRC , UPM1);
	SET_BIT(UCSRC , UPM0);
#elif Parity_Mode == Even_Parity
	SET_BIT(UCSRC , UPM1);
	CLEAR_BIT(UCSRC , UPM0);
#else
	{
		/* Error */
	}
#endif

	/* Stop Bit Option */
#if Stop_Bit == 1
	CLEAR_BIT(UCSRC , USBS);
#elif Stop_Bit == 2
	SET_BIT(UCSRC , USBS);
#else
	{
		/* Error */
	}
#endif

	/* Data Frame Size */
#if Data_Frame_Size == 5
	SET_BIT(UCSRC , URSEL);
	CLEAR_BIT(UCSRC , UCSZ0);
	CLEAR_BIT(UCSRC , UCSZ1);
	CLEAR_BIT(UCSRB , UCSZ2);
#elif Data_Frame_Size == 6
	SET_BIT(UCSRC , URSEL);
	SET_BIT(UCSRC , UCSZ0);
	CLEAR_BIT(UCSRC , UCSZ1);
	CLEAR_BIT(UCSRB , UCSZ2);
#elif Data_Frame_Size == 7
	SET_BIT(UCSRC , URSEL);
	CLEAR_BIT(UCSRC , UCSZ0);
	SET_BIT(UCSRC , UCSZ1);
	CLEAR_BIT(UCSRB , UCSZ2);
#elif Data_Frame_Size == 8
	SET_BIT(UCSRC , URSEL);
	SET_BIT(UCSRC , UCSZ0);
	SET_BIT(UCSRC , UCSZ1);
	CLEAR_BIT(UCSRB , UCSZ2);
#elif Data_Frame_Size == 9
	SET_BIT(UCSRC , URSEL);
	SET_BIT(UCSRC , UCSZ0);
	SET_BIT(UCSRC , UCSZ1);
	SET_BIT(UCSRB , UCSZ2);
#else
	{
		/* Error */
	}
#endif
	/*
	Baud Rate 
	 */
	UBRRL=(u8)(((F_CPU)/(16*Copy_u32BaudRate))-1);
	UBRRH = (((F_CPU)/(16*Copy_u32BaudRate))-1) >> 8;

	/* Enable For Interrupt Reciever */


	sei();
	SET_BIT(UCSRB , RXCIE);
	SET_BIT(UCSRB , TXEN);
	SET_BIT(UCSRB , RXEN);

}

void UART_voidSendCharacterPolling(u8 Copy_u8Charcter)
{
	while((CHECK_BIT(UCSRA , UDRE)) == 0);
	UDR = Copy_u8Charcter;
}

void UART_voidRecieveCharacter(u8 *Copy_u8Charcter)
{
	*Copy_u8Charcter = Buffer;
	Buffer = 0;
}

void UART_voidSendStringPolling(u8 *String)
{
	u8 i = 0;
	while(String[i] != '\0')
	{
		UART_voidSendCharacterPolling(String[i]);
		i++;
	}
	UART_voidSendCharacterPolling(String[i]);
}

