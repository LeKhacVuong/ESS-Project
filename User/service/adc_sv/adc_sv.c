/*
 * adc_sv.c
 *
 *  Created on: Oct 13, 2024
 *      Author: lekhacvuong
 */

#include "adc_sv.h"
#include "main.h"

#define MCU_VREF 		3300
#define ADC_RESOLUTIN 	4095

enum{
	ADC_LOAD = 0,
	ADC_BANK_A,
	ADC_BANK_B,
	ADC_CHG,
	ADC_NUMBER
}ADC_ENUM;

static uint32_t g_adc_value[ADC_NUMBER];

int32_t adc_sv_init(){
	HAL_ADC_Start_DMA(&hadc1, g_adc_value, ADC_NUMBER);
	return 0;
}


uint32_t adc_sv_get_load_vol(){
	uint32_t adc_vol = g_adc_value[ADC_LOAD] * MCU_VREF / ADC_RESOLUTIN;
	return adc_vol * (10 + 54) / 10;
}

uint32_t adc_sv_get_bank_a_vol(){
	uint32_t adc_vol = g_adc_value[ADC_BANK_A] * MCU_VREF / ADC_RESOLUTIN;
	return adc_vol * (10 + 52) / 10;
}

uint32_t adc_sv_get_bank_b_vol(){
	uint32_t adc_vol = g_adc_value[ADC_BANK_B] * MCU_VREF / ADC_RESOLUTIN;
	return adc_vol * (64 + 37) / 64;
}

uint32_t adc_sv_get_charger_vol(){
	uint32_t adc_vol = g_adc_value[ADC_BANK_B] * MCU_VREF / ADC_RESOLUTIN;
	return adc_vol * (10 + 49) / 10;
}

