/*
 * button_driver.h
 *
 *  Created on: May 31, 2024
 *      Author: kinan
 */

#ifndef MY_UART_MODULES_BUTTON_DRIVER_H_
#define MY_UART_MODULES_BUTTON_DRIVER_H_

#include "stm32f0xx_hal.h"

void button_init_interrupt();
int button_get_state(void);


#endif /* MY_UART_MODULES_BUTTON_DRIVER_H_ */
