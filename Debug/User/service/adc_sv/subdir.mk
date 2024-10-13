################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/service/adc_sv/adc_sv.c 

OBJS += \
./User/service/adc_sv/adc_sv.o 

C_DEPS += \
./User/service/adc_sv/adc_sv.d 


# Each subdirectory must supply rules for building sources it contributes
User/service/adc_sv/%.o User/service/adc_sv/%.su User/service/adc_sv/%.cyclo: ../User/service/adc_sv/%.c User/service/adc_sv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/lekhacvuong/STM32CubeIDE/workspace_1.14.0/project_heat/User" -I"/home/lekhacvuong/STM32CubeIDE/workspace_1.14.0/project_heat/User/utils" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User-2f-service-2f-adc_sv

clean-User-2f-service-2f-adc_sv:
	-$(RM) ./User/service/adc_sv/adc_sv.cyclo ./User/service/adc_sv/adc_sv.d ./User/service/adc_sv/adc_sv.o ./User/service/adc_sv/adc_sv.su

.PHONY: clean-User-2f-service-2f-adc_sv

