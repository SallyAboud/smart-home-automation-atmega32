/*
 * leds.h
 *
 *  Created on: Oct 4, 2024
 *      Author: SoO
 *
 * Module: Leds
 *
 * File Name: leds.h
 *
 * Description: header file for the leds driver
 */

#ifndef LEDS_H_
#define LEDS_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LEDS_PORT PORTB_ID
#define RED_PIN   PIN5_ID
#define GREEN_PIN PIN6_ID
#define BLUE_PIN  PIN7_ID
#define LED_ON    LOGIC_HIGH
#define LED_OFF   LOGIC_LOW

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	RED_LED,GREEN_LED,BLUE_LED
}LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the leds.
 */
void LEDS_init();

/*
 * Description :
 * Function responsible for turning a led on.
 */
void LED_on(LED_ID id);

/*
 * Description :
 * Function responsible for turning a led off.
 */
void LED_off(LED_ID id);
#endif /* LEDS_H_ */
