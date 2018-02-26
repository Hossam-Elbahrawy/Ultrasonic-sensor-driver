#include "ultrasonic.h"

void ultrasonic_init(void){
  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR|=(1<<ECHO);
  return;
}
void ultra_triger(void){

  return;
}
