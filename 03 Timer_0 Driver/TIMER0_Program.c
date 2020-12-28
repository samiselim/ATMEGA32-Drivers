/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 27 DEC 2020 							*/
/****************************************************** */

#include "TIMER0_Private.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Config.h"

static void(*ptrCallBack[2])(void) = {NULL};

ISR(TIMER0_OVF_VECTOR)
{
	ptrCallBack[0]();
}

ISR(TIMER0_COMP_VECTOR)
{
	ptrCallBack[1]();
}

void TIMER0_voidInit(TIMER0_MODE_OPTIONS Copy_ENUMTimer0_Mode, PRESCALER_OPTIONS Copy_ENUMPreScaler)
{
	sei();
	switch(Copy_ENUMPreScaler)
		{
			case TIMER0_SCALER_1:
				TCCR0 = ((TCCR0 & 0xF8) | TIMER0_SCALER_1);
				break;
			case TIMER0_SCALER_8:
				TCCR0 = ((TCCR0 & 0xF8) | TIMER0_SCALER_8);
				break;
			case TIMER0_SCALER_32:
				TCCR0 = ((TCCR0 & 0xF8) | TIMER0_SCALER_32);
				break;
			case TIMER0_SCALER_64:
				TCCR0 = ((TCCR0 & 0xF8) | TIMER0_SCALER_64);
				break; 
			case TIMER0_SCALER_128:
				TCCR0 = ((TCCR0 & 0xF8) | TIMER0_SCALER_128);
				break;
			case TIMER0_SCALER_256:
				TCCR0 = ((TCCR0 & 0xF8) | TIMER0_SCALER_256);
				break;
			case TIMER0_SCALER_1024:
				TCCR0 = ((TCCR0 & 0xF8) | TIMER0_SCALER_1024);
				break;
			default:
				break;
		}

	switch(Copy_ENUMTimer0_Mode)
	{
		case TIMER0_OVERFLOW_MODE:
			SET_BIT(TIMSK , TOIE0);
			CLEAR_BIT(TCCR0 , WGM00);
			CLEAR_BIT(TCCR0 , WGM01);
			break;
		case TIMER0_COMPAREMATCH_MODE:
			SET_BIT(TIMSK , OCIE0);
			CLEAR_BIT(TCCR0 , WGM00);
			SET_BIT(TCCR0 , WGM01);

			#if CTC_Option == OC0_NOT_CONNECTED
				CLEAR_BIT(TCCR0 , COM00);
				CLEAR_BIT(TCCR0 , COM01);
			#endif

			break;
		default:
			break;
	}
}

void TIMER0_voidStart(u8 Copy_u8StartValue)
{
	TCNT0 = Copy_u8StartValue;
}

void TIMER0_voidSETCompareValue(u8 Copy_u8CompareValue)
{
	OCR0  = Copy_u8CompareValue;
}

void TIMER0_voidStop()
{
	TCCR0 = ((TCCR0 & 0xF8) | TIMER0_SCALER_0);
}

u8 TIMER0_u8Read_value()
{
	return TCCR0;
}

void TIMER0_voidCallBack(TIMER0_MODE_OPTIONS Copy_ENUMTimer0_Mode , void(*CallBack)(void))
{
	ptrCallBack[Copy_ENUMTimer0_Mode] = CallBack;
}
