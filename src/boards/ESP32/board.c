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



#include <stdio.h>
#include "esp_log.h"
void BoardInitMcu()
{
    SpiInit(&SX1276.Spi, SPI_2, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, 15);
    printf("spi init complete \n");
    SX1276IoInit( );
    
}

void BoardLowPowerHandler( void )
{

}

void BoardInitPeriph( void )
{
    // is blank in examples
}


static portMUX_TYPE lock_name_original = portMUX_INITIALIZER_UNLOCKED;
// check this functions not sure if correct
void BoardCriticalSectionBegin( uint32_t *mask )
{
    printf("inside board critical section begin\n");
    //xt_ints_off(*mask);
    //taskENTER_CRITICAL_ISR(&lock_name_original);
    taskENTER_CRITICAL(&lock_name_original);
    printf("end of board critical section begin\n");
}


// check this functions not sure if correct
void BoardCriticalSectionEnd( uint32_t *mask )
{
   //xt_ints_on((unsigned int)*mask );
   taskEXIT_CRITICAL_ISR(&lock_name_original);
}
