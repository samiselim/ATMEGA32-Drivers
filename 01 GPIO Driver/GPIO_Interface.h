/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 00									*/
/* Date 		: 21 DEC 2020							*/
/****************************************************** */

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

#include "DATA_TYPES.h"
#include "MACRO_FUNCTIONS.h"

#include "GPIO_Private.h"

/* MODE : INPUT   OR   OUTPUT */
#define INPUT  0
#define OUTPUT 1

/* VALUE : HIGH   OR   LOW */
#define HIGH 1
#define LOW  0

/* REG OPTIONS */
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3

/* PIN OPTIONS */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


void GPIO_void_Set_Direction(u8 Copy_u8REG , u8 Copy_u8PIN , u8 Copy_u8MODE);

void GPIO_void_Set_Value(u8 Copy_u8REG , u8 Copy_u8PIN , u8 Copy_u8VALUE);

void GPIO_void_Set_PULL_UP(u8 Copy_u8REG , u8 Copy_u8PIN);

void GPIO_void_Toggle_Pin(u8 Copy_u8REG , u8 Copy_u8PIN);

#endif