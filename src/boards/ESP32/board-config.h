/*
Related pins from ESP to the RF board
*/

#ifndef __BOARD_CONFIG_H__
#define __BOARD_CONFIG_H__

#include "/Users/michael/Documents/Senior_Project/ESP/test_lorawan/main/debug.c" 


// MCU specific
#define RADIO_RESET                                 GPIO_NUM_7

#define RADIO_MOSI                                  GPIO_NUM_12
#define RADIO_MISO                                  GPIO_NUM_13
#define RADIO_SCLK                                  GPIO_NUM_14


// radio specific 
#define RADIO_NSS                                   GPIO_NUM_15

#define RADIO_DIO_0                                 GPIO_NUM_5
#define RADIO_DIO_1                                 GPIO_NUM_6

#define RADIO_DIO_2                                 FILL_ME_IN
#define RADIO_DIO_3                                 FILL_ME_IN
#define RADIO_DIO_4                                 FILL_ME_IN
#define RADIO_DIO_5                                 FILL_ME_IN

#define RADIO_ANT_SWITCH                            FILL_ME_IN

#define LED_1                                       FILL_ME_IN
#define LED_2                                       FILL_ME_IN

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            FILL_ME_IN
#define RADIO_DBG_PIN_RX                            FILL_ME_IN

// global defines
#define OSC_LSE_IN                                  FILL_ME_IN
#define OSC_LSE_OUT                                 FILL_ME_IN

#define OSC_HSE_IN                                  FILL_ME_IN
#define OSC_HSE_OUT                                 FILL_ME_IN

#define SWCLK                                       FILL_ME_IN
#define SWDAT                                       FILL_ME_IN

#define I2C_SCL                                     FILL_ME_IN
#define I2C_SDA                                     FILL_ME_IN

#define UART_TX                                     FILL_ME_IN
#define UART_RX                                     FILL_ME_IN

#endif // __BOARD_CONFIG_H__