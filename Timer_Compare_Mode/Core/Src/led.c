/*
 * led.c
 *
 *  Created on: Apr 5, 2023
 *      Author: kinan
 */
#include "stm32f0xx_hal.h"
#include "led.h"


void led_init(void){

	GPIO_InitTypeDef led_pins;

	__HAL_RCC_GPIOA_CLK_ENABLE();

__HAL_RCC_GPIOC_CLK_ENABLE();

led_pins.Mode = GPIO_MODE_OUTPUT_PP;
led_pins.Pin= GPIO_PIN_8 | GPIO_PIN_9 ;
led_pins.Pull= GPIO_PULLUP ;
led_pins.Speed =GPIO_SPEED_MEDIUM;

HAL_GPIO_Init(GPIOC,  &led_pins);

GPIOA->AFR[0] &= ~(1<<28);
GPIOA->AFR[0] &= ~(1<<29);
GPIOA->AFR[0] |= (1<<30);
GPIOA->AFR[0] &= ~(1<<31);

}
void led_toggle(void){

	GPIOC->ODR ^= (1<<8);
		GPIOC->ODR ^= (1<<9);

}
