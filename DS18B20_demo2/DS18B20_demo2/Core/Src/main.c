/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32f0xx_ll_usart.h"
#include <stdio.h>
#include "ds18b20.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
volatile float DS18B20_Temp=0;
/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */

//static uint8_t DS18B20_Init(void);
//static uint8_t DS18B20_ReadBit(void);
//static uint8_t DS18B20_ReadByte(void);
//static void DS18B20_WriteByte(uint8_t);
//void DS18B20_SampleTemp(void);
//float DS18B20_ReadTemp(void);
//void one_wire_uart_init(uint32_t baud);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//void DS18B20_SampleTemp(void)
//{
//	// DS18B20_Init();
////    DS18B20_WriteByte(skip_rom_command);  // Skip ROM   (ROM-CMD)
////     DS18B20_WriteByte(convert_temprature_value);  // Convert T  (F-CMD)
//
//
//         DS18B20_Init();
//         DS18B20_WriteByte(0xCC);  // Skip ROM   (ROM-CMD)
//         DS18B20_WriteByte(0x44);  // Convert T  (F-CMD)
//
//
//}
//
//static void DS18B20_WriteByte(uint8_t data)
//{
//
//	    uint8_t TxBuffer[8];
//	        for (int i=0; i<8; i++)
//	        {
//	          if ((data & (1<<i)) != 0){
//	              TxBuffer[i] = 0xFF;
//	          }
//	          else{
//	              TxBuffer[i] = 0;
//	          }
//	        }
//	        HAL_UART_Transmit(&huart1, TxBuffer, 8, 10);
//
//}
//
//
//
//static uint8_t DS18B20_ReadBit(void)
//{
//
//
//	    uint8_t ReadBitCMD = 0xFF;
//	      uint8_t RxBit;
//
//	      // Send Read Bit CMD
//	      HAL_UART_Transmit(&huart1, &ReadBitCMD, 1, 1);
//	      // Receive The Bit
//	      HAL_UART_Receive(&huart1, &RxBit, 1, 1);
//
//	      return (RxBit & 0x01);
//
//
//}
//
//
//
//static uint8_t DS18B20_ReadByte(void)
//{
//
//	    uint8_t RxByte = 0;
//	    for (uint8_t i = 0; i < 8; i++)
//	    {
//	        RxByte >>= 1;
//	        if (DS18B20_ReadBit())
//	        {
//	            RxByte |= 0x80;
//	        }
//	    }
//	    return RxByte;
//
//
//}
//
//
//static uint8_t DS18B20_Init(void)
//{
//
//	        uint8_t ResetByte = 0xF0, PresenceByte;
//	           one_wire_uart_init(9600);
//	           // Send reset pulse (0xF0)
//	           HAL_UART_Transmit(&huart1, &ResetByte, 1, 1);
//	           // Wait for the presence pulse
//	           HAL_UART_Receive(&huart1, &PresenceByte, 1, 1);
//	           one_wire_uart_init(115200);
//
//	           // Check presence pulse
//	           if (PresenceByte != ResetByte){
//	               return 1; // Presence pulse detected
//	           }
//	           else{
//	               return 0; // No presence pulse detected
//	           }
//}
//
//float DS18B20_ReadTemp(void)
//{
//	    uint8_t Temp_LSB, Temp_MSB;
//	     uint16_t Temp;
//	     float Temperature;
//
//	     DS18B20_Init();
//	     DS18B20_WriteByte(0xCC);  // Skip ROM         (ROM-CMD)
//	     DS18B20_WriteByte(0xBE);  // Read Scratchpad  (F-CMD)
//	     Temp_LSB = DS18B20_ReadByte();
//	     Temp_MSB = DS18B20_ReadByte();
//	     Temp = ((Temp_MSB<<8))|Temp_LSB;
//	     Temperature = (float)Temp/16.0;
//
//	     return Temperature;
//}
//
////
//void one_wire_uart_init(uint32_t baud)
//{
//
//	  huart1.Instance = USART1;
//	  huart1.Init.BaudRate = baud;
//	  huart1.Init.WordLength = UART_WORDLENGTH_8B;
//	  huart1.Init.StopBits = UART_STOPBITS_1;
//	  huart1.Init.Parity = UART_PARITY_NONE;
//	  huart1.Init.Mode = UART_MODE_TX_RX;
//	  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//	  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
//	  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//	  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
//	  if (HAL_HalfDuplex_Init(&huart1) != HAL_OK)
//	  {
//	    Error_Handler();
//	  }
//
//}



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */


 // determine_resolution_alarms();

  /* USER CODE END 2 */




  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//
	  	  DS18B20_SampleTemp();              	 // Convert (Sample) Temperature Now
	      DS18B20_Temp = DS18B20_ReadTemp(); 	 // Read The Conversion Result Temperature Value
	      HAL_Delay(1000);

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_HalfDuplex_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LD4_Pin|LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD4_Pin LD3_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
