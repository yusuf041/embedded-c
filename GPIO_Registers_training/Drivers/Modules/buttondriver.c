/*
 * buttondriver.c
 *
 *  Created on: Feb 26, 2023
 *      Author: kinan
 */

#include "stm32f0xx_hal.h"

//void button_init(){
//
//	RCC->AHBENR |= (1<<17);
//	GPIOA->MODER &= ~(1<<0);
//	GPIOA->MODER &= ~(1<<1);
//
//}

//int get_button_state(void){
//
//	if (GPIOA->IDR & (1<<0)){
//		return 1;
//	} else {
//		 return 0;
//	}
//}

void button_init_interrupt(){

	// ::: gpıo port A clock enable
	__HAL_RCC_GPIOA_CLK_ENABLE() ;

	// ::: SYSTEM CONFIG CLCOK ENABLE
	__HAL_RCC_SYSCFG_CLK_ENABLE();

	// ::: input setting

	GPIOA->MODER &= ~(1<<0);
	GPIOA->MODER &= ~(1<<1);

	GPIOA->PUPDR &= ~(1<<0); // no pull
	GPIOA->PUPDR &= ~(1<<1); // no pull I NEED TO TRY FOR PULL UP WİTH ANOTHER BUTTON.


	// ::: SYSTEM CONFİG SETTİNG

	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;

	EXTI->IMR |= EXTI_IMR_IM0 ;

	EXTI->RTSR |= EXTI_RTSR_RT0 ;

	// ::: NVİC SETTİNG

	NVIC_SetPriority(EXTI0_1_IRQn, 1);

	NVIC_EnableIRQ(EXTI0_1_IRQn);
}

void EXTI0_1_IRQHandler(void){



if(EXTI_PR_PR0 == 1) {  // (EXTI->PR & EXTI_PR_PR0) == EXTI_PR_PR0

	EXTI->PR |= EXTI_PR_PR0 ;

for (int i=0; i<5 ; i++){

	  GPIOC->ODR &= ~(1 << 8);
		GPIOC->ODR &= ~(1 << 9);
		HAL_Delay(50);
		 GPIOC->ODR |= (1 << 8);
			GPIOC->ODR |= (1 << 9);
				HAL_Delay(50);
}

}

}
