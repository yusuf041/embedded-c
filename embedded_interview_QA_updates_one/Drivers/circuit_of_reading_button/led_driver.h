/*
 * led_driver.h
 *
 *  Created on: Aug 20, 2024
 *      Author: yusuf
 */

#ifndef CIRCUIT_OF_READING_BUTTON_LED_DRIVER_H_
#define CIRCUIT_OF_READING_BUTTON_LED_DRIVER_H_

#include "stm32f0xx_hal.h"

#define short_period 0
#define long_period 1

void led_init(void);
void led_short_period(void);
void led_long_period(void);
uint8_t get_led_blinking_status();

#endif /* CIRCUIT_OF_READING_BUTTON_LED_DRIVER_H_ */
