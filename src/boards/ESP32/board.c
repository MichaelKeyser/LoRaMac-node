/*
Sets up the ESP and its peripherals
*/

#include "utilities.h"
#include "board.h"
#include "rtc-board.h"
#include "timer.h"
#include "board-config.h"
#include "gpio.h"
#include "spi.h"
#include "sx1276-board.h"
//#include <xtensa/xtensa_api.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#include "esp_system.h"

#include <stdio.h>
#include "esp_log.h"

#include "esp_sleep.h"

void BoardInitMcu()
{
    SpiInit(&SX1276.Spi, SPI_2, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, 15);
    SX1276IoInit( );
    
}

/*!
 * \brief Resets the mcu.
 */
void BoardResetMcu( void )
{
    abort();
}

void BoardInitPeriph( void )
{
    // Initalize RTC timers
    RtcInit();
}

/*!
 * \brief De-initializes the target board peripherals to decrease power
 *        consumption.
 */
void BoardDeInitMcu( void )
{
    abort();
}



/*!
 * \brief Gets the current potentiometer level value
 *
 * \retval value  Potentiometer level ( value in percent )
 */
uint8_t BoardGetPotiLevel( void )
{
    abort();
    return 0;
}

/*!
 * \brief Measure the Battery voltage
 *
 * \retval value  battery voltage in volts
 */
uint32_t BoardGetBatteryVoltage( void )
{
    abort();
    return 0;
}

/*!
 * \brief Get the current battery level
 *
 * \retval value  battery level [  0: USB,
 *                                 1: Min level,
 *                                 x: level
 *                               254: fully charged,
 *                               255: Error]
 */
uint8_t BoardGetBatteryLevel( void )
{
    //abort();
    return 1;
}

/*!
 * \brief Get the current MCU temperature in degree celcius * 256
 *
 * \retval temperature * 256
 */
int16_t BoardGetTemperature( void )
{
    abort();
    return 0;
}

/*!
 * Returns a pseudo random seed generated using the MCU Unique ID
 *
 * \retval seed Generated pseudo random seed
 */
uint32_t BoardGetRandomSeed( void )
{
    abort();
    return 0;
}

/*!
 * \brief Gets the board 64 bits unique ID
 *
 * \param [IN] id Pointer to an array that will contain the Unique ID
 */
void BoardGetUniqueId( uint8_t *id )
{
    abort();
}

/*!
 * \brief Manages the entry into ARM cortex deep-sleep mode
 */
void BoardLowPowerHandler( void )
{
    esp_deep_sleep_start();
    //abort();
}

/*!
 * \brief Get the board power source
 *
 * \retval value  power source [0: USB_POWER, 1: BATTERY_POWER]
 */
uint8_t GetBoardPowerSource( void )
{
    abort();
    return 0;
}

/*!
 * \brief Get the board version
 *
 * \retval value  Version
 */
Version_t BoardGetVersion( void )
{
    Version_t v;
    abort();
    return v;
}


static portMUX_TYPE lock_name_original = portMUX_INITIALIZER_UNLOCKED;
// check this functions not sure if correct
void BoardCriticalSectionBegin( uint32_t *mask )
{
    //printf("inside board critical section begin\n");
    //xt_ints_off(*mask);
    //taskENTER_CRITICAL_ISR(&lock_name_original);
    taskENTER_CRITICAL_ISR(&lock_name_original);
    //printf("end of board critical section begin\n");
}


// check this functions not sure if correct
void BoardCriticalSectionEnd( uint32_t *mask )
{
   //xt_ints_on((unsigned int)*mask );
   taskEXIT_CRITICAL_ISR(&lock_name_original);
}



