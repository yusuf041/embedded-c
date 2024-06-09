/*
 * timer.h
 *
 *  Created on: Apr 5, 2023
 *      Author: kinan
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "stm32f0xx_hal.h"

void timer_init(void);
void timer_enable(void);
void timer_disable(void);
void timer14_capture_set_period(uint32_t ms) ;

#endif /* INC_TIMER_H_ */
