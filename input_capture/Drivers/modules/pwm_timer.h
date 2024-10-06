/*
 * pwm_timer.h
 *
 *  Created on: Sep 17, 2024
 *      Author: yusuf
 */

#ifndef MODULES_PWM_TIMER_H_
#define MODULES_PWM_TIMER_H_

#include "stm32f0xx_hal.h"

void pwm_timer_init(void);
void pwm_timer_gpıo_init(void);
void pwm_start(void);
void pwm_stop(void);

#endif /* MODULES_PWM_TIMER_H_ */
