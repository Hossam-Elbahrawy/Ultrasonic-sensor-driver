/*
 * pin_config.h
 *
 * Author : Hossam Elbahrawy
 */
#ifndef PIN_CONFIG_H_
#define PIN_CONFIG_H_


#define DATA_BUS		PORTA
#define CTL_BUS			PORTA
#define DATA_DDR		DDRA
#define CTL_DDR			DDRA

//LCD DATA PINS
#define   LCD_D4			   0
#define   LCD_D5			   1
#define   LCD_D6			   2
#define   LCD_D7			   3

// LCD CONTROL PINS
#define   LCD_EN			   5
#define	  LCD_RW			   6
#define	  LCD_RS			   7

#endif /* PIN_CONFIG_H_ */
