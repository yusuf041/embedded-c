/*
 * button_driver.c
 *
 *  Created on: Jan 4, 2023
 *      Author: kinan
 */

#include "button_driver.h"
#include "led_driver.h"
#include "stm32f0xx_hal.h"

/*
void button_driver_init(){
	RCC->AHBENR |= (1<<0);
	GPIOA->MODER &= ~(1<<0);
	GPIOA->MODER &= ~(1<<1);
}
*/

void button_driver_ext_init(){
// FİRST ONE CLOCK SETTİNG

	  __HAL_RCC_GPIOA_CLK_ENABLE();

	  // SYSTEM CLOCK SETTİNG
	  __HAL_RCC_SYSCFG_CLK_ENABLE();

	  // GPIO SETTİNG.
	  GPIOA->MODER &= ~(1<<0);
	  GPIOA->MODER &= ~(1<<1);

	  GPIOA->PUPDR &= ~(1<<0);
	  GPIOA->PUPDR &= ~(1<<1);
	  // EXT SETTİNG

// 	  SYSCFG->EXTICR[1] &= ~(1<<SYSCFG_EXTICR1_EXTI0_PA) ;

	  SYSCFG->EXTICR[0] &= ~(0xf<<4);

	 EXTI->IMR |= (1<<0);

	 EXTI->RTSR |= (1<<0);

	 // NVİC SETTİNGS

	 NVIC_SetPriority(EXTI0_1_IRQn, 1);
	 NVIC_EnableIRQ(EXTI0_1_IRQn);

}
/*
int get_button_state(){
	if(GPIOA->IDR & (1<<0)){
		return 1;
	} else {
		return 0;
	}
}
*/

void EXTI0_1_IRQHandler(void){




	// if((EXTI->PR & EXTI_PR_PR0) == EXTI_PR_PR0 )
	if (EXTI_PR_PR0 == 1){

		EXTI->PR |= (1<<0);
	//	GPIOC->ODR ^= GPIO_PIN_8 ;
	//  GPIOC->ODR ^= GPIO_PIN_9 ;

		GPIOC->ODR |= (1<<9) ;
		HAL_Delay(500);
		GPIOC->ODR &= ~(1<<9) ;
		HAL_Delay(500);

	}


}


