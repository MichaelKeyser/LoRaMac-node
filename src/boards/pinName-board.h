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

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * ESP32-S3 Pin Names from the datasheet. There are a total of 45 GPIOs (pins 22-25 are not used)
 */
#define MCU_PINS \
    GPIO0 = 0, GPIO1 = 1, GPIO2 = 2, GPIO3 = 3, GPIO4 = 4, GPIO5 = 5, GPIO6 = 6, GPIO7 = 7, \
    GPIO8 = 8, GPIO9 = 9, GPIO10 = 10, GPIO11 = 11, GPIO12 = 12, GPIO13 = 13, GPIO14 = 14, XTAL_32K_P = 15, \
    XTAL_32K_N = 16, GPIO17 = 17, GPIO18 = 18, GPIO19 = 19, GPIO20 = 20, GPIO21 = 21, SPICS1 = 26, SPIHD = 27,  \
    SPIWP = 28, SPICS0 = 29, SPICLK = 30, SPIQ = 31, SPID = 32, GPIO33 = 33, GPIO34 = 34, \
    GPIO35 = 35, GPIO36 = 36, GPIO37 = 37, GPIO38 = 38, MTCK = 39, MTDO = 40, MTDI = 41, \
    MTMS = 42, U0TXD = 43, U0RXD = 44,  GPIO45 = 45, GPIO46 = 36, SPICLK_P = 47, SPICLK_N = 48

// Aliases for the GPIO pins that do not have a standard GPIOx name
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






#ifdef __cplusplus
}
#endif

#endif // __PIN_NAME_BOARD_H__
