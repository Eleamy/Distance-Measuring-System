#include "ultrasound.h"
#include "lcd.h"
#include "avr/io.h"





int main (void)
{
	uint16 distance = 0;


	SREG |= (1<<7);

	LCD_init();
	Ultrasonic_init();


	while (TRUE)
	{

			distance = Ultrasonic_readDistance();
			LCD_displayStringRowColumn(0,0, "Distance = ");
			LCD_intgerToString(distance);
			LCD_displayString("cm");

	}
}


