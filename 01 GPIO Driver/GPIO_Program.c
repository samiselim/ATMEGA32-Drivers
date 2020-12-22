/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 21 DEC 2020							*/
/****************************************************** */
#include "DATA_TYPES.h"
#include "MACRO_FUNCTIONS.h"

#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"

/* REG : GPIOA , GPIOB , GPIOC or GPIOD */

void GPIO_void_Set_Direction(u8 Copy_u8REG , u8 Copy_u8PIN , u8 Copy_u8MODE)
{
	switch(Copy_u8MODE)
	{
	case OUTPUT:
	{
		switch(Copy_u8REG)
		{
		case GPIOA:
		{
			SET_BIT(DDRA , Copy_u8PIN);
			break;
		}
		case GPIOB:
		{
			SET_BIT(DDRB , Copy_u8PIN);
			break;
		}
		case GPIOC:
		{
			SET_BIT(DDRC , Copy_u8PIN);
			break;
		}
		case GPIOD:
		{
			SET_BIT(DDRD , Copy_u8PIN);
			break;
		}
		break;
		default:break;
		}
		break;
	}
	case INPUT:
	{
		switch(Copy_u8REG)
		{
		case GPIOA:
		{
			CLEAR_BIT(DDRA , Copy_u8PIN);
			break;
		}
		case GPIOB:
		{
			CLEAR_BIT(DDRB , Copy_u8PIN);
			break;
		}
		case GPIOC:
		{
			CLEAR_BIT(DDRC , Copy_u8PIN);
			break;
		}
		case GPIOD:
		{
			CLEAR_BIT(DDRD , Copy_u8PIN);
			break;
		}
		default:break;
		}
		break;
	}
	default:break;

	}
}
void GPIO_void_Set_Value(u8 Copy_u8REG , u8 Copy_u8PIN , u8 Copy_u8VALUE)
{
	switch(Copy_u8VALUE)
	{
	case HIGH:
	{
		switch(Copy_u8REG)
		{
		case GPIOA:
		{
			SET_BIT(PORTA , Copy_u8PIN);
			break;
		}
		case GPIOB:
		{
			SET_BIT(PORTB , Copy_u8PIN);
			break;
		}
		case GPIOC:
		{
			SET_BIT(PORTC , Copy_u8PIN);
			break;
		}
		case GPIOD:
		{
			SET_BIT(PORTD , Copy_u8PIN);
			break;
		}
		default:break;
		}
		break;
	}
	case LOW:
	{
		switch(Copy_u8REG)
		{
		case GPIOA:
		{
			CLEAR_BIT(PORTA , Copy_u8PIN);
			break;
		}
		case GPIOB:
		{
			CLEAR_BIT(PORTB , Copy_u8PIN);
			break;
		}
		case GPIOC:
		{
			CLEAR_BIT(PORTC , Copy_u8PIN);
			break;
		}
		case GPIOD:
		{
			CLEAR_BIT(PORTD , Copy_u8PIN);
			break;
		}
		default:break;

		}
		break;
	}
	default:break;

	}
}

void GPIO_void_Set_PULL_UP(u8 Copy_u8REG , u8 Copy_u8PIN)
{
	switch(Copy_u8REG)
	{
	case GPIOA:
	{
		SET_BIT(PORTA , Copy_u8PIN);
		break;
	}
	case GPIOB:
	{
		SET_BIT(PORTB , Copy_u8PIN);
		break;
	}
	case GPIOC:
	{
		SET_BIT(PORTC , Copy_u8PIN);
		break;
	}
	case GPIOD:
	{
		SET_BIT(PORTD , Copy_u8PIN);
		break;
	}
	default:break;

	}
}

void GPIO_void_Toggle_Pin(u8 Copy_u8REG , u8 Copy_u8PIN)
{
	switch(Copy_u8REG)
	{
	case GPIOA:
	{
		TOGGLE_BIT(PORTA , Copy_u8PIN);
		break;
	}
	case GPIOB:
	{
		TOGGLE_BIT(PORTB , Copy_u8PIN);
		break;
	}
	case GPIOC:
	{
		TOGGLE_BIT(PORTC , Copy_u8PIN);
		break;
	}
	case GPIOD:
	{
		TOGGLE_BIT(PORTD , Copy_u8PIN);
		break;
	}
	default:break;

	}
}
