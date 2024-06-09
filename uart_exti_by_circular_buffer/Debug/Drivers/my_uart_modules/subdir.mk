################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/my_uart_modules/button_driver.c \
../Drivers/my_uart_modules/led_driver.c \
../Drivers/my_uart_modules/uart_driver.c 

OBJS += \
./Drivers/my_uart_modules/button_driver.o \
./Drivers/my_uart_modules/led_driver.o \
./Drivers/my_uart_modules/uart_driver.o 

C_DEPS += \
./Drivers/my_uart_modules/button_driver.d \
./Drivers/my_uart_modules/led_driver.d \
./Drivers/my_uart_modules/uart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/my_uart_modules/%.o Drivers/my_uart_modules/%.su Drivers/my_uart_modules/%.cyclo: ../Drivers/my_uart_modules/%.c Drivers/my_uart_modules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/my_uart_modules -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/my_uart_modules/uart_driver.o: ../Drivers/my_uart_modules/uart_driver.c Drivers/my_uart_modules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/my_uart_modules -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-my_uart_modules

clean-Drivers-2f-my_uart_modules:
	-$(RM) ./Drivers/my_uart_modules/button_driver.cyclo ./Drivers/my_uart_modules/button_driver.d ./Drivers/my_uart_modules/button_driver.o ./Drivers/my_uart_modules/button_driver.su ./Drivers/my_uart_modules/led_driver.cyclo ./Drivers/my_uart_modules/led_driver.d ./Drivers/my_uart_modules/led_driver.o ./Drivers/my_uart_modules/led_driver.su ./Drivers/my_uart_modules/uart_driver.cyclo ./Drivers/my_uart_modules/uart_driver.d ./Drivers/my_uart_modules/uart_driver.o ./Drivers/my_uart_modules/uart_driver.su

.PHONY: clean-Drivers-2f-my_uart_modules

