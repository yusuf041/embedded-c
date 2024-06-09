/*
 * button_driver.c
 *
 *  Created on: May 31, 2024
 *      Author: kinan
 */


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

#include "button_driver.h"



#define led_on 1
#define led_off 0


uint32_t counter_button = 0;
volatile uint32_t speed = 0;

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
	counter_button++;

//		for (int i = 0; i < 5; i++) {
//
//			GPIOC->ODR &= ~(1 << 8);
//			GPIOC->ODR &= ~(1 << 9);
//			HAL_Delay(50);
//			GPIOC->ODR |= (1 << 8);
//			GPIOC->ODR |= (1 << 9);
//			HAL_Delay(50);
//		}

}
//
//switch (counter_button) {
//	case 1:
//		speed = 2;
//		break;
//
//	case 2:
//			speed = 3;
//			break;
//
//	case 3:
//			speed = 4;
//			break;
//	default:
//		speed=1;
//		break;
//}
//
//if(counter_button >= 3)
//{
//	counter_button = 0;
//}

}

int button_get_state(void)
{

	if((GPIOA->IDR & (1<<0)) == led_on)
		{
			return led_on;
		}
	else
	{
		return led_off;
	}

}


