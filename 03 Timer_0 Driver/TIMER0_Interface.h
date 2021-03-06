/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 01									*/
/* Date 		: 30 DEC 2020 							*/
/****************************************************** */

#ifndef _TIMER0_INTERFACE_H
#define _TIMER0_INTERFACE_H

#include "DATA_TYPES.h"
#include "MACRO_FUNCTIONS.h"


/* Timer 0 Mode Options */

typedef enum
{	
	TIMER0_OVERFLOW_MODE,				/* Over flow mode*/
	TIMER0_COMPAREMATCH_MODE,			/* Compare Match Mode ( CTC )*/
	
}TIMER0_MODE_OPTIONS;

/* OC0 PIN Options For What happen if CTC generate an Inerrupt */

#define OC0_NOT_CONNECTED			 	0
#define TOGGLE_OC0_ON_COMPARE_MATCH 	1
#define CLEAR_OC0_ON_COMPARE_MATCH		2
#define SET_OC0_ON_COMPARE_MATCH		3

/* Prescaler Options For Timer 0 */

typedef enum
{
	TIMER0_SCALER_0=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_32,
	TIMER0_SCALER_64,
	TIMER0_SCALER_128,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024

}PRESCALER_OPTIONS;

/* OC0 PIN Options For PWM MODE */

#define OC0_DISCONNECTED			 	0
#define NON_INVERTING_MODE				1
#define INVERTING_MODE					2



void TIMER0_voidInit(TIMER0_MODE_OPTIONS Copy_ENUMTimer0_Mode, PRESCALER_OPTIONS Copy_ENUMPreScaler);

void TIMER0_voidStart(u8 Copy_u8StartValue);

void TIMER0_voidSETCompareValue(u8 Copy_u8CompareValue);

void TIMER0_voidStop();

u8 TIMER0_u8Read_value();	

void TIMER0_voidInitPWM(PRESCALER_OPTIONS Copy_ENUMPreScaler);

void TIMER0_voidPWMSET_DutyCycle(u8 Copy_u8DutyCycle);

void TIMER0_voidCallBack(TIMER0_MODE_OPTIONS Copy_ENUMTimer0_Mode , void(*CallBack)(void));

#endif
