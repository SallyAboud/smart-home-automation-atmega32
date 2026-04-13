/*
 * flame.h
 *
 *  Created on: Oct 4, 2024
 *      Author: SoO
 *
 * Module: Flame
 *
 * File Name: flame.h
 *
 * Description: header file for the flame sensor driver
 */

#ifndef FLAME_H_
#define FLAME_H_
#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define FLAME_SENSOR_PORT  PORTD_ID
#define FLAME_SENSOR_PIN   PIN2_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the flame sensor.
 */
void FLAME_SENSOR_init();

/*
 * Description :
 * Function responsible for getting the value of flame sensor.
 */
uint8 FLAME_SENSOR_getValue();

#endif /* FLAME_H_ */
