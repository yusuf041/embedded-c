/*
 * ds18b20.c
 *
 *  Created on: Jan 13, 2025
 *      Author: kinan
 */
#include "ds18b20.h"


extern UART_HandleTypeDef huart1;


uint8_t DS18B20_Init(void);
uint8_t DS18B20_ReadBit(void);
uint8_t DS18B20_ReadByte(void);
void DS18B20_WriteByte(uint8_t);
void DS18B20_SampleTemp(void);
float DS18B20_ReadTemp(void);
void uart_initt(uint32_t baud);



uint8_t DS18B20_Init(void)
{



//	uint8_t ResetByte = 0xF0, PresenceByte;
//
//    uart_initt(9600);
//    // Send reset pulse (0xF0)
//    HAL_UART_Transmit(&huart1, &ResetByte, 1, 1);
//    // Wait for the presence pulse
//    HAL_UART_Receive(&huart1, &PresenceByte, 1, 100);
//    if(PresenceByte != HAL_OK)
//    	{
//    	return -1 ;  // failed occured check connection or configuration
//    	}
//    uart_initt(115200);
//    // Check presence pulse
//    if (PresenceByte == ResetByte) {
//    	return -2; // No response ... check connection
//    }
//
//        return 1; //  presence pulse detected


        uint8_t ResetByte = 0xF0, PresenceByte;
        uart_initt(9600);
           // Send reset pulse (0xF0)
           HAL_UART_Transmit(&huart1, &ResetByte, 1, 1);
           // Wait for the presence pulse
           HAL_UART_Receive(&huart1, &PresenceByte, 1, 1);
           uart_initt(115200);

           // Check presence pulse
           if (PresenceByte != ResetByte){
               return 1; // Presence pulse detected
           }
           else{
               return 0; // No presence pulse detected
           }


}

 uint8_t DS18B20_ReadBit(void)
{
    uint8_t ReadBitCMD = 0xFF;
    uint8_t RxBit;

    // Send Read Bit CMD
    HAL_UART_Transmit(&huart1, &ReadBitCMD, 1, 1);
    // Receive The Bit
    HAL_UART_Receive(&huart1, &RxBit, 1, 1);

    return (RxBit & 0x01);


//    uint8_t ReadBitCMD = 0xFF;
//      uint8_t RxBit;
//
//      // Send Read Bit CMD
//      HAL_UART_Transmit(&huart1, &ReadBitCMD, 1, 1);
//      // Receive The Bit
//      HAL_UART_Receive(&huart1, &RxBit, 1, 1);
//
//      return (RxBit & 0x01);



}

 uint8_t DS18B20_ReadByte(void)
{
    uint8_t RxByte = 0;
    for (uint8_t i = 0; i < 8; i++)
    {
        RxByte >>= 1;
        if (DS18B20_ReadBit())
        {
            RxByte |= 0x80;
        }
    }
    return RxByte;

//    uint8_t RxByte = 0;
//    for (uint8_t i = 0; i < 8; i++)
//    {
//        RxByte >>= 1;
//        if (DS18B20_ReadBit())
//        {
//            RxByte |= 0x80;
//        }
//    }
//    return RxByte;



}

 void DS18B20_WriteByte(uint8_t data)
{
    uint8_t TxBuffer[8];
    for (int i=0; i<8; i++)
    {
      if ((data & (1<<i)) != 0){
          TxBuffer[i] = 0xFF;
      }
      else{
          TxBuffer[i] = 0;
      }
    }
    HAL_UART_Transmit(&huart1, TxBuffer, 8, 10);


//    uint8_t TxBuffer[8];
//        for (int i=0; i<8; i++)
//        {
//          if ((data & (1<<i)) != 0){
//              TxBuffer[i] = 0xFF;
//          }
//          else{
//              TxBuffer[i] = 0;
//          }
//        }
//        HAL_UART_Transmit(&huart1, TxBuffer, 8, 10);


}

void DS18B20_SampleTemp(void)
{
	DS18B20_Init();
    DS18B20_WriteByte(skip_rom_command);  // Skip ROM   (ROM-CMD)
     DS18B20_WriteByte(convert_temprature_value);  // Convert T  (F-CMD)

//
//         DS18B20_Init();
//         DS18B20_WriteByte(0xCC);  // Skip ROM   (ROM-CMD)
//         DS18B20_WriteByte(0x44);  // Convert T  (F-CMD)


}

float DS18B20_ReadTemp(void)
{
    uint8_t Temp_LSB, Temp_MSB;
    int16_t Temp = 0;
    float Temperature;

    DS18B20_Init();
    DS18B20_WriteByte(skip_rom_command);  // Skip ROM         (ROM-CMD)
    DS18B20_WriteByte(read_skratch_pad);  // Read Scratchpad  (F-CMD)
    Temp_LSB = DS18B20_ReadByte();
    Temp_MSB = DS18B20_ReadByte();
    Temp = ((Temp_MSB<<8))|Temp_LSB;
    Temperature = (float)Temp/16.0;

    return Temperature;



//    uint8_t Temp_LSB, Temp_MSB;
//     uint16_t Temp;
//     float Temperature;
//
//     DS18B20_Init();
//     DS18B20_WriteByte(0xCC);  // Skip ROM         (ROM-CMD)
//     DS18B20_WriteByte(0xBE);  // Read Scratchpad  (F-CMD)
//     Temp_LSB = DS18B20_ReadByte();
//     Temp_MSB = DS18B20_ReadByte();
//     Temp = ((Temp_MSB<<8))|Temp_LSB;
//     Temperature = (float)Temp/16.0;
//
//     return Temperature;







}

void uart_initt(uint32_t baud)
{

	  huart1.Instance = USART1;
	  huart1.Init.BaudRate = baud;
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

	   //  Error_Handler();
		  __asm__("NOP");
	  }

}

