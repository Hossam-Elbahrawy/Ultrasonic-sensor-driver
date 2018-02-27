#include  <avr/io.h>
#include  "LCD/LCD.h"
#include  "timer/timer.h"
#include  "ultrasonic.h"

uint8_t distance;
//uint8_t distance_str[5];

int main(){
//lcd_init();
ultrasonic_init();
DDRA=0xff;
sei();

//lcd_write_word("Distance is ");
//lcd_goto_xy(1,0);

while(1){
PORTA=distance;
//itoa(distance,distance_str,10);
//lcd_write_word(distance_str);
ultra_triger();
}

  return 0;
}
