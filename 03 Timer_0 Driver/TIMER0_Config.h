/****************************************************** */
/* Author 		: Sami Selim							*/
/* Version 		: V 01									*/
/* Date 		: 30 DEC 2020 							*/
/****************************************************** */


#ifndef _TIMER0_CONFIG_H
#define _TIMER0_CONFIG_H


/* 
	Please Select OC0 PIN option FOR CTC MODE From Interface File as you want 

	1) OC0_NOT_CONNECTED
	2) TOGGLE_OC0_ON_COMPARE_MATCH 
	3) CLEAR_OC0_ON_COMPARE_MATCH
	4) SET_OC0_ON_COMPARE_MATCH	

*/
#define OC0_CTC_PIN_Option		OC0_NOT_CONNECTED

/* 
	Please Select OC0 PIN option FOR PWM MODE From Interface File as you want 

	1) OC0_DISCONNECTED
	2) NON_INVERTING_MODE 
	3) INVERTING_MODE
	
*/

#define OC0_PWM_PIN_Option		NON_INVERTING_MODE

#endif
