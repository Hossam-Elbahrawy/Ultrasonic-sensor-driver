#include "ultrasonic.h"

uint8_t sensor_working=0;

void ultrasonic_init(void){
  
  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt();
  timer0_init();

  return;
}

void enable_ex_interrupt(void){

  GICR  |= (1<<INT1);			// Enable INT1 interrupts.
	MCUCR |= (1<<ISC10) ;		// Trigger INT1 on any logic change.

  return;
}

void ultra_triger(void){

  TRIGER_PORT|=(1<<TRIGER);
  _delay_us(10);
  TRIGER_PORT&=~(1<<TRIGER);
  sensor_working=1;

  return;
}
