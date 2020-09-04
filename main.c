/*
 * main.c
 *
 *  Created on: Jul 26, 2020
 *      Author: MeGa
 */

#include<avr/io.h>
#include<util/delay.h>

int main()
{

	LCD_init();
	LCD_send_one_letter('A',2,12);

	return 0;
}
