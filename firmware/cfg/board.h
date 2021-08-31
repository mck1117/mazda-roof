/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for STMicroelectronics STM32F4-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_STM32F4_DISCOVERY
#define BOARD_NAME                  "STMicroelectronics STM32F4-Discovery"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000U
#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   330U

/*
 * MCU type as defined in the ST header.
 */
#define STM32F407xx

#define PIN_MODE_DEFAULT PIN_MODE_INPUT
#define DR_DEFAULT PIN_PUPDR_PULLDOWN
#define DEFAULT_GPIO_SPEED PIN_OSPEED_HIGH

/*
 * IO pins assignments.
 */
#define GPIOA_SWDIO                 13
#define GPIOA_SWCLK                 14

#define GPIOB_SWO                   3

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

#define VAL_GPIO_MODER_ALL_DEFAULT  (PIN_MODE_DEFAULT(0) |           \
                                     PIN_MODE_DEFAULT(1) |           \
                                     PIN_MODE_DEFAULT(2) |           \
                                     PIN_MODE_DEFAULT(3) |           \
                                     PIN_MODE_DEFAULT(4) |         \
                                     PIN_MODE_DEFAULT(5) |   \
                                     PIN_MODE_DEFAULT(6) |           \
                                     PIN_MODE_DEFAULT(7) |           \
                                     PIN_MODE_DEFAULT(8) |           \
                                     PIN_MODE_DEFAULT(9) |           \
                                     PIN_MODE_DEFAULT(10) |          \
                                     PIN_MODE_DEFAULT(11) |          \
                                     PIN_MODE_DEFAULT(12) |          \
                                     PIN_MODE_DEFAULT(13) |          \
                                     PIN_MODE_DEFAULT(14) |          \
                                     PIN_MODE_DEFAULT(15))

#define VAL_GPIO_OTYPER_ALL_DEFAULT (PIN_OTYPE_PUSHPULL(0) |   \
                                     PIN_OTYPE_PUSHPULL(1) |   \
                                     PIN_OTYPE_PUSHPULL(2) |   \
                                     PIN_OTYPE_PUSHPULL(3) |   \
                                     PIN_OTYPE_PUSHPULL(4) |   \
                                     PIN_OTYPE_PUSHPULL(5) |   \
                                     PIN_OTYPE_PUSHPULL(6) |   \
                                     PIN_OTYPE_PUSHPULL(7) |   \
                                     PIN_OTYPE_PUSHPULL(8) |   \
                                     PIN_OTYPE_PUSHPULL(9) |   \
                                     PIN_OTYPE_PUSHPULL(10) |  \
                                     PIN_OTYPE_PUSHPULL(11) |  \
                                     PIN_OTYPE_PUSHPULL(12) |  \
                                     PIN_OTYPE_PUSHPULL(13) |  \
                                     PIN_OTYPE_PUSHPULL(14) |  \
                                     PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIO_OSPEEDR_ALL_DEFAULT (DEFAULT_GPIO_SPEED(0) |          \
                                     DEFAULT_GPIO_SPEED(1) |          \
                                     DEFAULT_GPIO_SPEED(2) |          \
                                     DEFAULT_GPIO_SPEED(3) |          \
                                     DEFAULT_GPIO_SPEED(4) |         \
                                     DEFAULT_GPIO_SPEED(5) |  \
                                     DEFAULT_GPIO_SPEED(6) |          \
                                     DEFAULT_GPIO_SPEED(7) |          \
                                     DEFAULT_GPIO_SPEED(8) |          \
                                     DEFAULT_GPIO_SPEED(9) |          \
                                     DEFAULT_GPIO_SPEED(10) |         \
                                     DEFAULT_GPIO_SPEED(11) |         \
                                     DEFAULT_GPIO_SPEED(12) |          \
                                     DEFAULT_GPIO_SPEED(13) |          \
                                     DEFAULT_GPIO_SPEED(14) |          \
                                     DEFAULT_GPIO_SPEED(15))

#define VAL_GPIO_ODR_ALL_DEFAULT    0

#define VAL_GPIO_PUPDR_ALL_DEFAULT (DR_DEFAULT(0) |        \
                                     DR_DEFAULT(1) |       \
                                     DR_DEFAULT(2) |       \
                                     DR_DEFAULT(3) |       \
                                     DR_DEFAULT(4) |       \
                                     DR_DEFAULT(5) |       \
                                     DR_DEFAULT(6) |       \
                                     DR_DEFAULT(7) |       \
                                     DR_DEFAULT(8) |       \
                                     DR_DEFAULT(9) |       \
                                     DR_DEFAULT(10) |      \
                                     DR_DEFAULT(11) |      \
                                     DR_DEFAULT(12) |      \
                                     DR_DEFAULT(13) |      \
                                     DR_DEFAULT(14) |      \
                                     DR_DEFAULT(15))

#define VAL_GPIO_AF_ALL_DEFAULT   (PIN_AFIO_AF(0, 0U) |          \
                                   PIN_AFIO_AF(1, 0U) |          \
                                   PIN_AFIO_AF(2, 0U) |          \
                                   PIN_AFIO_AF(3, 0U) |          \
                                   PIN_AFIO_AF(4, 0U) |          \
                                   PIN_AFIO_AF(5, 0U) |          \
                                   PIN_AFIO_AF(6, 0U) |          \
                                   PIN_AFIO_AF(7, 0U))


/*
 * GPIOA setup:
 *
 * PA11 - OTG_FS_DM                 (alternate 10).
 * PA12 - OTG_FS_DP                 (alternate 10).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_DEFAULT(0) |         \
                                     PIN_MODE_DEFAULT(1) |           \
                                     PIN_MODE_DEFAULT(2) |           \
                                     PIN_MODE_DEFAULT(3) |           \
                                     PIN_MODE_DEFAULT(4) |       \
                                     PIN_MODE_DEFAULT(5) |        \
                                     PIN_MODE_DEFAULT(6) |        \
                                     PIN_MODE_DEFAULT(7) |        \
                                     PIN_MODE_DEFAULT(8) |           \
                                     PIN_MODE_DEFAULT(9) |        \
                                     PIN_MODE_DEFAULT(10) |  \
                                     PIN_MODE_ALTERNATE(11) |  \
                                     PIN_MODE_ALTERNATE(12) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_DEFAULT(15))
#define VAL_GPIOA_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOA_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOA_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOA_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(0, 0U) |        \
                                     PIN_AFIO_AF(1, 0U) |          \
                                     PIN_AFIO_AF(2, 0U) |          \
                                     PIN_AFIO_AF(3, 0U) |          \
                                     PIN_AFIO_AF(4, 6U) |          \
                                     PIN_AFIO_AF(5, 5U) |           \
                                     PIN_AFIO_AF(6, 5U) |           \
                                     PIN_AFIO_AF(7, 5U))
#define VAL_GPIOA_AFRH              VAL_GPIO_AF_ALL_DEFAULT

/*
 * GPIOB setup:
 * 
 * Default except SWO configured on PB3
 * 
 */
#define VAL_GPIOB_MODER             (PIN_MODE_DEFAULT(0) |           \
                                     PIN_MODE_DEFAULT(1) |           \
                                     PIN_MODE_DEFAULT(2) |           \
                                     PIN_MODE_ALTERNATE(GPIOB_SWO) |        \
                                     PIN_MODE_DEFAULT(4) |           \
                                     PIN_MODE_DEFAULT(5) |           \
                                     PIN_MODE_DEFAULT(6) |        \
                                     PIN_MODE_DEFAULT(7) |           \
                                     PIN_MODE_DEFAULT(8) |           \
                                     PIN_MODE_DEFAULT(9) |          \
                                     PIN_MODE_DEFAULT(10) |          \
                                     PIN_MODE_DEFAULT(11) |          \
                                     PIN_MODE_DEFAULT(12) |          \
                                     PIN_MODE_DEFAULT(13) |          \
                                     PIN_MODE_DEFAULT(14) |          \
                                     PIN_MODE_DEFAULT(15))
#define VAL_GPIOB_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOB_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOB_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOB_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(0, 0U) |          \
                                     PIN_AFIO_AF(1, 0U) |          \
                                     PIN_AFIO_AF(2, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_SWO, 0U) |           \
                                     PIN_AFIO_AF(4, 0U) |          \
                                     PIN_AFIO_AF(5, 0U) |          \
                                     PIN_AFIO_AF(6, 0U) |           \
                                     PIN_AFIO_AF(7, 0U))
#define VAL_GPIOB_AFRH              VAL_GPIO_AF_ALL_DEFAULT

/*
 * GPIOC setup:
 */
#define VAL_GPIOC_MODER             VAL_GPIO_MODER_ALL_DEFAULT
#define VAL_GPIOC_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOC_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOC_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOC_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOC_AFRL              VAL_GPIO_AF_ALL_DEFAULT
#define VAL_GPIOC_AFRH              VAL_GPIO_AF_ALL_DEFAULT

/*
 * GPIOD setup:
 */
#define VAL_GPIOD_MODER             VAL_GPIO_MODER_ALL_DEFAULT
#define VAL_GPIOD_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOD_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOD_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOD_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOD_AFRL              VAL_GPIO_AF_ALL_DEFAULT
#define VAL_GPIOD_AFRH              VAL_GPIO_AF_ALL_DEFAULT

/*
 * GPIOE setup:
 */
#define VAL_GPIOE_MODER             VAL_GPIO_MODER_ALL_DEFAULT
#define VAL_GPIOE_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOE_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOE_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOE_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOE_AFRL              VAL_GPIO_AF_ALL_DEFAULT
#define VAL_GPIOE_AFRH              VAL_GPIO_AF_ALL_DEFAULT

/*
 * GPIOF setup:
 */
#define VAL_GPIOF_MODER             VAL_GPIO_MODER_ALL_DEFAULT
#define VAL_GPIOF_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOF_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOF_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOF_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOF_AFRL              VAL_GPIO_AF_ALL_DEFAULT
#define VAL_GPIOF_AFRH              VAL_GPIO_AF_ALL_DEFAULT

/*
 * GPIOG setup:
 */
#define VAL_GPIOG_MODER             VAL_GPIO_MODER_ALL_DEFAULT
#define VAL_GPIOG_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOG_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOG_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOG_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOG_AFRL              VAL_GPIO_AF_ALL_DEFAULT
#define VAL_GPIOG_AFRH              VAL_GPIO_AF_ALL_DEFAULT

/*
 * GPIOH setup:
 */
#define VAL_GPIOH_MODER             VAL_GPIO_MODER_ALL_DEFAULT
#define VAL_GPIOH_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOH_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOH_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOH_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOH_AFRL              VAL_GPIO_AF_ALL_DEFAULT
#define VAL_GPIOH_AFRH              VAL_GPIO_AF_ALL_DEFAULT

/*
 * GPIOI setup:
 */
#define VAL_GPIOI_MODER             VAL_GPIO_MODER_ALL_DEFAULT
#define VAL_GPIOI_OTYPER            VAL_GPIO_OTYPER_ALL_DEFAULT
#define VAL_GPIOI_OSPEEDR           VAL_GPIO_OSPEEDR_ALL_DEFAULT
#define VAL_GPIOI_PUPDR             VAL_GPIO_PUPDR_ALL_DEFAULT
#define VAL_GPIOI_ODR               VAL_GPIO_ODR_ALL_DEFAULT
#define VAL_GPIOI_AFRL              VAL_GPIO_AF_ALL_DEFAULT
#define VAL_GPIOI_AFRH              VAL_GPIO_AF_ALL_DEFAULT





/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
