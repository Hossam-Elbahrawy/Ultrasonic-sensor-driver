#include  "LCD/LCD.h"
#include  "ultrasonic.h"

int main(){

lcd_init();
ultrasonic_init();
sei();

lcd_write_word("Distance is ");

while(1){
  ultra_triger();
}

  return 0;
}
