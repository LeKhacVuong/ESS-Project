/*
 * io_sv.c
 *
 *  Created on: Oct 13, 2024
 *      Author: lekhacvuong
 */

#include "io_sv.h"
#include "main.h"
#include "sm_elapsed_timer.h"

elapsed_timer_t g_latch_off_timer = {.m_duration = 500, .m_start_time = 0};
uint8_t g_is_wait_latch_off = 0;

int32_t io_sv_init(){
	io_sv_set_val(IO_CTRL_EN_100A_FET, 1);
	io_sv_set_val(IO_CTRL_EN_200A_FET, 1);

	return 0;
}

int32_t io_sv_set_val(IO_SV_PIN _pin, uint8_t _val){
	switch (_pin) {
		case IO_CTRL_EN_FAST_CHG_FET:
			HAL_GPIO_WritePin(CTRL_FAST_CHG_FET_GPIO_Port, CTRL_FAST_CHG_FET_Pin, _val);
			break;
		case IO_CTRL_EN_100A_CHG_FET:
			HAL_GPIO_WritePin(CTRL_100A_CHG_FET_GPIO_Port, CTRL_100A_CHG_FET_Pin, _val);
			break;
		case IO_CTRL_EN_100A_FET:
			HAL_GPIO_WritePin(CTRL_100A_FET_GPIO_Port, CTRL_100A_FET_Pin, _val);
			break;
		case IO_CTRL_EN_200A_FET:
			HAL_GPIO_WritePin(CTRL_200A_FET_GPIO_Port, CTRL_200A_FET_Pin, _val);
			break;
		case IO_CTRL_WARN_LED:
			HAL_GPIO_WritePin(CTRL_WARN_LED_GPIO_Port, CTRL_WARN_LED_Pin, _val);
			break;
		case IO_CTRL_LED_100:
			HAL_GPIO_WritePin(CTRL_LED_100_GPIO_Port, CTRL_LED_100_Pin, _val);
			break;
		case IO_CTRL_LED_50:
			HAL_GPIO_WritePin(CTRL_LED_50_GPIO_Port, CTRL_LED_50_Pin, _val);
			break;
		case IO_CTRL_LED_0:
			HAL_GPIO_WritePin(CTRL_LED_0_GPIO_Port, CTRL_LED_0_Pin, _val);
			break;
		case IO_CTRL_LED_CHRGING:
			HAL_GPIO_WritePin(CTRL_LED_CHRGING_GPIO_Port, CTRL_LED_CHRGING_Pin, _val);
			break;
		case IO_CTRL_LED_CHECK_CHG:
			HAL_GPIO_WritePin(CTRL_LED_CHECK_CHRG_GPIO_Port, CTRL_LED_CHECK_CHRG_Pin, _val);
			break;
		case IO_CTRL_RELAY_EXT:
			HAL_GPIO_WritePin(CTRL_RELAY_EXT_GPIO_Port, CTRL_RELAY_EXT_Pin, _val);
			break;
		case IO_CTRL_LATCH_ANI1:
			HAL_GPIO_WritePin(LATCH_AIN1_GPIO_Port, LATCH_AIN1_Pin, _val);
			break;
		case IO_CTRL_LATCH_ANI2:
			HAL_GPIO_WritePin(LATCH_AIN2_GPIO_Port, LATCH_AIN2_Pin, _val);
			break;
		case IO_CTRL_LATCH_STBY:
			HAL_GPIO_WritePin(LATCH_STBY_GPIO_Port, LATCH_STBY_Pin, _val);
			break;
		case IO_CTRL_LATCH_PWMA:
			HAL_GPIO_WritePin(LATCH_PWMA_GPIO_Port, LATCH_PWMA_Pin, _val);
			break;
		default:
			return -1;
			break;
	}
	return 0;
}


int32_t io_sv_get_val(IO_SV_PIN _pin){
	switch (_pin) {
		case IO_CTRL_EN_FAST_CHG_FET:
			return HAL_GPIO_ReadPin(CTRL_FAST_CHG_FET_GPIO_Port, CTRL_FAST_CHG_FET_Pin);
		case IO_CTRL_EN_100A_CHG_FET:
			return HAL_GPIO_ReadPin(CTRL_100A_CHG_FET_GPIO_Port, CTRL_100A_CHG_FET_Pin);
		case IO_CTRL_EN_100A_FET:
			return HAL_GPIO_ReadPin(CTRL_100A_FET_GPIO_Port, CTRL_100A_FET_Pin);
		case IO_CTRL_EN_200A_FET:
			return HAL_GPIO_ReadPin(CTRL_200A_FET_GPIO_Port, CTRL_200A_FET_Pin);
		case IO_CTRL_WARN_LED:
			return HAL_GPIO_ReadPin(CTRL_WARN_LED_GPIO_Port, CTRL_WARN_LED_Pin);
		case IO_CTRL_LED_100:
			return HAL_GPIO_ReadPin(CTRL_LED_100_GPIO_Port, CTRL_LED_100_Pin);
		case IO_CTRL_LED_50:
			return HAL_GPIO_ReadPin(CTRL_LED_50_GPIO_Port, CTRL_LED_50_Pin);
		case IO_CTRL_LED_0:
			return HAL_GPIO_ReadPin(CTRL_LED_0_GPIO_Port, CTRL_LED_0_Pin);
		case IO_CTRL_LED_CHRGING:
			return HAL_GPIO_ReadPin(CTRL_LED_CHRGING_GPIO_Port, CTRL_LED_CHRGING_Pin);
		case IO_CTRL_LED_CHECK_CHG:
			return HAL_GPIO_ReadPin(CTRL_LED_CHECK_CHRG_GPIO_Port, CTRL_LED_CHECK_CHRG_Pin);
		case IO_CTRL_RELAY_EXT:
			return HAL_GPIO_ReadPin(CTRL_RELAY_EXT_GPIO_Port, CTRL_RELAY_EXT_Pin);
		case IO_STT_OV_LOAD_MCU:
			return HAL_GPIO_ReadPin(IN_OV_MCU_GPIO_Port, IN_OV_MCU_Pin);
		case IO_STT_UDV_LOAD_MCU:
			return HAL_GPIO_ReadPin(IN_UDV_MCU_GPIO_Port, IN_UDV_MCU_Pin);
		case IO_STT_OV_BANK_B:
			return HAL_GPIO_ReadPin(IN_OV_BANK_B_GPIO_Port, IN_OV_BANK_B_Pin);
		case IO_STT_UDV_BANK_A:
			return HAL_GPIO_ReadPin(IN_UDV_BANK_A_GPIO_Port, IN_UDV_BANK_A_Pin);
		default:
			break;
	}
	return -1;
}

int32_t io_sv_ctrl_normal_charger(uint8_t _val){
	io_sv_set_val(IO_CTRL_EN_100A_CHG_FET, _val);
	io_sv_set_val(IO_CTRL_LED_CHRGING, _val);

	return 0;
}

int32_t io_sv_ctrl_fast_charger(uint8_t _val){
	io_sv_set_val(IO_CTRL_EN_FAST_CHG_FET, _val);
	io_sv_set_val(IO_CTRL_LED_CHECK_CHG, _val);

	return 0;
}

int32_t io_sv_set_led_status(uint8_t _val){
	switch (_val) {
		case 0:
			io_sv_set_val(IO_CTRL_LED_100, 0);
			io_sv_set_val(IO_CTRL_LED_50, 0);
			io_sv_set_val(IO_CTRL_LED_0, 1);
			break;
		case 50:
			io_sv_set_val(IO_CTRL_LED_100, 0);
			io_sv_set_val(IO_CTRL_LED_50, 1);
			io_sv_set_val(IO_CTRL_LED_0, 1);
			break;
		case 100:
			io_sv_set_val(IO_CTRL_LED_100, 1);
			io_sv_set_val(IO_CTRL_LED_50, 1);
			io_sv_set_val(IO_CTRL_LED_0, 1);
			break;
		default:
			break;
	}

	return 0;
}

int32_t io_sv_open_latch(){
	io_sv_set_val(IO_CTRL_LATCH_ANI1, 0);
	io_sv_set_val(IO_CTRL_LATCH_ANI2, 1);
	io_sv_set_val(IO_CTRL_LATCH_PWMA, 1);

	io_sv_set_val(IO_CTRL_LATCH_STBY, 1);

	elapsed_timer_reset(&g_latch_off_timer);
	g_is_wait_latch_off = 1;
	return 0;
}

int32_t io_sv_close_latch(){
	io_sv_set_val(IO_CTRL_LATCH_ANI1, 1);
	io_sv_set_val(IO_CTRL_LATCH_ANI2, 0);
	io_sv_set_val(IO_CTRL_LATCH_PWMA, 1);

	io_sv_set_val(IO_CTRL_LATCH_STBY, 1);

	g_is_wait_latch_off = 1;
	return 0;
}

int32_t io_sv_process(){
	if(g_is_wait_latch_off && !elapsed_timer_get_remain(&g_latch_off_timer)){
		io_sv_set_val(IO_CTRL_LATCH_STBY, 0);

		io_sv_set_val(IO_CTRL_LATCH_ANI1, 0);
		io_sv_set_val(IO_CTRL_LATCH_ANI2, 0);
		io_sv_set_val(IO_CTRL_LATCH_PWMA, 0);
		g_is_wait_latch_off = 0;
	}
	return 0;
}

