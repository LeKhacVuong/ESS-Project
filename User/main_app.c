/*
 * main_app.c
 *
 *  Created on: Oct 13, 2024
 *      Author: lekhacvuong
 */
#include "main_app.h"
#include "main.h"

#include "sm_elapsed_timer.h"

enum{
	ADC_LOAD = 0,
	ADC_BANK_A,
	ADC_BANK_B,
	ADC_CHG,
	ADC_NUMBER
}ADC_ENUM;

uint32_t g_adc_value[ADC_NUMBER];

int64_t get_tick_count(){
	return HAL_GetTick();
}

void main_app(){
	HAL_ADC_Start_DMA(&hadc1, g_adc_value, ADC_NUMBER);
	while(1);
}

void SysTick_Handler(void)
{

  HAL_IncTick();
  if(uwTick % 500 == 0){
	  HAL_GPIO_TogglePin(BOARD_TEST_LED_GPIO_Port, BOARD_TEST_LED_Pin);
  }

}

