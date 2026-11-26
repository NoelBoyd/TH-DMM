/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

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
#define LSE_OSC_IN_Pin GPIO_PIN_14
#define LSE_OSC_IN_GPIO_Port GPIOC
#define LSE_OSC_OUT_Pin GPIO_PIN_15
#define LSE_OSC_OUT_GPIO_Port GPIOC
#define HSE_OSC_IN_Pin GPIO_PIN_0
#define HSE_OSC_IN_GPIO_Port GPIOH
#define HSE_OSC_OUT_Pin GPIO_PIN_1
#define HSE_OSC_OUT_GPIO_Port GPIOH
#define MON_3V3_PER_VDC_Pin GPIO_PIN_0
#define MON_3V3_PER_VDC_GPIO_Port GPIOC
#define ETH_MDC_Pin GPIO_PIN_1
#define ETH_MDC_GPIO_Port GPIOC
#define MON_12VDC_SUPPLIES_Pin GPIO_PIN_0
#define MON_12VDC_SUPPLIES_GPIO_Port GPIOA
#define ETH_REF_CLK_Pin GPIO_PIN_1
#define ETH_REF_CLK_GPIO_Port GPIOA
#define ETH_MDIO_Pin GPIO_PIN_2
#define ETH_MDIO_GPIO_Port GPIOA
#define MON_5VDC_Pin GPIO_PIN_3
#define MON_5VDC_GPIO_Port GPIOA
#define REF_1V55_Pin GPIO_PIN_4
#define REF_1V55_GPIO_Port GPIOA
#define ETH_CRS_DV_Pin GPIO_PIN_7
#define ETH_CRS_DV_GPIO_Port GPIOA
#define ETH_RXD0_Pin GPIO_PIN_4
#define ETH_RXD0_GPIO_Port GPIOC
#define ETH_RXD1_Pin GPIO_PIN_5
#define ETH_RXD1_GPIO_Port GPIOC
#define DISPLAY_BACKLIGHT_Pin GPIO_PIN_9
#define DISPLAY_BACKLIGHT_GPIO_Port GPIOE
#define DISPLAY_DC_Pin GPIO_PIN_10
#define DISPLAY_DC_GPIO_Port GPIOE
#define DISPLAY_SPI_CS_N_Pin GPIO_PIN_11
#define DISPLAY_SPI_CS_N_GPIO_Port GPIOE
#define DISPLAY_SPI_SCLK_Pin GPIO_PIN_12
#define DISPLAY_SPI_SCLK_GPIO_Port GPIOE
#define DISPLAY_SPI_MISO_Pin GPIO_PIN_13
#define DISPLAY_SPI_MISO_GPIO_Port GPIOE
#define DISPLAY_SPI_MOSI_Pin GPIO_PIN_14
#define DISPLAY_SPI_MOSI_GPIO_Port GPIOE
#define DISPLAY_RESET_N_Pin GPIO_PIN_15
#define DISPLAY_RESET_N_GPIO_Port GPIOE
#define TEMP_EXP_SPI_SCK_Pin GPIO_PIN_10
#define TEMP_EXP_SPI_SCK_GPIO_Port GPIOB
#define ETH_TX_EN_Pin GPIO_PIN_11
#define ETH_TX_EN_GPIO_Port GPIOB
#define ETH_TXD0_Pin GPIO_PIN_12
#define ETH_TXD0_GPIO_Port GPIOB
#define ETH_TXD1_Pin GPIO_PIN_13
#define ETH_TXD1_GPIO_Port GPIOB
#define TEMP_EXP_SPI_MISO_Pin GPIO_PIN_14
#define TEMP_EXP_SPI_MISO_GPIO_Port GPIOB
#define TEMP_EXP_SPI_MOSI_Pin GPIO_PIN_15
#define TEMP_EXP_SPI_MOSI_GPIO_Port GPIOB
#define TEMP_CS_N_Pin GPIO_PIN_8
#define TEMP_CS_N_GPIO_Port GPIOD
#define EXPANSION_SPI_CS_N_Pin GPIO_PIN_9
#define EXPANSION_SPI_CS_N_GPIO_Port GPIOD
#define EXPANSION_SDA_Pin GPIO_PIN_9
#define EXPANSION_SDA_GPIO_Port GPIOC
#define EXPANSION_SCL_Pin GPIO_PIN_8
#define EXPANSION_SCL_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define FREQUENCY_Pin GPIO_PIN_15
#define FREQUENCY_GPIO_Port GPIOA
#define ADC_SYS_CLK_Pin GPIO_PIN_10
#define ADC_SYS_CLK_GPIO_Port GPIOC
#define ADC_DATA_IN_Pin GPIO_PIN_11
#define ADC_DATA_IN_GPIO_Port GPIOC
#define ADC_DATA_OUT_Pin GPIO_PIN_12
#define ADC_DATA_OUT_GPIO_Port GPIOC
#define ADC_CS_N_Pin GPIO_PIN_0
#define ADC_CS_N_GPIO_Port GPIOD
#define ADC_DOUT_NOTRDY_Pin GPIO_PIN_1
#define ADC_DOUT_NOTRDY_GPIO_Port GPIOD
#define ADC_DOUT_NOTRDY_EXTI_IRQn EXTI1_IRQn
#define ADC_SYNC_ERROR_N_Pin GPIO_PIN_2
#define ADC_SYNC_ERROR_N_GPIO_Port GPIOD
#define ADC_SYNC_ERROR_N_EXTI_IRQn EXTI2_IRQn
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define EEPROM_SCL_Pin GPIO_PIN_6
#define EEPROM_SCL_GPIO_Port GPIOB
#define EEPROM_SDA_Pin GPIO_PIN_7
#define EEPROM_SDA_GPIO_Port GPIOB
#define EEPROM_WRITE_PROTECT_Pin GPIO_PIN_8
#define EEPROM_WRITE_PROTECT_GPIO_Port GPIOB
#define MAIN_LOOP_IND_Pin GPIO_PIN_1
#define MAIN_LOOP_IND_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
