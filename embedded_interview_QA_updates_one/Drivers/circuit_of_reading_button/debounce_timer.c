/*
 * debounce_timer.c
 *
 *  Created on: Aug 26, 2024
 *      Author: yusuf
 */

#include "debounce_timer.h"
#include "button_driver.h"
#include "timer_driver.h"

extern uint32_t _tIM14counteR;
volatile uint16_t _debounce_time = 0;
volatile uint8_t Debounced_button_state = 0;



void debounce_timer_init(void);
uint8_t after_debouncing_button_state(void);
void debounce_timer_enable(void);
void debounce_timer_disable(void);
void debounce_timer_init(void);


void debounce_timer_init()  //TİM6
{

	__HAL_RCC_TIM6_CLK_ENABLE();

	// RCC->APB1ENR |= (1<<4);

	TIM6->PSC = 47999;    // timer counter cnt period  48.000.000 / 47.999 = 1000hZ -> 1MS
	TIM6->ARR = 99;     // olayın ne zaman kesme üretimesi istenirse ona ayarlanıyor
// 100ms sonra butona basılma durumu kontrol ediliyor.

	TIM6->DIER |= (1<<0);

	HAL_NVIC_EnableIRQ(TIM6_IRQn);
	HAL_NVIC_SetPriority(TIM6_IRQn, 0, 1);

}



uint8_t after_debouncing_button_state(void)
{
	_debounce_time = TIM6->CNT;
return _debounce_time;
}

void debounce_timer_enable(void)
{
	TIM6->CR1 |= (1<<0);
}

void debounce_timer_disable(void)
{
	TIM6->CR1 &= ~(TIM_CR1_CEN);
}

void TIM6_IRQHandler(void)  //  debouncer interrup fonction
{

	if((TIM6->SR & (1<<0)) != RESET)
		{

		TIM6->SR &= ~(1<<0);
			if(get_button_state() != RESET)
			{

				Debounced_button_state = 1;
				debounce_timer_disable();
				timer_enable();
				_tIM14counteR = 0;
			} else {
				Debounced_button_state = 0;
			//	_tIM14counteR = 0;
				debounce_timer_disable();
			}
		}
	else
	{
		TIM6->SR &= ~(1<<0);
		debounce_timer_disable();

			}

//	if(((TIM6->SR & (1<<0)) != RESET) && (get_button_state() != RESET))
//	{
//		TIM6->SR |= (1<<0);
//
//	//	TIM6->SR &= ~(1<<0);
//		_debounce_time++;
//
//		if((get_button_state() != RESET) && (_debounce_time >= 3000))
//		{
//			Debounced_button_state = 1;
//			debounce_timer_disable();
//			timer_enable();
//			_debounce_time = 0;
//			_tIM14counteR = 0;
//		} else if((get_button_state() != RESET) && (_debounce_time <= 3000)){
//			Debounced_button_state = 0;
//			_tIM14counteR = 0;
//		}
//
//	} else if( (TIM6->SR & (1<<0)) != RESET && get_button_state() == RESET)  //guard over interrupt of timer
//	{
//		TIM6->SR &= ~(1<<0);
//		 debounce_timer_disable();
//		 Debounced_button_state = undebounced;
//		 _debounce_time = 0;
//
//	}

}

