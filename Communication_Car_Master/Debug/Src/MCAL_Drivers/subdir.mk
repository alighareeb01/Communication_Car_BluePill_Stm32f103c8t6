################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL_Drivers/EXTI.c \
../Src/MCAL_Drivers/STM32F103C8T6_RCC.c \
../Src/MCAL_Drivers/USART.c \
../Src/MCAL_Drivers/gpio.c 

OBJS += \
./Src/MCAL_Drivers/EXTI.o \
./Src/MCAL_Drivers/STM32F103C8T6_RCC.o \
./Src/MCAL_Drivers/USART.o \
./Src/MCAL_Drivers/gpio.o 

C_DEPS += \
./Src/MCAL_Drivers/EXTI.d \
./Src/MCAL_Drivers/STM32F103C8T6_RCC.d \
./Src/MCAL_Drivers/USART.d \
./Src/MCAL_Drivers/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL_Drivers/%.o Src/MCAL_Drivers/%.su Src/MCAL_Drivers/%.cyclo: ../Src/MCAL_Drivers/%.c Src/MCAL_Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL_Drivers

clean-Src-2f-MCAL_Drivers:
	-$(RM) ./Src/MCAL_Drivers/EXTI.cyclo ./Src/MCAL_Drivers/EXTI.d ./Src/MCAL_Drivers/EXTI.o ./Src/MCAL_Drivers/EXTI.su ./Src/MCAL_Drivers/STM32F103C8T6_RCC.cyclo ./Src/MCAL_Drivers/STM32F103C8T6_RCC.d ./Src/MCAL_Drivers/STM32F103C8T6_RCC.o ./Src/MCAL_Drivers/STM32F103C8T6_RCC.su ./Src/MCAL_Drivers/USART.cyclo ./Src/MCAL_Drivers/USART.d ./Src/MCAL_Drivers/USART.o ./Src/MCAL_Drivers/USART.su ./Src/MCAL_Drivers/gpio.cyclo ./Src/MCAL_Drivers/gpio.d ./Src/MCAL_Drivers/gpio.o ./Src/MCAL_Drivers/gpio.su

.PHONY: clean-Src-2f-MCAL_Drivers

