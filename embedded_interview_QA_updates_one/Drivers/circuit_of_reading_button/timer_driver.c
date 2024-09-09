/*
 * timer_drriver.c
 *
 *  Created on: Aug 25, 2024
 *      Author: yusuf
 */


#include "timer_driver.h"
#include "led_driver.h"
#include"button_driver.h"

extern uint16_t _debounce_time;
extern uint8_t Debounced_button_state;
volatile uint32_t _tIM14counteR = 0;



void timer_init(void);
void timer_enable(void);
void timer_disable(void);
void set_timer_period(uint16_t set_time);
uint16_t get_timer_period(void);


void timer_init(void)
{

	 __HAL_RCC_TIM14_CLK_ENABLE();

// RCC->APB1ENR |= (1<<8);

TIM14->PSC = 47999; // 48.000.000 / 47999 =1000khz => 1ms
TIM14->ARR = 1;   // HER 2 MS DE BİR KESME OLACAK 0 yazınca timer kesmeden çıkmıyor sapıtıyor

TIM14->DIER |= (1<<0);


HAL_NVIC_EnableIRQ(TIM14_IRQn);
HAL_NVIC_SetPriority(TIM14_IRQn, 1, 0);

}

void timer_enable(void)
{

	TIM14->CR1 |= (1<<0);
}

void timer_disable(void)
{
	TIM14->CR1 &= ~(1<<0);

}


//uint16_t get_timer_period(void)
//{
//	// _tIM14counteR = TIM14->CNT;
//	return _tIM14counteR;
//}

void TIM14_IRQHandler(void)
{
	// 1MS DE KESME MEYDANA GELDİĞİ KONTROLÜ

	if((TIM14->SR & (1<<0)) != RESET  && get_button_state() != RESET )
	{

		TIM14->SR &= ~(1<<0);
		Debounced_button_state = 0;
		_tIM14counteR++;
		// _debounce_time = 0;
		// debounce_timer_disable();

	} else if((TIM14->SR & (1<<0)) != RESET  && get_button_state() == RESET){
		 TIM14->SR &= ~(1<<0);
		timer_disable();

	}

}

