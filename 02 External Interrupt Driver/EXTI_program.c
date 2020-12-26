/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 26 DEC 2020							*/
/****************************************************** */

#include "DATA_TYPES.h"
#include "MACRO_FUNCTIONS.h"

#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "EXTI_Config.h"

static void (*EXTI_CallBack[3])(void) = {NULL};

ISR(EXTI0_VECTOR)
{
	EXTI_CallBack[0]();
}

ISR(EXTI1_VECTOR)
{
	EXTI_CallBack[1]();
}

ISR(EXTI2_VECTOR)
{
	EXTI_CallBack[2]();
}


void EXTI_voidEnable_EXTI(EXTI_TYPE Copy_u8EXTI_TYPE , EXTI_SENSE Copy_u8EXTI_Edge)
{
	sei();  /* Enable Global Enterrupt */
	switch(Copy_u8EXTI_TYPE)
	{
	case EXTI_0:
		SET_BIT(GICR , INT0);
		switch(Copy_u8EXTI_Edge)
		{
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(MCUCR ,ISC00);
			CLEAR_BIT(MCUCR ,ISC01);
			break;
		case EXTI_FALLING:
			CLEAR_BIT(MCUCR ,ISC00);
			SET_BIT(MCUCR ,ISC01);
			break;
		case EXTI_RISING:
			SET_BIT(MCUCR ,ISC00);
			SET_BIT(MCUCR ,ISC01);
			break;
		case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR ,ISC00);
			CLEAR_BIT(MCUCR ,ISC01);
			break;
		default:
			break;
		}
		break;
		case EXTI_1:
			SET_BIT(GICR , INT1);
			switch(Copy_u8EXTI_Edge)
			{
			case EXTI_LOW_LEVEL:
				CLEAR_BIT(MCUCR ,ISC10);
				CLEAR_BIT(MCUCR ,ISC11);
				break;
			case EXTI_FALLING:
				CLEAR_BIT(MCUCR ,ISC10);
				SET_BIT(MCUCR ,ISC11);
				break;
			case EXTI_RISING:
				SET_BIT(MCUCR ,ISC10);
				SET_BIT(MCUCR ,ISC11);
				break;
			case EXTI_ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR ,ISC10);
				CLEAR_BIT(MCUCR ,ISC11);
				break;
			default:
				break;
			}
			break;
			case EXTI_2:
				SET_BIT(GICR , INT2);
				switch(Copy_u8EXTI_Edge)
				{
				case EXTI_FALLING:
					CLEAR_BIT(MCUCSR ,ISC2);
					break;
				case EXTI_RISING:
					SET_BIT(MCUCSR ,ISC2);
					break;
				default:
					break;
				}
				break;
				default:
					break;
	}

}

void EXTI_voidDisable_EXTI(EXTI_TYPE Copy_u8EXTI_TYPE)
{
	switch(Copy_u8EXTI_TYPE)
	{
	case EXTI_0:
		CLEAR_BIT(GICR , INT0);
		break;
	case EXTI_1:
		CLEAR_BIT(GICR , INT1);
		break;
	case EXTI_2:
		CLEAR_BIT(GICR , INT2);
		break;
	default:
		break;
	}
}



void EXTI_voidSET_CallBack(void(*FUN_CallBack)(void) , EXTI_TYPE Copy_u8EXTI_TYPE)
{
	EXTI_CallBack[Copy_u8EXTI_TYPE] = FUN_CallBack;

}


