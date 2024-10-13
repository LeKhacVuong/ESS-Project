/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BOARD_TEST_LED_Pin GPIO_PIN_13
#define BOARD_TEST_LED_GPIO_Port GPIOC
#define ADC1_LOAD_Pin GPIO_PIN_1
#define ADC1_LOAD_GPIO_Port GPIOA
#define ADC1_BANK_A_Pin GPIO_PIN_2
#define ADC1_BANK_A_GPIO_Port GPIOA
#define ADC1_BANK_B_Pin GPIO_PIN_3
#define ADC1_BANK_B_GPIO_Port GPIOA
#define ADC1_CHARGER_Pin GPIO_PIN_4
#define ADC1_CHARGER_GPIO_Port GPIOA
#define IN_OV_MCU_Pin GPIO_PIN_5
#define IN_OV_MCU_GPIO_Port GPIOA
#define IN_UDV_MCU_Pin GPIO_PIN_6
#define IN_UDV_MCU_GPIO_Port GPIOA
#define IN_OV_BANK_B_Pin GPIO_PIN_7
#define IN_OV_BANK_B_GPIO_Port GPIOA
#define LATCH_AIN1_Pin GPIO_PIN_1
#define LATCH_AIN1_GPIO_Port GPIOB
#define CTRL_LED_100_Pin GPIO_PIN_10
#define CTRL_LED_100_GPIO_Port GPIOB
#define CTRL_LED_50_Pin GPIO_PIN_11
#define CTRL_LED_50_GPIO_Port GPIOB
#define CTRL_LED_0_Pin GPIO_PIN_12
#define CTRL_LED_0_GPIO_Port GPIOB
#define CTRL_LED_CHRGING_Pin GPIO_PIN_13
#define CTRL_LED_CHRGING_GPIO_Port GPIOB
#define CTRL_LED_CHECK_CHRG_Pin GPIO_PIN_14
#define CTRL_LED_CHECK_CHRG_GPIO_Port GPIOB
#define CTRL_FAST_CHG_FET_Pin GPIO_PIN_8
#define CTRL_FAST_CHG_FET_GPIO_Port GPIOA
#define CTRL_100A_CHG_FET_Pin GPIO_PIN_9
#define CTRL_100A_CHG_FET_GPIO_Port GPIOA
#define CTRL_100A_FET_Pin GPIO_PIN_10
#define CTRL_100A_FET_GPIO_Port GPIOA
#define CTRL_200A_FET_Pin GPIO_PIN_11
#define CTRL_200A_FET_GPIO_Port GPIOA
#define IN_UDV_BANK_A_Pin GPIO_PIN_12
#define IN_UDV_BANK_A_GPIO_Port GPIOA
#define LATCH_PWM_Pin GPIO_PIN_3
#define LATCH_PWM_GPIO_Port GPIOB
#define LATCH_AIN2_Pin GPIO_PIN_4
#define LATCH_AIN2_GPIO_Port GPIOB
#define LATCH_STBY_Pin GPIO_PIN_5
#define LATCH_STBY_GPIO_Port GPIOB
#define CTRL_RELAY_EXT_Pin GPIO_PIN_6
#define CTRL_RELAY_EXT_GPIO_Port GPIOB
#define CTRL_WARN_LED_Pin GPIO_PIN_9
#define CTRL_WARN_LED_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern TIM_HandleTypeDef htim2;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
