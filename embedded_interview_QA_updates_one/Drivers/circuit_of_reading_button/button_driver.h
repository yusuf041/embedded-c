/*
 * button_driver.h
 *
 *  Created on: Aug 20, 2024
 *      Author: yusuf
 */

#ifndef CIRCUIT_OF_READING_BUTTON_BUTTON_DRIVER_H_
#define CIRCUIT_OF_READING_BUTTON_BUTTON_DRIVER_H_

#include "stm32f0xx_hal.h"

#define long_blink 1
#define short_blink 0

void button_gpio_init(void);
void external_interrupt_init(void);
uint8_t get_button_state(void);

#endif /* CIRCUIT_OF_READING_BUTTON_BUTTON_DRIVER_H_ */
