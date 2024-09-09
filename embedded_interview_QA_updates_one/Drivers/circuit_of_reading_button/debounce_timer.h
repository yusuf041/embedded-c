/*
 * debounce_timer.h
 *
 *  Created on: Aug 26, 2024
 *      Author: yusuf
 */

#ifndef CIRCUIT_OF_READING_BUTTON_DEBOUNCE_TIMER_H_
#define CIRCUIT_OF_READING_BUTTON_DEBOUNCE_TIMER_H_

#include "stm32f0xx_hal.h"

#define debounced 1
#define undebounced 0


void debounce_timer_init(void);
uint8_t after_debouncing_button_state(void);
void debounce_timer_enable(void);
void debounce_timer_disable(void);

#endif /* CIRCUIT_OF_READING_BUTTON_DEBOUNCE_TIMER_H_ */
