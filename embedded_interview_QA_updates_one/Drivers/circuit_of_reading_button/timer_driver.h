/*
 * timer_driver.h
 *
 *  Created on: Aug 25, 2024
 *      Author: yusuf
 */

#ifndef CIRCUIT_OF_READING_BUTTON_TIMER_DRIVER_H_
#define CIRCUIT_OF_READING_BUTTON_TIMER_DRIVER_H_

#include "stm32f0xx_hal.h"

#define long_period 1
#define short_period 0

void timer_init(void);
void timer_enable(void);
void timer_disable(void);
void set_timer_period(uint16_t set_time);
uint16_t get_timer_period(void);

#endif /* CIRCUIT_OF_READING_BUTTON_TIMER_DRIVER_H_ */
