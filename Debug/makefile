################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
own_driver_of_lcd.lss \

FLASH_IMAGE += \
own_driver_of_lcd.hex \

EEPROM_IMAGE += \
own_driver_of_lcd.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: own_driver_of_lcd.elf secondary-outputs

# Tool invocations
own_driver_of_lcd.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,own_driver_of_lcd.map -mmcu=atmega32 -o "own_driver_of_lcd.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

own_driver_of_lcd.lss: own_driver_of_lcd.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S own_driver_of_lcd.elf  >"own_driver_of_lcd.lss"
	@echo 'Finished building: $@'
	@echo ' '

own_driver_of_lcd.hex: own_driver_of_lcd.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex own_driver_of_lcd.elf  "own_driver_of_lcd.hex"
	@echo 'Finished building: $@'
	@echo ' '

own_driver_of_lcd.eep: own_driver_of_lcd.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex own_driver_of_lcd.elf  "own_driver_of_lcd.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: own_driver_of_lcd.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 own_driver_of_lcd.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) own_driver_of_lcd.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
