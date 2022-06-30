/*!
 * \file      pinName-board.h
 *
 * \brief     Target board GPIO pins definitions
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 */
#ifndef __PIN_NAME_BOARD_H__
#define __PIN_NAME_BOARD_H__

#include "hal/gpio_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * Aliases for EPS32 pins to work with built-in pin definitions. There are a total of 45 GPIOs (pins 22-25 are not used)
 */
#define MCU_PINS  \
    GPIO0 = GPIO_NUM_0, GPIO1 = GPIO_NUM_1, GPIO2 = GPIO_NUM_2, GPIO3 = GPIO_NUM_3, GPIO4 = GPIO_NUM_4, GPIO5 = GPIO_NUM_5, GPIO6 = GPIO_NUM_6, GPIO7 = GPIO_NUM_7, \
    GPIO8 = GPIO_NUM_8, GPIO9 = GPIO_NUM_9, GPIO10 = GPIO_NUM_10, GPIO11 = GPIO_NUM_11, GPIO12 = GPIO_NUM_12, GPIO13 = GPIO_NUM_13, GPIO14 = GPIO_NUM_14, GPIO15 = GPIO_NUM_15, \
    GPIO16 = GPIO_NUM_16, GPIO17 = GPIO_NUM_17, GPIO18 = GPIO_NUM_18, GPIO19 = GPIO_NUM_19, GPIO20 = GPIO_NUM_20, GPIO21 = GPIO_NUM_21, GPIO26 = GPIO_NUM_26, GPIO27 = GPIO_NUM_27,  \
    GPIO28 = GPIO_NUM_28, GPIO29 = GPIO_NUM_29, GPIO30 = GPIO_NUM_30, GPIO31 = GPIO_NUM_31, GPIO32 = GPIO_NUM_32, GPIO33 = GPIO_NUM_33, GPIO34 = GPIO_NUM_34, \
    GPIO35 = GPIO_NUM_35, GPIO36 = GPIO_NUM_36, GPIO37 = GPIO_NUM_37, GPIO38 = GPIO_NUM_38, GPIO39 = GPIO_NUM_39, GPIO40 = GPIO_NUM_40, GPIO41 = GPIO_NUM_41, \
    GPIO42 = GPIO_NUM_42, GPIO43 = GPIO_NUM_43, GPIO44 = GPIO_NUM_44, GPIO45 = GPIO_NUM_45, GPIO46 = GPIO_NUM_36, GPIO47 = GPIO_NUM_47, GPIO48 = GPIO_NUM_48
    

// Aliases for the GPIO pins that do not have a standard GPIOx name

/*
#define GPIO15 XTAL_32K_P
#define GPIO16 XTAL_32K_N
#define GPIO26 SPICS1
#define GPIO27 SPIHD
#define GPIO28 SPIWP
#define GPIO29 SPICS0
#define GPIO30 SPICLK
#define GPIO31 SPIQ
#define GPIO32 SPID
#define GPIO39 MTCK
#define GPIO40 MTDO
#define GPIO41 MTDI
#define GPIO42 MTMS
#define GPIO43 U0TXD
#define GPIO44 U0TXD
#define GPIO47 SPICLK_P
#define GPIO48 SPICLK_N
*/





#ifdef __cplusplus
}
#endif

#endif // __PIN_NAME_BOARD_H__
