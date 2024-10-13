/*
 * adc_sv.h
 *
 *  Created on: Oct 13, 2024
 *      Author: lekhacvuong
 */

#ifndef SERVICE_ADC_SV_ADC_SV_H_
#define SERVICE_ADC_SV_ADC_SV_H_

#include "stdint.h"

int32_t adc_sv_init();

uint32_t adc_sv_get_load_vol();

uint32_t adc_sv_get_bank_a_vol();

uint32_t adc_sv_get_bank_b_vol();

uint32_t adc_sv_get_charger_vol();


#endif /* SERVICE_ADC_SV_ADC_SV_H_ */
