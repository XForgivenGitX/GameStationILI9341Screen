################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Modules/SNAKE/Src/SnakeLogic.cpp \
../Modules/SNAKE/Src/SnakeTask.cpp 

OBJS += \
./Modules/SNAKE/Src/SnakeLogic.o \
./Modules/SNAKE/Src/SnakeTask.o 

CPP_DEPS += \
./Modules/SNAKE/Src/SnakeLogic.d \
./Modules/SNAKE/Src/SnakeTask.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/SNAKE/Src/%.o Modules/SNAKE/Src/%.su: ../Modules/SNAKE/Src/%.cpp Modules/SNAKE/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Modules/PROCESS/ -I../Modules/BUTTONS/ -I../Modules/SNAKE/ -I../Src/Adafruit_GFX/ -I../Modules/ -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/[PROJECTS]/[DISPLAY_ILI9341_STM32F103]/Snake_ILI9341_2023-02-04/Src/Adafruit_GFX/Fonts" -O1 -ffunction-sections -fdata-sections -fno-exceptions -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modules-2f-SNAKE-2f-Src

clean-Modules-2f-SNAKE-2f-Src:
	-$(RM) ./Modules/SNAKE/Src/SnakeLogic.d ./Modules/SNAKE/Src/SnakeLogic.o ./Modules/SNAKE/Src/SnakeLogic.su ./Modules/SNAKE/Src/SnakeTask.d ./Modules/SNAKE/Src/SnakeTask.o ./Modules/SNAKE/Src/SnakeTask.su

.PHONY: clean-Modules-2f-SNAKE-2f-Src

