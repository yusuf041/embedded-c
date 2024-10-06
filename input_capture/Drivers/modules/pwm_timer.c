/*
 * pwm_timer.c
 *
 *  Created on: Sep 17, 2024
 *      Author: yusuf
 */

#include "pwm_timer.h"


void pwm_timer_init(void);
void pwm_timer_gpıo_init(void);
void pwm_start(void);
void pwm_stop(void);


void pwm_timer_init(void)    // TIM3
{

pwm_timer_gpıo_init();

__HAL_RCC_TIM3_CLK_ENABLE();
// RCC->APB1ENR |= (1<<1) ;   //TIM3 Clock Enabled

TIM3->PSC = 47; // 48.000.000 / 47 => 1.000.000 Hz -> 1MHz sinyal

TIM3->ARR = 99; // 1.000.000 / 100 => 10.000 Hz -> 10KHz sinyal 10ms

TIM3->CCR1 = 49; // 1. KANAL %50 DUTY
TIM3->CCR2 = 40;
TIM3->CCR3 = 70;
TIM3->CCR4 = 9;

TIM3->CCMR1 |= (1<<6);         //PWM MODE channel 1
TIM3->CCMR1 |= (1<<5);
TIM3->CCMR1 &= ~(1<<4);

TIM3->CCMR1 |= (1<<14);         //PWM MODE channel 2
TIM3->CCMR1 |= (1<<13);
TIM3->CCMR1 &= ~(1<<12);

TIM3->CCMR2 |= (1<<6);         //PWM MODE channel 3
TIM3->CCMR2 |= (1<<5);
TIM3->CCMR2 &= ~(1<<4);

TIM3->CCMR2 |= (1<<14);         //PWM MODE channel 4
TIM3->CCMR2 |= (1<<13);
TIM3->CCMR2 &= ~(1<<12);


TIM3->CCER |= (1<<0);   //CAPTURE COMPARE  CHANNEL ENABLE
TIM3->CCER |= (1<<4);
TIM3->CCER |= (1<<8);
TIM3->CCER |= (1<<12);

}

void pwm_start(void)
{

TIM3->EGR |= (1<<0);   //update event generation eneble
TIM3->CR1 |= (1<<0);    // counter enable

}

void pwm_stop(void)
{

TIM3->CR1 &= ~(1<<0);  // counter disable

}

void pwm_timer_gpıo_init(void)
{

/*  TIM3 PA6 & PA7 to AF1   */
/*  TIM3 PB4 & PB5 to AF1   */

// PA6 has to be set AF1

RCC->AHBENR |= (1<<17);   //A clock enable

GPIOA->MODER |= (1<<13);   //MODE AF PA6
GPIOA->MODER &= ~(1<<12);

GPIOA->OTYPER &= (1<<6);  // OUTPUT PUSHPULL

GPIOA->PUPDR &= ~(1<<12); // no pull up no pull down
GPIOA->PUPDR &= ~(1<<13);

GPIOA->OSPEEDR |= (1<<12);   //HIGH speed
GPIOA->OSPEEDR |= (1<<13);

GPIOA->AFR[0] &= ~(1<<27);  //Alternative Function Register set as AF1
GPIOA->AFR[0] &= ~(1<<26);
GPIOA->AFR[0] &= ~(1<<25);
GPIOA->AFR[0] |=  (1<<24);

/*pb1   */

RCC->AHBENR |= (1<<18);

GPIOB->MODER |= (1<<3);   //MODE AF PB1
GPIOB->MODER &= ~(1<<2);

GPIOB->OTYPER &= (1<<1);  // OUTPUT PUSHPULL

GPIOB->PUPDR &= ~(1<<2); // no pull up no pull down
GPIOB->PUPDR &= ~(1<<3);

GPIOB->OSPEEDR |= (1<<2);   //HIGH speed
GPIOB->OSPEEDR |= (1<<3);

GPIOB->AFR[0] &= ~(1<<7);  //Alternative Function Register set as AF1
GPIOB->AFR[0] &= ~(1<<6);
GPIOB->AFR[0] &= ~(1<<5);
GPIOB->AFR[0] |=  (1<<4);


/*  PA7  */

GPIOA->MODER |= (1<<15);   //MODE AF PA7
GPIOA->MODER &= ~(1<<14);

GPIOA->OTYPER &= (1<<7);  // OUTPUT PUSHPULL

GPIOA->PUPDR &= ~(1<<15); // no pull up no pull down
GPIOA->PUPDR &= ~(1<<14);

GPIOA->OSPEEDR |= (1<<15);   //HIGH speed
GPIOA->OSPEEDR |= (1<<14);

GPIOA->AFR[0] &= ~(1<<31);  //Alternative Function Register set as AF1
GPIOA->AFR[0] &= ~(1<<30);
GPIOA->AFR[0] &= ~(1<<29);
GPIOA->AFR[0] |=  (1<<28);

}

