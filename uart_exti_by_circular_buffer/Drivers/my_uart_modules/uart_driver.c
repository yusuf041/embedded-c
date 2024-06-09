/*
 * uart_driver.c
 *
 *  Created on: May 31, 2024
 *      Author: kinan
 */

#include "uart_driver.h"
#include "led_driver.h"

UART_HandleTypeDef my_uart;

#define buffer_size 256


typedef struct circular_buffer
{

	uint32_t head_pointer;
	uint32_t tail_pointer;
	uint32_t buffer[buffer_size];

}UART_buffer_t;

volatile UART_buffer_t UART_buffer_RX;
volatile UART_buffer_t UART_buffer_TX;



void uart_init(void);
static void UART_Error_Handler(void);
static int32_t UART_is_buffer_empty(volatile UART_buffer_t* buffer);


//volatile uint32_t status_flag = 0;
//volatile uint8_t led_status[10];
// uint32_t counter = 0;


void uart_init(void)

{
	GPIO_InitTypeDef uart_pins;

__HAL_RCC_GPIOA_CLK_ENABLE();
__HAL_RCC_USART2_CLK_ENABLE();


/*   GPIO CONF PA2*/

uart_pins.Alternate = GPIO_AF1_USART2;
uart_pins.Mode = GPIO_MODE_AF_PP;
uart_pins.Pin = GPIO_PIN_2;
uart_pins.Pull = GPIO_NOPULL;
uart_pins.Speed = GPIO_SPEED_FREQ_MEDIUM;
HAL_GPIO_Init(GPIOA, &uart_pins);


/*   GPIO CONF PA3*/
uart_pins.Alternate = GPIO_AF1_USART2;
uart_pins.Mode = GPIO_MODE_AF_PP;
uart_pins.Pin = GPIO_PIN_3;
uart_pins.Pull = GPIO_NOPULL;
uart_pins.Speed = GPIO_SPEED_FREQ_MEDIUM;
HAL_GPIO_Init(GPIOA, &uart_pins);

/*  UART CONFG */

my_uart.Instance = USART2;
my_uart.Init.BaudRate = 9600;
my_uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
my_uart.Init.Mode= UART_MODE_TX_RX;
my_uart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
my_uart.Init.OverSampling = UART_OVERSAMPLING_16;
my_uart.Init.Parity = UART_PARITY_NONE;
my_uart.Init.StopBits = UART_STOPBITS_1;
my_uart.Init.WordLength = UART_WORDLENGTH_8B;
my_uart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

if(HAL_UART_DeInit(&my_uart) != HAL_OK)
 {
   //ERROR
		UART_Error_Handler();
 }

 if(HAL_UART_Init(&my_uart) != HAL_OK)
 {
		//ERROR
   UART_Error_Handler();
 }


USART2->CR1 |= (1<<5);   //rx interrupt enable

HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
HAL_NVIC_EnableIRQ(USART2_IRQn);

}


static void UART_Error_Handler(void)
{
     while(1)
    {

    }
}


int __io_putchar(int ch)
{
	UART_send_byte(ch);
	  return ch;
}


void USART2_IRQHandler(void)

{
	// RX ile ile ilgili kesme var.

	if((USART2->ISR & USART_ISR_RXNE) != RESET && (USART2->CR1 & USART_CR1_RXNEIE) != RESET)
	{
//		led_status[counter] = USART2->RDR ;
//		counter++;
////	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
////	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
//
//		if(counter == 6)
//		{
//			status_flag = 1;
//			counter = 0;
//		}

		UART_buffer_RX.buffer[UART_buffer_RX.head_pointer] = USART2->RDR ;
		UART_buffer_RX.head_pointer ++;
		if(UART_buffer_RX.head_pointer == buffer_size)
		{
			UART_buffer_RX.head_pointer = 0;
		}

		return ;
	}

	// TX ile ile ilgili kesme var.

	if((USART2->ISR & USART_ISR_TXE) != RESET && (USART2->CR1 & USART_CR1_TXEIE) != RESET)
	{
//		led_status[counter] = USART2->RDR ;
//		counter++;
////	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
////	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
//
//		if(counter == 6)
//		{
//			status_flag = 1;
//			counter = 0;
//		}

		if(UART_buffer_TX.head_pointer != UART_buffer_TX.tail_pointer)
			// head pointer should be different than tail
			// because ı need to make sure buffer is full or there is some things

		{
			USART2->TDR = UART_buffer_TX.buffer[UART_buffer_TX.tail_pointer];
			UART_buffer_TX.tail_pointer++;

			if(UART_buffer_TX.tail_pointer == buffer_size)
			{
				UART_buffer_TX.tail_pointer = 0;
			}

		}
		else
		{
			CLEAR_BIT(USART2->CR1,USART_CR1_TXEIE);
		}

		return ;
	}
}

void UART_send_byte(uint8_t data)
{
	UART_buffer_TX.buffer[UART_buffer_TX.head_pointer] = data;
	UART_buffer_TX.head_pointer++;

	if(UART_buffer_TX.head_pointer == buffer_size)
	{
		UART_buffer_TX.head_pointer = 0;
	}

	SET_BIT(USART2->CR1,USART_CR1_TXEIE);


}

static int32_t UART_is_buffer_empty(volatile UART_buffer_t* buffer)
{

	return (buffer->head_pointer == buffer->tail_pointer?1:0);

//	if(buffer->head_pointer == buffer->tail_pointer)
//	{
//		return 1;
//	} else {
//		return 0;
//	}

}

int32_t UART_read_byte(void)
{
	int ch = 0;

	if(UART_is_buffer_empty(&UART_buffer_RX) == 1)
	{
		ch = -1;
	}

	else
	{

		ch = UART_buffer_RX.buffer[UART_buffer_RX.tail_pointer++];
	//	UART_buffer_RX.tail_pointer++;

		if(UART_buffer_RX.tail_pointer == buffer_size)
		{
			UART_buffer_RX.tail_pointer = 0;
		}
	}

	return ch;
}

void UART_send_byte_array(uint8_t* buffer, uint32_t size)
{

	int i;

		for( i=0; i<size; i++)
		{
			UART_send_byte(buffer[i]);
		}

}

uint32_t UART_bytes_to_read(void)
{

	if(UART_buffer_RX.head_pointer >= UART_buffer_RX.tail_pointer)
	{
		return UART_buffer_RX.head_pointer - UART_buffer_RX.tail_pointer;
	}
	else
	{
		return (buffer_size + UART_buffer_RX.head_pointer - UART_buffer_RX.tail_pointer);
	}

}
