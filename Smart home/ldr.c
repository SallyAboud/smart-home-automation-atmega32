/*
 * ldr.c
 *
 *  Created on: Oct 4, 2024
 *      Author: SoO
 *
 * Module: LDR
 *
 * File Name: ldr.c
 *
 * Description: source file for the ldr Sensor driver
 */

#include <util/delay.h> /* For the delay functions */
#include "ldr.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for calculating the intensity of light from the ADC digital value.
 */
uint16 LDR_getLightIntensity(void)
{
	uint16 light_intensity = 0;
	uint16 adc_value=0;
	/* Read ADC channel where the LDR is connected */
	adc_value=ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
	_delay_ms(5);

	/* Calculate the light intensity from the ADC value*/
	light_intensity = (uint16)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));
	return light_intensity;
}
