################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/modules/input_capture_timer_driver.c \
../Drivers/modules/pwm_timer.c 

OBJS += \
./Drivers/modules/input_capture_timer_driver.o \
./Drivers/modules/pwm_timer.o 

C_DEPS += \
./Drivers/modules/input_capture_timer_driver.d \
./Drivers/modules/pwm_timer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/modules/%.o Drivers/modules/%.su Drivers/modules/%.cyclo: ../Drivers/modules/%.c Drivers/modules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/modules -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-modules

clean-Drivers-2f-modules:
	-$(RM) ./Drivers/modules/input_capture_timer_driver.cyclo ./Drivers/modules/input_capture_timer_driver.d ./Drivers/modules/input_capture_timer_driver.o ./Drivers/modules/input_capture_timer_driver.su ./Drivers/modules/pwm_timer.cyclo ./Drivers/modules/pwm_timer.d ./Drivers/modules/pwm_timer.o ./Drivers/modules/pwm_timer.su

.PHONY: clean-Drivers-2f-modules

