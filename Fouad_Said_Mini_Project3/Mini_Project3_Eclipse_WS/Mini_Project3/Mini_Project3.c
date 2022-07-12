 /******************************************************************************
 *
 * Module: Fan Controller
 *
 * File Name: Mini_Project3.c
 *
 * Description: Source file for Temperature-controlled fan project
 *
 * Author: Fouad Dowidar
 *
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dcmotor.h"

int main(void)
{
	uint16 temp_value = 0;

	/*Dynamic configuration pointer*/
	ADC_ConfigType ConFig_Ptr = {INTERNAL,DIVISION_FACTOR_8};

	/*Function responsible for initialize the ADC driver.*/
	ADC_init(&ConFig_Ptr);

	/*Initialize the LCD:*/
	LCD_init();

	/* The Function responsible for setup the direction
	 * for the two motor pins through the GPIO driver.*/
	DcMotor_Init();

	/*Move the cursor to a specified row and column index on the screen*/
	LCD_moveCursor(0,3);
	/*Display the required string on the screen*/
	LCD_displayString("FAN is ");

	/*Move the cursor to a specified row and column index on the screen*/
	LCD_moveCursor(1,3);
	/*Display the required string on the screen*/
	LCD_displayString("Temp =    C");

	while(1)
	{
		temp_value = LM35_getTemperature();

		/*Move the cursor to a specified row and column index on the screen*/
		LCD_moveCursor(0,10);

		/*Setting the state of the Fan and the DC Motor depending on the temperature*/
		if((temp_value >= 0)&&(temp_value <= 29))
		{

			/*Display the required string on the screen*/
			LCD_displayString("OFF");

			/*The function responsible for rotate the DC Motor and Setting the required duty cycle*/
			DcMotor_Rotate(STOP,0);

		}
		else if((temp_value >= 30)&&(temp_value <= 59))
		{

			/*Display the required string on the screen*/
			LCD_displayString("ON");

			/*print space in the next digit place on the screen*/
			LCD_displayCharacter(' ');

			/*The function responsible for rotate the DC Motor and Setting the required duty cycle*/
			DcMotor_Rotate(CW,25);

		}
		else if((temp_value >= 60)&&(temp_value <= 89))
		{

			/*Display the required string on the screen*/
			LCD_displayString("ON");

			/*print space in the next digit place on the screen*/
			LCD_displayCharacter(' ');

			/*The function responsible for rotate the DC Motor and Setting the required duty cycle*/
			DcMotor_Rotate(CW,50);

		}
		else if((temp_value >= 90)&&(temp_value <= 119))
		{

			/*Display the required string on the screen*/
			LCD_displayString("ON");

			/*print space in the next digit place on the screen*/
			LCD_displayCharacter(' ');

			/*The function responsible for rotate the DC Motor and Setting the required duty cycle*/
			DcMotor_Rotate(CW,75);

		}
		else if((temp_value >= 120))
		{

			/*Display the required string on the screen*/
			LCD_displayString("ON");

			/*print space in the next digit place on the screen*/
			LCD_displayCharacter(' ');

			/*The function responsible for rotate the DC Motor and Setting the required duty cycle*/
			DcMotor_Rotate(CW,100);

		}

		/*Move the cursor to a specified row and column index on the screen*/
         LCD_moveCursor(1,10);

		/* Display the temperature value every time at same position */
		if(temp_value >= 100)
		{

			/*Display the required decimal value on the screen*/
			LCD_intgerToString(temp_value);

		}
		else
		{

			/*Display the required decimal value on the screen*/
			LCD_intgerToString(temp_value);

			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');

		}
	}
}
