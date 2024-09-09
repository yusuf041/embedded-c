################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/circuit_of_reading_button/button_driver.c \
../Drivers/circuit_of_reading_button/debounce_timer.c \
../Drivers/circuit_of_reading_button/led_driver.c \
../Drivers/circuit_of_reading_button/timer_driver.c 

OBJS += \
./Drivers/circuit_of_reading_button/button_driver.o \
./Drivers/circuit_of_reading_button/debounce_timer.o \
./Drivers/circuit_of_reading_button/led_driver.o \
./Drivers/circuit_of_reading_button/timer_driver.o 

C_DEPS += \
./Drivers/circuit_of_reading_button/button_driver.d \
./Drivers/circuit_of_reading_button/debounce_timer.d \
./Drivers/circuit_of_reading_button/led_driver.d \
./Drivers/circuit_of_reading_button/timer_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/circuit_of_reading_button/%.o Drivers/circuit_of_reading_button/%.su Drivers/circuit_of_reading_button/%.cyclo: ../Drivers/circuit_of_reading_button/%.c Drivers/circuit_of_reading_button/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/circuit_of_reading_button -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-circuit_of_reading_button

clean-Drivers-2f-circuit_of_reading_button:
	-$(RM) ./Drivers/circuit_of_reading_button/button_driver.cyclo ./Drivers/circuit_of_reading_button/button_driver.d ./Drivers/circuit_of_reading_button/button_driver.o ./Drivers/circuit_of_reading_button/button_driver.su ./Drivers/circuit_of_reading_button/debounce_timer.cyclo ./Drivers/circuit_of_reading_button/debounce_timer.d ./Drivers/circuit_of_reading_button/debounce_timer.o ./Drivers/circuit_of_reading_button/debounce_timer.su ./Drivers/circuit_of_reading_button/led_driver.cyclo ./Drivers/circuit_of_reading_button/led_driver.d ./Drivers/circuit_of_reading_button/led_driver.o ./Drivers/circuit_of_reading_button/led_driver.su ./Drivers/circuit_of_reading_button/timer_driver.cyclo ./Drivers/circuit_of_reading_button/timer_driver.d ./Drivers/circuit_of_reading_button/timer_driver.o ./Drivers/circuit_of_reading_button/timer_driver.su

.PHONY: clean-Drivers-2f-circuit_of_reading_button

