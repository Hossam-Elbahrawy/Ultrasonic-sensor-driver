
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega32 -c main.c LCD/LCD.c timer/timer.c ultrasonic.c
avr-gcc -mmcu=atmega32 *.o -o run
avr-objcopy -O ihex -R .eeprom run run.hex
avrdude -F -V -c usbasp -p ATMEGA32 -P /dev/ttyACM0 -b 115200 -U flash:w:run.hex
