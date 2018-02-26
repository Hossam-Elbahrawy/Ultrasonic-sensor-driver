#include
enable_ex_interrupt();<avr/io.h>
#include  "LCD/LCD.h"
#include  "timer/timer.h"
#include  "ultrasonic.h"

int main(){

lcd_init();
ultrasonic_init();

while(1){

}

  return 0;
}
