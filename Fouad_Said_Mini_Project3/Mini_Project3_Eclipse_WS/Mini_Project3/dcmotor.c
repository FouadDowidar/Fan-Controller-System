 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dcmotor.c
 *
 * Description: Source file for the DC MOTOR driver
 *
 * Author: Fouad Dowidar
 *
 *******************************************************************************/

#include "dcmotor.h"
#include "gpio.h"
#include "pwm.h"

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

/* Description :
 * The Function responsible for setup the direction
 * for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */

void DcMotor_Init(void)
{

	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

}

/* Description:
 * The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	PWM_Timer0_Start(speed);

	switch(state)
	{
	case STOP:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);
		break;
	case A_CW:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		break;
	}

}
