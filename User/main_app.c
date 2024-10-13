/*
 * main_app.c
 *
 *  Created on: Oct 13, 2024
 *      Author: lekhacvuong
 */
#include "main_app.h"
#include "main.h"
#include "io_sv.h"
#include "adc_sv.h"
#include "stdbool.h"

#include "sm_elapsed_timer.h"

#define FILTER_COUNT	50

#define SAMPLING_MS		10

int64_t get_tick_count(){
	return HAL_GetTick();
}

typedef enum{
	MODE_BOOST,
	MODE_DISCH,
	MODE_FLAT,
	MODE_NUMBER
}PROCESS_MODE;

PROCESS_MODE g_mode;

bool g_is_firt_time_under_12v = true;

bool g_is_load_lower_12v;
bool g_is_load_upper_16v;
bool g_is_bank_a_lower_15_5v;
bool g_is_bank_b_lower_4v;
bool g_is_load_over_vol;
bool g_is_load_under_vol;
bool g_is_charger_over_vol;
bool g_is_charger_under_vol;



void load_vol_lower_12v_filter(){
	static uint32_t count = 0;

	if(adc_sv_get_load_vol() <= 12000){
		count++;
	}else{
		g_is_load_lower_12v = 0;
		count = 0;
	}

	if(count > FILTER_COUNT){
		g_is_load_lower_12v = true;
	}

}

void load_vol_upper_16v_filter(){
	static uint32_t count = 0;

	if(adc_sv_get_load_vol() >= 16000){
		count++;
	}else{
		g_is_load_upper_16v = 0;
		count = 0;
	}

	if(count > FILTER_COUNT){
		g_is_load_upper_16v = true;
	}
}

void bank_a_vol_lower_16_filter(){
	static uint32_t count = 0;

	if(adc_sv_get_bank_a_vol() <= 15500){
		count++;
	}else{
		g_is_bank_a_lower_15_5v = 0;
		count = 0;
	}

	if(count > FILTER_COUNT){
		g_is_bank_a_lower_15_5v = true;
	}
}

void bank_b_vol_upper_4v_filter(){
	static uint32_t count = 0;

	if(adc_sv_get_bank_b_vol() >= 3950){
		count++;
	}else{
		count = 0;
		g_is_bank_b_lower_4v = false;
	}

	if(count > FILTER_COUNT){
		g_is_bank_b_lower_4v = true;
	}
}

void load_vol_out_range_filter(){
	static uint32_t count = 0;
	uint32_t load_vol = adc_sv_get_load_vol();

	if(load_vol <= 11500 || load_vol >= 16200){
		count++;
	}else{
		count = 0;
		g_is_load_under_vol = false;
		g_is_load_over_vol = false;
	}

	if(count > FILTER_COUNT){
		if(load_vol <= 11500){
			g_is_load_under_vol = true;
		}else{
			g_is_load_over_vol = true;
		}
	}
}


void charger_vol_out_range_filter(){
	static uint32_t count = 0;
	uint32_t charger_vol = adc_sv_get_charger_vol();

	if(charger_vol <= 12000 || charger_vol >= 20000){
		count++;
	}else{
		count = 0;
		g_is_charger_under_vol = false;
		g_is_charger_over_vol = false;
	}

	if(count > FILTER_COUNT){
		if(charger_vol <= 12000){
			g_is_charger_under_vol = true;
		}else{
			g_is_charger_over_vol = true;
		}
	}
}
void control_latch_relay_soc_led_and_status(){
	if(g_is_load_lower_12v){
		io_sv_open_latch();
		io_sv_set_led_status(100);
		g_mode = MODE_DISCH;
	}else if(g_is_load_lower_12v){
		if(g_mode != MODE_BOOST && g_mode != MODE_FLAT && g_is_firt_time_under_12v){
			g_is_firt_time_under_12v = false;
			g_mode = MODE_BOOST;
			io_sv_open_latch();
			io_sv_set_led_status(50);
		}else{
			g_mode = MODE_FLAT;
			io_sv_close_latch();
			io_sv_set_led_status(0);
			io_sv_set_val(IO_CTRL_RELAY_EXT, 1);
			io_sv_set_val(IO_CTRL_WARN_LED, 1);
		}
	}
}

void control_charger_switch_soc_led_set_mode(){
	if(g_is_bank_b_lower_4v){
		if(g_is_bank_a_lower_15_5v){
			io_sv_ctrl_normal_charger(0);
			io_sv_ctrl_fast_charger(1);
		}else{
			io_sv_ctrl_normal_charger(1);
			io_sv_ctrl_fast_charger(0);
			io_sv_set_led_status(100);
		}
	}else{
		io_sv_ctrl_normal_charger(1);
		io_sv_ctrl_fast_charger(0);
	}
}

void monitor_load_charging_vol_set_warn_led(){
	uint8_t err = 0;
	if(g_is_load_over_vol){
		err = 1;
		io_sv_ctrl_normal_charger(0);
		io_sv_ctrl_fast_charger(0);
	}

	if(g_is_charger_over_vol){
		err = 1;
		io_sv_ctrl_normal_charger(0);
		io_sv_ctrl_fast_charger(0);
	}

	if(g_is_load_under_vol){
		err = 1;
		io_sv_ctrl_normal_charger(1);
		io_sv_ctrl_fast_charger(0);
	}

	if(g_is_charger_under_vol){
		err = 1;
		io_sv_ctrl_normal_charger(1);
		io_sv_ctrl_fast_charger(0);
	}

	io_sv_set_val(IO_CTRL_WARN_LED, err);
}

void main_app(){
	adc_sv_init();
	io_sv_init();

	HAL_Delay(500);

	elapsed_timer_t sampling_timer = {.m_duration = SAMPLING_MS, .m_start_time = 0};

	while(1){
		if(!elapsed_timer_get_remain(&sampling_timer)){ // debound 1ms run 1 time
			load_vol_lower_12v_filter();
			load_vol_upper_16v_filter();
			bank_a_vol_lower_16_filter();
			bank_b_vol_upper_4v_filter();
			load_vol_out_range_filter();
			charger_vol_out_range_filter();
			elapsed_timer_reset(&sampling_timer);
		}

		control_latch_relay_soc_led_and_status();
		control_charger_switch_soc_led_set_mode();
		monitor_load_charging_vol_set_warn_led();

		io_sv_process();
	}
}

void SysTick_Handler(void)
{

  HAL_IncTick();
  if(uwTick % 500 == 0){
	  HAL_GPIO_TogglePin(BOARD_TEST_LED_GPIO_Port, BOARD_TEST_LED_Pin);
  }

}

