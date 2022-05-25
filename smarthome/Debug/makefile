################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include RUN_MAIN/subdir.mk
-include MCAL/WATCH_DOG/subdir.mk
-include MCAL/TIMER1/Source/subdir.mk
-include MCAL/I2C/src/subdir.mk
-include MCAL/GIE/Source/subdir.mk
-include MCAL/EXT_INTERRUPTS/src/subdir.mk
-include MCAL/EEPROM/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include MCAL/ADC/subdir.mk
-include EHAL/TEMP_SENSOR/src/subdir.mk
-include EHAL/SEVEN-SEGMINT/Source/subdir.mk
-include EHAL/SERVO/subdir.mk
-include EHAL/LED/Source/subdir.mk
-include EHAL/LDR/subdir.mk
-include EHAL/LCD/Source/subdir.mk
-include EHAL/KEYBAD/Source/subdir.mk
-include EHAL/EXT_EEPROM/src/subdir.mk
-include EHAL/DC/subdir.mk
-include EHAL/BUZZER/subdir.mk
-include APP/APP_Smart_Home/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SMART_HOME_TEST2_2022.lss \

FLASH_IMAGE += \
SMART_HOME_TEST2_2022.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SMART_HOME_TEST2_2022.elf secondary-outputs

# Tool invocations
SMART_HOME_TEST2_2022.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SMART_HOME_TEST2_2022.map -mmcu=atmega32 -o "SMART_HOME_TEST2_2022.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SMART_HOME_TEST2_2022.lss: SMART_HOME_TEST2_2022.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SMART_HOME_TEST2_2022.elf  >"SMART_HOME_TEST2_2022.lss"
	@echo 'Finished building: $@'
	@echo ' '

SMART_HOME_TEST2_2022.hex: SMART_HOME_TEST2_2022.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SMART_HOME_TEST2_2022.elf  "SMART_HOME_TEST2_2022.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SMART_HOME_TEST2_2022.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SMART_HOME_TEST2_2022.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SMART_HOME_TEST2_2022.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
