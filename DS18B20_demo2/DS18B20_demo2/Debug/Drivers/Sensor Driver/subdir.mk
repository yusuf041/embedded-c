################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Sensor\ Driver/ds18b20.c 

OBJS += \
./Drivers/Sensor\ Driver/ds18b20.o 

C_DEPS += \
./Drivers/Sensor\ Driver/ds18b20.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Sensor\ Driver/ds18b20.o: ../Drivers/Sensor\ Driver/ds18b20.c Drivers/Sensor\ Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"../Drivers/Sensor Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/Sensor Driver/ds18b20.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Sensor-20-Driver

clean-Drivers-2f-Sensor-20-Driver:
	-$(RM) ./Drivers/Sensor\ Driver/ds18b20.cyclo ./Drivers/Sensor\ Driver/ds18b20.d ./Drivers/Sensor\ Driver/ds18b20.o ./Drivers/Sensor\ Driver/ds18b20.su

.PHONY: clean-Drivers-2f-Sensor-20-Driver

