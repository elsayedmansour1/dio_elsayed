################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/APP_Smart_Home/APP.c 

OBJS += \
./APP/APP_Smart_Home/APP.o 

C_DEPS += \
./APP/APP_Smart_Home/APP.d 


# Each subdirectory must supply rules for building sources it contributes
APP/APP_Smart_Home/%.o: ../APP/APP_Smart_Home/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


