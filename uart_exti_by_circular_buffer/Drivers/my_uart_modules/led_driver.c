/*
 * led_driver.c
 *
 *  Created on: May 31, 2024
 *      Author: kinan
 */


#include "stm32f0xx_hal.h"


void togle_led(void);

void led_init(void){

	RCC->AHBENR |= (1<<19);

	GPIOC->MODER |= (1<<16);  // MODER8 PC8
	GPIOC->MODER &= ~(1<<17);

	GPIOC->MODER |= (1<<18); // MODER9 PC9
	GPIOC->MODER &= ~(1<<19);

	GPIOC->OSPEEDR &= ~(1<<16); //LOW SPEED
	GPIOC->OSPEEDR &= ~(1<<17); //LOW SPEED
	GPIOC->OSPEEDR &= ~(1<<18); //LOW SPEED
	GPIOC->OSPEEDR &= ~(1<<19); //LOW SPEED

	GPIOC->OTYPER &= ~(1<<8);
	GPIOC->OTYPER &= ~(1<<9);

}
void led_on(void){
	 GPIOC->ODR |= (1 << 8);
			GPIOC->ODR |= (1 << 9);
}
void led_off(void){
	GPIOC->ODR &= ~(1 << 8);
		GPIOC->ODR &= ~(1 << 9);
}

void togle_led(void)
{
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
}
