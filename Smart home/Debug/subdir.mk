################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../buzzer.c \
../dc_motor.c \
../flame.c \
../gpio.c \
../lcd.c \
../ldr.c \
../leds.c \
../lm35_sensor.c \
../miniproject3.c \
../pwm.c 

OBJS += \
./adc.o \
./buzzer.o \
./dc_motor.o \
./flame.o \
./gpio.o \
./lcd.o \
./ldr.o \
./leds.o \
./lm35_sensor.o \
./miniproject3.o \
./pwm.o 

C_DEPS += \
./adc.d \
./buzzer.d \
./dc_motor.d \
./flame.d \
./gpio.d \
./lcd.d \
./ldr.d \
./leds.d \
./lm35_sensor.d \
./miniproject3.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


