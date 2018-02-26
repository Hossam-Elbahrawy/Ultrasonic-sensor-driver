#ifndef _ULTRA_H_
#define _ULTRA_H_

#define   TRIGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTD
#define   TRIGER        2
#define   ECHO          3

/*************************************************
 *  API functions
 *************************************************/

void ultrasonic_init(void);
void ultrasonic_triger(void);

#endif
