/*
 * led_driver.c
 *
 *  Created on: Aug 20, 2024
 *      Author: yusuf
 */

#include "led_driver.h"
#include "timer_driver.h"
#include "debounce_timer.h"

GPIO_InitTypeDef stausleds;
/*
 *
 * false mean short period
 * true mean long period
 *
 * */

extern uint32_t _debounce_time;
extern uint32_t _tIM14counteR;
extern uint8_t Debounced_button_state;

volatile uint8_t led_blinking_status = 0;

void led_init(void);
void led_on(void);
void led_off(void);
uint8_t get_led_blinking_status();

void led_init(void)
{

RCC->AHBENR |= (1<<19);  //C PORT CLOCK ENABLE
__HAL_RCC_GPIOA_CLK_ENABLE();

GPIOC->MODER |=  (1<<16);  // PC8 & 9 SET as OUTPUT
GPIOC->MODER &= ~(1<<17);

GPIOC->MODER |=  (1<<18);
GPIOC->MODER &= ~(1<<19);

GPIOC->OTYPER &= ~(1<<8);
GPIOC->OTYPER &= ~(1<<9);

GPIOC->OSPEEDR &= ~(1<<16); //PC8 & 9 SPEEDS SET as LOW
GPIOC->OSPEEDR |=  (1<<17);
GPIOC->OSPEEDR &= ~(1<<18);
GPIOC->OSPEEDR |=  (1<<19);

GPIOC->PUPDR &= ~(1<<16);  // PC8 &  9 SET as no pullup / down
GPIOC->PUPDR &= ~(1<<17);
GPIOC->PUPDR &= ~(1<<18);
GPIOC->PUPDR &= ~(1<<19);


__HAL_RCC_GPIOC_CLK_ENABLE();

stausleds.Mode = GPIO_MODE_OUTPUT_PP;
stausleds.Pin = GPIO_PIN_4;
stausleds.Pull = GPIO_NOPULL;
stausleds.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(GPIOC, &stausleds);

stausleds.Mode = GPIO_MODE_OUTPUT_PP;
stausleds.Pin = GPIO_PIN_5;
stausleds.Pull = GPIO_NOPULL;
stausleds.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(GPIOC, &stausleds);

}

void led_short_period(void)
{
// 2 kere 1 sn 2 kere 2sn

//	for (int i = 0; i < 2; ++i)
//	{
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
//		HAL_Delay(1000);
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
//		HAL_Delay(1000);
//	}
//
//	for (int i = 0; i < 2; ++i)
//		{
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
//			HAL_Delay(2000);
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
//			HAL_Delay(2000);
//		}

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);

}

void led_long_period(void)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
//	for (int i = 0; i < 4; ++i)
//		{
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
//			HAL_Delay(1000);
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
//			HAL_Delay(1000);
//		}
//
//		for (int i = 0; i < 4; ++i)
//			{
//				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
//				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
//				HAL_Delay(2000);
//				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
//				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
//				HAL_Delay(2000);
//			}
}

uint8_t get_led_blinking_status()
{
	// update_led_blinking();
return led_blinking_status;
}

void update_led_blinking(volatile uint8_t update_request_led_blinking)
{
	led_blinking_status = update_request_led_blinking ;

	//_tIM14counteR = 0;
	//_debounce_time = 0;
	//Debounced_button_state = 0;
	//debounce_timer_disable();
	//timer_disable();

}
