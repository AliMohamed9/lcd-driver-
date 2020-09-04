/*
 * own_lcd.c
 *
 *  Created on: Jul 26, 2020
 *      Author: MeGa
 */
#include<avr/io.h>
#include<util/delay.h>
#include"own_lcd.h"


void LCD_init()
{

		DDRC|=(1<<7);
		DDRC|=(1<<6);
		PORTC&=~(1<<6);
#if lcd_4_bit_mode
		DDRB=0b11110000;
	    LCD_send_command(0x28);
	_delay_ms(5);
	/*
	PORTB=(PORTB&0x0f)|(0xf0&0x28);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);

	PORTB=(PORTB&0x0f)|(0x28<<4);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);
*/
#elif lcd_8_bit_mode
	DDRB=0b11111111;
	LCD_send_command(0x30);
	_delay_ms(5);

#endif

#if display_mode_on

	LCD_send_command(0x0c);
	_delay_ms(5);
	/*
	PORTB=(PORTB&0x0f)|(0xf0&0x0c);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);

	PORTB=(PORTB&0x0f)|(0x0c<<4);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);
*/

#elif display_mode_off
	LCD_send_command(0x08);
	_delay_ms(5);

#endif


#if cursor_mode_on
	LCD_send_command(0x0e);
	_delay_ms(5);

#elif cursor_mode_off
	LCD_send_command(0x0c);
	_delay_ms(5);

#endif

#if  cursor_blink_mode_on
	LCD_send_command(0x0f);
	_delay_ms(5);

#elif cursor_blink_mode_off
	LCD_send_command(0x0e);
	_delay_ms(5);
#endif


	LCD_send_command(0x06);     /////shift
/*
	PORTB=(PORTB&0x0f)|(0xf0&0x06);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);

	PORTB=(PORTB&0x0f)|(0x06<<4);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);
*/
	_delay_ms(5);

	LCD_send_command(0x01);   ////clear lcd
	/*
	PORTB=(PORTB&0x0f)|(0xf0&0x01);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);

	PORTB=(PORTB&0x0f)|(0x01<<4);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);
*/
	_delay_ms(5);

//	LCD_send_command(0x0e);
/*
	PORTB=(PORTB&0x0f)|(0xf0&0x0e);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);

	PORTB=(PORTB&0x0f)|(0x0e<<4);
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);
*/
	//_delay_ms(5);



}
void LCD_send_command(unsigned char command )
{
   #if lcd_4_bit_mode

	PORTC&=~(1<<6);
	PORTB=(PORTB&0x0f)|(0xf0&command);
	lcd_make_pulse ();
	/*
		PORTC|=(1<<7);
		_delay_ms(1);
		PORTC&=~(1<<7);
		_delay_ms(1);
   */

		PORTB=(PORTB&0x0f)|(command<<4);

		lcd_make_pulse ();

		/*
		PORTC|=(1<<7);
		_delay_ms(1);
		PORTC&=~(1<<7);
		_delay_ms(1);

		_delay_ms(5);
        */


#elif  lcd_8_bit_mode
	{
		PORTC&=~(1<<6);
			PORTB=command;
			lcd_make_pulse ();
		/*
		    PORTC|=(1<<7);
		    _delay_ms(1);
		    PORTC&=~(1<<7);
		    _delay_ms(1);
       */
	}
#endif
}
void LCD_send_one_letter(unsigned char data, unsigned char y,unsigned char x)
{

#if lcd_4_bit_mode

	if(y==first_row)
	{

		LCD_send_command(0x80+x-1);
		_delay_ms(1);

	PORTC|=(1<<6);
	PORTB=(PORTB&0x0f)|(0xf0&data);
	lcd_make_pulse ();
	/*
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);
   */
	PORTB=(PORTB&0x0f)|(data<<4);
	lcd_make_pulse ();
	/*
	PORTC|=(1<<7);
	_delay_ms(1);
	PORTC&=~(1<<7);
	_delay_ms(1);
    */
	_delay_ms(5);
	}
	else if(y==second_row)
	{
		LCD_send_command(0xc0+x-1);
		_delay_ms(1);

			PORTC|=(1<<6);
			PORTB=(PORTB&0x0f)|(0xf0&data);
			lcd_make_pulse ();

			/*
			PORTC|=(1<<7);
			_delay_ms(1);
			PORTC&=~(1<<7);
			_delay_ms(1);
            */
			PORTB=(PORTB&0x0f)|(data<<4);
			lcd_make_pulse ();
			/*
			PORTC|=(1<<7);
			_delay_ms(1);
			PORTC&=~(1<<7);
			_delay_ms(1);
           */
	}

#elif lcd_8_bit_mode

	PORTC|=(1<<6);

	if(y==first_row)
	{
	LCD_send_command(0x80+x-1);
	_delay_ms(1);
	PORTC|=(1<<6);
	PORTB=data;
	lcd_make_pulse ();
	   /*
	PORTC|=(1<<7);
	    _delay_ms(1);
	    PORTC&=~(1<<7);
	    _delay_ms(1);
	    */
	}
	else if(y==second_row)
	{
		LCD_send_command(0xc0+x-1);
			_delay_ms(1);
			PORTC|=(1<<6);
			PORTB=data;
		     	/*
		 	PORTC|=(1<<7);
			    _delay_ms(1);
			    PORTC&=~(1<<7);
			    _delay_ms(1);
			    */
	}
#endif
}

void LCD_send_string(unsigned char * sentence)
{
	while(*sentence!='/0')
	{
		LCD_send_one_letter(*sentence++);
	}

}
void lcd_make_pulse ()
{
	PORTC|=(1<<7);
			_delay_ms(1);
			PORTC&=~(1<<7);
			_delay_ms(1);
}

