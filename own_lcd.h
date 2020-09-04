/*
 * own_lcd.h
 *
 *  Created on: Jul 26, 2020
 *      Author: MeGa
 */

#ifndef OWN_LCD_H_
#define OWN_LCD_H_

#include<avr/io.h>
#include<util/delay.h>
void LCD_init();
void  LCD_send_command(unsigned char command );
void LCD_send_one_letter(unsigned char data, unsigned char y,unsigned char x);
void LCD_send_one_letter_8bit_mode(unsigned char data, unsigned char y,unsigned char x);
void LCD_send_string(char * data);
void lcd_make_pulse ();

#define lcd_4_bit_mode 1
#define lcd_8_bit_mode 0

#define display_mode_on  1
#define display_mode_off 0

#define cursor_mode_on 1
#define cursor_mode_off 0

#define cursor_blink_mode_on 1
#define cursor_blink_mode_off 0

#define data_4_mode 1
#define data_8_mode 2

#define first_row 1
#define second_row 2
#endif /* OWN_LCD_H_ */
