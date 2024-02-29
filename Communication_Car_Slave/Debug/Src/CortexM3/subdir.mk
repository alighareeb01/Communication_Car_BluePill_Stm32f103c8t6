################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CortexM3/CortexM3_NVIC.c \
../Src/CortexM3/CortexM3_SCB.c \
../Src/CortexM3/CortexM3_SysTick.c 

OBJS += \
./Src/CortexM3/CortexM3_NVIC.o \
./Src/CortexM3/CortexM3_SCB.o \
./Src/CortexM3/CortexM3_SysTick.o 

C_DEPS += \
./Src/CortexM3/CortexM3_NVIC.d \
./Src/CortexM3/CortexM3_SCB.d \
./Src/CortexM3/CortexM3_SysTick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CortexM3/%.o Src/CortexM3/%.su Src/CortexM3/%.cyclo: ../Src/CortexM3/%.c Src/CortexM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-CortexM3

clean-Src-2f-CortexM3:
	-$(RM) ./Src/CortexM3/CortexM3_NVIC.cyclo ./Src/CortexM3/CortexM3_NVIC.d ./Src/CortexM3/CortexM3_NVIC.o ./Src/CortexM3/CortexM3_NVIC.su ./Src/CortexM3/CortexM3_SCB.cyclo ./Src/CortexM3/CortexM3_SCB.d ./Src/CortexM3/CortexM3_SCB.o ./Src/CortexM3/CortexM3_SCB.su ./Src/CortexM3/CortexM3_SysTick.cyclo ./Src/CortexM3/CortexM3_SysTick.d ./Src/CortexM3/CortexM3_SysTick.o ./Src/CortexM3/CortexM3_SysTick.su

.PHONY: clean-Src-2f-CortexM3

