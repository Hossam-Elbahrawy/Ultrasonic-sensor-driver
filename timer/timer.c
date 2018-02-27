  /***************************************************************
 *  Source File: EF_PWM.c
 *
 *  Description: PWM driver for ATMEGA32
 *
 **************************************************************/
#include "timer.h"


/*********************************************************************
* Function    : timer0_init(void);
*
* DESCRIPTION : Initializes Timer0 with 1024 prescaler.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing.
***********************************************************************/
void timer0_init(void)
{
	    	/* Disable Timer 0 */
	    	TCCR0 = DISABLE_MODULE_VALUE;
	    	/* Setting pre scaler */
	    	TCCR0 = (PRESCLR1_VALUE);
	    	/* Initializing the timer with zero */
	    	TCNT0 = ZER0_INITIALIZER;
				/* Timer overflow interrupt enable*/
				TIMSK |=(1<<TOIE0);

	return;
}
