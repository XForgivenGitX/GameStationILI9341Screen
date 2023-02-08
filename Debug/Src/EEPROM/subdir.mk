################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/EEPROM/eeprom.cpp 

OBJS += \
./Src/EEPROM/eeprom.o 

CPP_DEPS += \
./Src/EEPROM/eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
Src/EEPROM/%.o Src/EEPROM/%.su: ../Src/EEPROM/%.cpp Src/EEPROM/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Modules/PROCESS/ -I../Modules/BUTTONS/ -I../Modules/SNAKE/ -I../Src/Adafruit_GFX/ -I../Modules/ -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/PRogElectronic/VScode/Snake_ILI9341/Src/Adafruit_GFX/Fonts" -O1 -ffunction-sections -fdata-sections -fno-exceptions -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-EEPROM

clean-Src-2f-EEPROM:
	-$(RM) ./Src/EEPROM/eeprom.d ./Src/EEPROM/eeprom.o ./Src/EEPROM/eeprom.su

.PHONY: clean-Src-2f-EEPROM

