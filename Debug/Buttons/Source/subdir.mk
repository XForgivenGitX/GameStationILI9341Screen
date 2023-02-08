################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Buttons/Source/ButtonSource.cpp \
../Buttons/Source/HandleSource.cpp 

OBJS += \
./Buttons/Source/ButtonSource.o \
./Buttons/Source/HandleSource.o 

CPP_DEPS += \
./Buttons/Source/ButtonSource.d \
./Buttons/Source/HandleSource.d 


# Each subdirectory must supply rules for building sources it contributes
Buttons/Source/%.o Buttons/Source/%.su: ../Buttons/Source/%.cpp Buttons/Source/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Buttons/Headers/ -I../Buttons/ButtonCore/ -I../Inc -I../Src/ -I../Src/Adafruit_GFX/ -I../Modules/ -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Buttons/ -I"D:/USERS/Downloads/Snake_ILI9341_2023-02-04/Snake_ILI9341_2023-02-04/Src/Adafruit_GFX/Fonts" -O1 -ffunction-sections -fdata-sections -fno-exceptions -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Buttons-2f-Source

clean-Buttons-2f-Source:
	-$(RM) ./Buttons/Source/ButtonSource.d ./Buttons/Source/ButtonSource.o ./Buttons/Source/ButtonSource.su ./Buttons/Source/HandleSource.d ./Buttons/Source/HandleSource.o ./Buttons/Source/HandleSource.su

.PHONY: clean-Buttons-2f-Source

