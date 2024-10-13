################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/utils/sm_logger.c 

OBJS += \
./User/utils/sm_logger.o 

C_DEPS += \
./User/utils/sm_logger.d 


# Each subdirectory must supply rules for building sources it contributes
User/utils/%.o User/utils/%.su User/utils/%.cyclo: ../User/utils/%.c User/utils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/lekhacvuong/STM32CubeIDE/workspace_1.14.0/project_heat/User" -I"/home/lekhacvuong/STM32CubeIDE/workspace_1.14.0/project_heat/User/utils" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User-2f-utils

clean-User-2f-utils:
	-$(RM) ./User/utils/sm_logger.cyclo ./User/utils/sm_logger.d ./User/utils/sm_logger.o ./User/utils/sm_logger.su

.PHONY: clean-User-2f-utils

