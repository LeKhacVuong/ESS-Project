################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/service/io_sv/io_sv.c 

OBJS += \
./User/service/io_sv/io_sv.o 

C_DEPS += \
./User/service/io_sv/io_sv.d 


# Each subdirectory must supply rules for building sources it contributes
User/service/io_sv/%.o User/service/io_sv/%.su User/service/io_sv/%.cyclo: ../User/service/io_sv/%.c User/service/io_sv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/lekhacvuong/Desktop/ESS-Project/User" -I"/home/lekhacvuong/Desktop/ESS-Project/User/utils" -I"/home/lekhacvuong/Desktop/ESS-Project/User/service/io_sv" -I"/home/lekhacvuong/Desktop/ESS-Project/User/service/adc_sv" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User-2f-service-2f-io_sv

clean-User-2f-service-2f-io_sv:
	-$(RM) ./User/service/io_sv/io_sv.cyclo ./User/service/io_sv/io_sv.d ./User/service/io_sv/io_sv.o ./User/service/io_sv/io_sv.su

.PHONY: clean-User-2f-service-2f-io_sv

