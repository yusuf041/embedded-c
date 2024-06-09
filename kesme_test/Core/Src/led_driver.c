/*
 * led_driver.c
 *
 *  Created on: Jan 4, 2023
 *      Author: kinan
 */
#include "led_driver.h"
#include "main.h"
#include "stm32f0xx_hal.h"

void led_driver_init(void){

	RCC->AHBENR |= (1<<19);

	GPIOC->MODER &= ~(1<<17);
	GPIOC->MODER |= (1<<16);

	GPIOC->MODER &= ~(1<<19);
	GPIOC->MODER |= (1<<18);

	GPIOC->OTYPER &= ~(1<<8);
	GPIOC->OTYPER &= ~(1<<9);

	GPIOC->OSPEEDR &= ~(1<<16);
	GPIOC->OSPEEDR &= ~(1<<17);

}
void led_on(){
GPIOC->ODR |= (1<<8);
GPIOC->ODR |= (1<<9);
}
void led_off(){
	GPIOC->ODR &= ~(1<<8);
	GPIOC->ODR &= ~(1<<9);
}
