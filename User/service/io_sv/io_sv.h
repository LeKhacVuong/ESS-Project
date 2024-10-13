/*
 * io_sv.h
 *
 *  Created on: Oct 13, 2024
 *      Author: lekhacvuong
 */

#ifndef SERVICE_IO_SV_IO_SV_H_
#define SERVICE_IO_SV_IO_SV_H_
#include "stdint.h"

typedef enum{
	IO_CTRL_EN_FAST_CHG_FET,
	IO_CTRL_EN_100A_CHG_FET,
	IO_CTRL_EN_100A_FET,
	IO_CTRL_EN_200A_FET,
	IO_CTRL_WARN_LED,
	IO_CTRL_LED_100,
	IO_CTRL_LED_50,
	IO_CTRL_LED_0,
	IO_CTRL_LED_CHRGING,
	IO_CTRL_LED_CHECK_CHG,
	IO_CTRL_LATCH_ANI1,
	IO_CTRL_LATCH_ANI2,
	IO_CTRL_LATCH_STBY,
	IO_CTRL_LATCH_PWMA,
	IO_CTRL_RELAY_EXT,
	IO_STT_OV_LOAD_MCU,
	IO_STT_UDV_LOAD_MCU,
	IO_STT_OV_BANK_B,
	IO_STT_UDV_BANK_A,
	IO_PIN_NUMBER
}IO_SV_PIN;

int32_t io_sv_init();

int32_t io_sv_set_val(IO_SV_PIN _pin, uint8_t _val);

int32_t io_sv_get_val(IO_SV_PIN _pin);

int32_t io_sv_ctrl_normal_charger(uint8_t _val);

int32_t io_sv_ctrl_fast_charger(uint8_t _val);

int32_t io_sv_set_led_status(uint8_t _val);

int32_t io_sv_open_latch();

int32_t io_sv_close_latch();

int32_t io_sv_process();


#endif /* SERVICE_IO_SV_IO_SV_H_ */
