################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER2/subdir.mk
-include MCAL/TIMER1/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/ULTRASONIC/subdir.mk
-include HAL/SIM808/subdir.mk
-include HAL/SERVO/subdir.mk
-include HAL/DC_MOTOR/subdir.mk
-include APP/subdir.mk
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
55-Last_Test_IMT_Project.lss \

FLASH_IMAGE += \
55-Last_Test_IMT_Project.hex \

EEPROM_IMAGE += \
55-Last_Test_IMT_Project.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 55-Last_Test_IMT_Project.elf secondary-outputs

# Tool invocations
55-Last_Test_IMT_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,55-Last_Test_IMT_Project.map -mmcu=atmega32 -o "55-Last_Test_IMT_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

55-Last_Test_IMT_Project.lss: 55-Last_Test_IMT_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 55-Last_Test_IMT_Project.elf  >"55-Last_Test_IMT_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

55-Last_Test_IMT_Project.hex: 55-Last_Test_IMT_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 55-Last_Test_IMT_Project.elf  "55-Last_Test_IMT_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

55-Last_Test_IMT_Project.eep: 55-Last_Test_IMT_Project.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 55-Last_Test_IMT_Project.elf  "55-Last_Test_IMT_Project.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 55-Last_Test_IMT_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 55-Last_Test_IMT_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 55-Last_Test_IMT_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
