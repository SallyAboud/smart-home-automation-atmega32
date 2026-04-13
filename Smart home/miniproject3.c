/*
 * miniproject3.c
 *
 *  Created on: Oct 5, 2024
 *      Author: SoO
 */

#include"buzzer.h"
#include"flame.h"
#include"lcd.h"
#include"ldr.h"
#include"leds.h"
#include"lm35_sensor.h"
#include<avr/io.h>
#include"dc_motor.h"
int main(){
	uint8 temp;
	uint16 light_intensity;

	ADC_init();/* initialize ADC driver */
	BUZZER_init();/* initialize buzzer driver */
	FLAME_SENSOR_init();/* initialize flame sensor driver */
	LCD_init();/* initialize LCD driver */
	LEDS_init();/* initialize leds driver */
	DCMotor_init();/* initialize dc motor driver */

	while(1){

		temp=LM35_getTemperature();
		light_intensity=LDR_getLightIntensity();

		LCD_displayStringRowColumn(0,0,"FAN is ");//display in the first row "fan is"
		LCD_displayStringRowColumn(1,0,"Temp=");//display in the second row "Temp="
		LCD_displayStringRowColumn(1,8,"LDR=");//display in the second row "LDR="
		LCD_displayStringRowColumn(1,15,"%");//display in the second row "%"

		//controlling the leds according to the LDR reading and the display of the light intensity

		// Display the light intensity value every time at same position
		LCD_moveCursor(1,12);
		if(light_intensity==100){

			LCD_intgerToString(light_intensity);

		}
		else{

			LCD_intgerToString(light_intensity);
			LCD_displayCharacter(' ');

		}

		//if light intensity is less than or equal 15% turn on all the leds
		if(light_intensity<=15){

			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);

		}

		//if light intensity is more than 15% and less than or equal 50 turn on the red and green leds only and turn off the blue led
		else if(light_intensity<=50){

			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);

		}

		//if light intensity is more than 50% and less than or equal 70 turn on the red led only and turn off the blue and green leds
		else if(light_intensity<=70){

			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);

		}

		//if light intensity is more than 70% turn off all the leds
		else{

			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);

		}

		//controlling the fan according to the temperature value and the display of the temperature and the status of the fan (on or off)

		// Display the temperature value every time at same position
		LCD_moveCursor(1,5);
		if(temp>=100){

			LCD_intgerToString(temp);

		}
		else{

			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');

		}

		//if temperature is less than 25 turn off the fan and display that the fan is off
		if(temp<25){

			DCMotor_rotate(Stop,0);
			LCD_displayStringRowColumn(0,7,"OFF");

		}

		//if temperature is more than 25 display that the fan is on
		else{

			LCD_displayStringRowColumn(0,7,"ON ");

			//if temperature is more than or equal 40 make the fan rotates clockwise and at speed 100%
			if(temp>=40){

				DCMotor_rotate(CW,100);

			}

			//if temperature is more than or equal 35 and less than 40 make the fan rotates clockwise and at speed 75%
			else if(temp>=35){

				DCMotor_rotate(CW,75);

			}

			//if temperature is more than or equal 30 and less than 35 make the fan rotates clockwise and at speed 50%
			else if(temp>=30){

				DCMotor_rotate(CW,50);

			}

			//if temperature is more than or equal 25 and less than 30 make the fan rotates clockwise and at speed 25%
			else{

				DCMotor_rotate(CW,25);

			}

		}

		//if there is a flame the buzzer will turn on and the lcd screen will be cleared and then displays "Critical alert!"
		if(FLAME_SENSOR_getValue()){

			BUZZER_on();
			LCD_clearScreen();

			while(FLAME_SENSOR_getValue()){
				LCD_displayStringRowColumn(0,0,"Critical alert!");
			}

			LCD_clearScreen();
		}

		//if there is no flame turn off the buzzer
		else{
			BUZZER_off();
		}
	}
}
