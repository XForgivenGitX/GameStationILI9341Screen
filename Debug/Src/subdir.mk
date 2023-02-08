################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/stm32f1xx_hal_msp.c \
../Src/syscalls.c \
../Src/system_stm32f1xx.c \
../Src/tiny_printf.c 

CPP_SRCS += \
../Src/Open-DSO-150.cpp \
../Src/awrap.cpp \
../Src/capture.cpp \
../Src/control.cpp \
../Src/display.cpp \
../Src/encoder.cpp \
../Src/interface.cpp \
../Src/io.cpp \
../Src/main.cpp \
../Src/stm32f1xx_it.cpp \
../Src/zconfig.cpp 

C_DEPS += \
./Src/stm32f1xx_hal_msp.d \
./Src/syscalls.d \
./Src/system_stm32f1xx.d \
./Src/tiny_printf.d 

OBJS += \
./Src/Open-DSO-150.o \
./Src/awrap.o \
./Src/capture.o \
./Src/control.o \
./Src/display.o \
./Src/encoder.o \
./Src/interface.o \
./Src/io.o \
./Src/main.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f1xx.o \
./Src/tiny_printf.o \
./Src/zconfig.o 

CPP_DEPS += \
./Src/Open-DSO-150.d \
./Src/awrap.d \
./Src/capture.d \
./Src/control.d \
./Src/display.d \
./Src/encoder.d \
./Src/interface.d \
./Src/io.d \
./Src/main.d \
./Src/stm32f1xx_it.d \
./Src/zconfig.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Modules/PROCESS/ -I../Modules/BUTTONS/ -I../Modules/SNAKE/ -I../Src/Adafruit_GFX/ -I../Modules/ -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/PRogElectronic/VScode/Snake_ILI9341/Src/Adafruit_GFX/Fonts" -O1 -ffunction-sections -fdata-sections -fno-exceptions -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m3 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../ButtonsManager/ -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Modules/ -I"D:/PRogElectronic/VScode/Snake_ILI9341/Src/Adafruit_GFX/Fonts" -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Open-DSO-150.d ./Src/Open-DSO-150.o ./Src/Open-DSO-150.su ./Src/awrap.d ./Src/awrap.o ./Src/awrap.su ./Src/capture.d ./Src/capture.o ./Src/capture.su ./Src/control.d ./Src/control.o ./Src/control.su ./Src/display.d ./Src/display.o ./Src/display.su ./Src/encoder.d ./Src/encoder.o ./Src/encoder.su ./Src/interface.d ./Src/interface.o ./Src/interface.su ./Src/io.d ./Src/io.o ./Src/io.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/stm32f1xx_hal_msp.d ./Src/stm32f1xx_hal_msp.o ./Src/stm32f1xx_hal_msp.su ./Src/stm32f1xx_it.d ./Src/stm32f1xx_it.o ./Src/stm32f1xx_it.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/system_stm32f1xx.d ./Src/system_stm32f1xx.o ./Src/system_stm32f1xx.su ./Src/tiny_printf.d ./Src/tiny_printf.o ./Src/tiny_printf.su ./Src/zconfig.d ./Src/zconfig.o ./Src/zconfig.su

.PHONY: clean-Src

