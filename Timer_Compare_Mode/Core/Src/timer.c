/*
 * timer.c
 *
 *  Created on: Apr 5, 2023
 *      Author: kinan
 */

#include "timer.h"
#include "led.h"

static void oc_led_init(void);


void timer_init(void){

	oc_led_init();

	__HAL_RCC_TIM14_CLK_ENABLE();

	TIM14->PSC = 48000-1;  // 48MhZ / 47999 = 1000 Hz = 1kHz

	TIM14->CCMR1 &= ~TIM_CCMR1_CC1S_0;
	TIM14->CCMR1 &= ~TIM_CCMR1_CC1S_1;

//	TIM14->CCMR1 &= ~(1<<0);
//	TIM14->CCMR1 &= ~(1<<1);


	TIM14->CCMR1 |= TIM_CCMR1_OC1M_0;
	TIM14->CCMR1 |= TIM_CCMR1_OC1M_1;
	TIM14->CCMR1 &= ~TIM_CCMR1_OC1M_2;

// TIM14->CCMR1 &= ~(1<<6);
// TIM14->CCMR1 |= (1<<5);
// TIM14->CCMR1 |= (1<<4);

	TIM14->CCER |= TIM_CCER_CC1E;

// TIM14->CCER |= (1<<0);

	TIM14->CCER &= ~TIM_CCER_CC1P;

// TIM14->CCER &= ~(1<<1);

	TIM14->ARR = 99; //100ms de taşma
	TIM14->CCR1 = 99; //100ms de karşılaştırma

}

void timer_enable(void){
TIM14->CR1 |= (1<<0);
}
void timer_disable(void){
	TIM14->CR1 &= ~(1<<0);
}


static void oc_led_init(void){

	GPIO_InitTypeDef tim_led_pins;

	__HAL_RCC_GPIOA_CLK_ENABLE();


//	GPIOA->MODER |= (1<<15);
//	GPIOA->MODER &= ~(1<<14);

//GPIOA->OTYPER &= ~(1<<7);

//GPIOA->OSPEEDR |= (1<<14);
//GPIOA->OSPEEDR &= ~(1<<15);

//GPIOA->PUPDR &= ~(1<<14);
//GPIOA->PUPDR &= ~(1<<15);

// **AF7 CONF**

//	GPIOA->AFR |= (1<<28);
//	GPIOA->AFR |= (1<<29);
//	GPIOA->AFR |= (1<<30);
//	GPIOA->AFR &= ~(1<<31);

	tim_led_pins.Mode = GPIO_MODE_AF_PP ;
	tim_led_pins.Pin = GPIO_PIN_7;
	tim_led_pins.Pull =GPIO_NOPULL;
	tim_led_pins.Speed = GPIO_SPEED_MEDIUM ;
	HAL_GPIO_Init(GPIOA, &tim_led_pins);

	// AF4 TO PA7 PIN CONFIGURATION

	GPIOA->AFR[0] &= ~(1<<28);
	GPIOA->AFR[0] &= ~(1<<29);
	GPIOA->AFR[0] |= (1<<30);
	GPIOA->AFR[0] &= ~(1<<31);

}

void timer14_capture_set_period(uint32_t ms){

	TIM14->ARR = ms - 1;
	TIM14->CCR1 = ms - 1;
}
