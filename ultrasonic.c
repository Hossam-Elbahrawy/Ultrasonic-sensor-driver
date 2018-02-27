#include "ultrasonic.h"

uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint16_t timer_counter=0;
extern uint16_t distance;

void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt();
  timer0_init();
  return;
}

void enable_ex_interrupt(void){

  MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
  MCUCR &= ~(1<<ISC11);
  GICR  |= (1<<INT1);			// Enable INT1 interrupts.

  return;
}

void ultra_triger(void){
  if(!sensor_working){
    _delay_ms(10);
    TRIGER_PORT&=~(1<<TRIGER);
    _delay_us(10);
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
}

ISR(INT1_vect){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else{
    distance=(timer_counter*256+TCNT0)/58;
    rising_edge=0;
    sensor_working=0;
  }
  }
}

ISR(TIMER0_OVF_vect){
  if(rising_edge==1){
    timer_counter++;

 if(timer_counter>91){        // timer reaches the maximum vlaue of the sensor 400cm
    sensor_working=0;
    rising_edge=0;
  }
}
}
