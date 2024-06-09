/*
 * uart_driver.h
 *
 *  Created on: May 31, 2024
 *      Author: kinan
 */

#ifndef MY_UART_MODULES_UART_DRIVER_H_
#define MY_UART_MODULES_UART_DRIVER_H_

#include "stm32f0xx_hal.h"

void uart_init(void);
void UART_send_byte(uint8_t data);
void UART_send_byte_array(uint8_t* buffer, uint32_t size);
int32_t UART_read_byte(void);
uint32_t UART_bytes_to_read(void);


#endif /* MY_UART_MODULES_UART_DRIVER_H_ */
