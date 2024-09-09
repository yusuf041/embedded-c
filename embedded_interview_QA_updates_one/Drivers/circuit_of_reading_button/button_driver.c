/*
 * button_driver.c
 *
 *  Created on: Aug 20, 2024
 *      Author: yusuf
 */

#include "button_driver.h"
#include "timer_driver.h"
#include "led_driver.h"
#include "debounce_timer.h"


uint8_t  status = 0;

void button_gpio_init(void)
{
__HAL_RCC_GPIOA_CLK_ENABLE();  //A PORT CLOCK ENABLE

GPIOA->MODER &= ~(1<<0);  //PA0 SET as INPUT
GPIOA->MODER &= ~(1<<1);

GPIOA->PUPDR &= ~(1<<0);
GPIOA->PUPDR &= ~(1<<1);

}

void external_interrupt_init(void)
{
	__HAL_RCC_SYSCFG_CLK_ENABLE();

//	SYSCFG->EXTICR[0] &= ~(1<<0); //SYSCNFG configuration register has set as EXTI0 in PA pin.
//	SYSCFG->EXTICR[0] &= ~(1<<1);
//	SYSCFG->EXTICR[0] &= ~(1<<2);
//	SYSCFG->EXTICR[0] &= ~(1<<3);

	SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI0_PA;

	EXTI->IMR |= (1<<0);

	 EXTI->RTSR |= (1<<0);
	// EXTI->FTSR |= (1<<0);

	NVIC_SetPriority(EXTI0_1_IRQn, 2);
	NVIC_EnableIRQ(EXTI0_1_IRQn);

}

// devre dışı

uint8_t get_button_state(void)
{
if((GPIOA->IDR & (1<<0)) != RESET )
{
	status = 1;
} else {
	status = 0;
}

return status;
}


void EXTI0_1_IRQHandler(void)
{

	if( ((EXTI->PR & (1<<0)) != RESET) && (get_button_state() != RESET) )  // rising trigger
	{
		EXTI->PR |= (1<<0);

		 debounce_timer_enable();

	} else {

		EXTI->PR |= (1<<0);
		debounce_timer_disable();
		timer_disable();
	}

}


