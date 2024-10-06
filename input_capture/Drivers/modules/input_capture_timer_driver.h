/*
 * input_capture_timer_driver.h
 *
 *  Created on: Sep 17, 2024
 *      Author: yusuf
 */

#ifndef MODULES_INPUT_CAPTURE_TIMER_DRIVER_H_
#define MODULES_INPUT_CAPTURE_TIMER_DRIVER_H_

#include "stm32f0xx_hal.h"

#define TIMCLOCK 48000000
#define PRESCALAR 48

void input_capture_timer_init(void);
void input_capture_timer_enable(void);
void input_capture_timer_disable(void);
void input_capture_timer_gpi0_init(void);

#endif /* MODULES_INPUT_CAPTURE_TIMER_DRIVER_H_ */
