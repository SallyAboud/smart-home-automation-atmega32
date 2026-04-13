/*
 * flame.c
 *
 *  Created on: Oct 4, 2024
 *      Author: SoO
 *
 * Module: Flame
 *
 *File Name: flame.c
 *
 * Description: source file for the flame Sensor driver
 */

#include"flame.h"
#include"gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the flame sensor.
 */
void FLAME_SENSOR_init(){

	GPIO_setupPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN,PIN_INPUT);//set the flame sensor pin as an input

}

/*
 * Description :
 * Function responsible for getting the value of flame sensor.
 */
uint8 FLAME_SENSOR_getValue(){
	//return the reading of the flame sensor
	return GPIO_readPin(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN);
}

