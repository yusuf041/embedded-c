/*
 * timer_drriver.c
 *
 *  Created on: Aug 25, 2024
 *      Author: yusuf
 */

#include "input_capture_timer_driver.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_tim.h"


void input_capture_timer_init(void);
void input_capture_timer_enable(void);
void input_capture_timer_disable(void);
void input_capture_timer_gpi0_init(void);


void input_capture_timer_init(void)        /*  TIM2 INPUT CAPTURE MODE   */
{
	input_capture_timer_gpi0_init();

__HAL_RCC_TIM2_CLK_ENABLE();   //tım 2 clock enable


TIM2->PSC = 47; // 48.000 / 47999 : 1000Hz -> 1Khz -> 1ms
TIM2->ARR = 0xffffffff;

TIM2->CR1 &= ~(1<<4);
TIM2->CR1 &= ~(1<<8);
TIM2->CR1 &= ~(1<<9);
TIM2->CR1 &= ~(1<<7);

TIM2->CR2 &= ~(1<<4);
TIM2->CR2 &= ~(1<<5);
TIM2->CR2 &= ~(1<<6);

TIM2->SMCR &= ~TIM_SMCR_MSM;

TIM2->CCER  &= ~(1<<0);

TIM2->CCMR1 |=  (1<<0);      //tım2 ccmr1 register ccs bits 01 yani input tı1 olarak ayarlanıyor
TIM2->CCMR1 &= ~(1<<1);

TIM2->CCMR1 &= ~(1<<2);   // active interrupt both side rising and falling.
TIM2->CCMR1 &= ~(1<<3);

TIM2->CCMR1 |= (1<<4);     /// INPUT FİLTER lenght SET as 8 CLOCK
TIM2->CCMR1 |= (1<<5);
TIM2->CCMR1 &= ~(1<<6);
TIM2->CCMR1 &= ~(1<<7);

TIM2->CCER |= (1<<1);
TIM2->CCER |= (1<<3);

HAL_NVIC_EnableIRQ(TIM2_IRQn);
HAL_NVIC_SetPriority(TIM2_IRQn, 0, 1);

}

void input_capture_timer_enable(void)
{

	TIM2->CR1 |= (1 << 0);
	TIM2->EGR |= (1 << 1);
	TIM2->EGR |= (1 << 0);
	TIM2->CCER |= (1 << 0);
	TIM2->DIER |= (1 << 1);
}
void input_capture_timer_disable(void)
{
	TIM2->CR1 &= ~(1<<0);
}

void input_capture_timer_gpi0_init(void)
{

	RCC->AHBENR |= (1<<17);   //PORT A CLOCK ENABLE
//	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIOA->MODER &= ~(1<<10);   // MODE ALTERNATİVE FUNCTİON
	GPIOA->MODER |= (1<<11);

	 GPIOA->OTYPER &= ~(1<<5);

	GPIOA->OSPEEDR |= (1<<10);   // SPEED high
	GPIOA->OSPEEDR |=  (1<<11);

	GPIOA->PUPDR &= ~(1<<10);   // nol pull up / down
	GPIOA->PUPDR &= ~(1<<11);

	GPIOA->AFR[0] &= ~(1<<23);  // PA5 to AF2   AFSEL5 to af2
	GPIOA->AFR[0] &= ~(1<<22);
	GPIOA->AFR[0] |=  (1<<21);
	GPIOA->AFR[0] &= ~(1<<20);

}

uint32_t IC_Val1=0;
uint32_t IC_Val2=0;
uint32_t Difference=0;
uint8_t Is_First_Captured = 0;
uint32_t usWidth = 0;

float frequency = 0;
float total_perriod = 0;

void TIM2_IRQHandler(void)
{
	  if ((TIM2->SR & (1<<1)) != RESET) { // CC1IF: Capture/Compare 1 interrupt flag

		  if (Is_First_Captured==0) // if the first rising edge is not captured
		  		{
		  			IC_Val1 = TIM2->CCR1 ;  // read the first value
		  			Is_First_Captured = 1;  // set the first captured as true
		  		}

		  		else   // If the first rising edge is captured, now we will capture the second edge
		  		{
		  			IC_Val2 = TIM2->CCR1 ;  // read second value

		  			if (IC_Val2 > IC_Val1)
		  			{
		  				Difference = IC_Val2-IC_Val1;
		  			}

		  			else if (IC_Val1 > IC_Val2)
		  			{
		  				Difference = (0xffffffff - IC_Val1) + IC_Val2;
		  			}

		  			float refClock = TIMCLOCK/(PRESCALAR);
		  			float mFactor = 1000000/refClock;

		  			frequency = refClock/Difference;
		  		    usWidth = Difference * mFactor;

		  			TIM2->CNT  = 0;
		  			Is_First_Captured = 0; // set it back to false
		  		}
	        // Kesme bayrağını sıfırla
	        TIM2->SR &= ~(1 << 1); // CC1IF bayrağını temizle
	    }
	// HAL_TIM_IRQHandler(&htim2);
}


