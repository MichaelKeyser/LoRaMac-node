/*
Sets up the ESP and its peripherals
*/

#include "utilities.h"
#include "board.h"
#include "rtc-board.h"
#include "timer.h"
//#include "cmsis_gcc.h"
#include "board-config.h"
#include "gpio.h"
#include "spi.h"
#include "sx1276-board.h"
//#include "freertos/xtensa_api.h"
#include <xtensa/xtensa_api.h>

void BoardInitMcu()
{
    SpiInit( &SX1276.Spi, SPI_1, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, NC );
    SX1276IoInit( );
    
}

void BoardLowPowerHandler( void )
{

}

void BoardInitPeriph( void )
{
    // is blank in examples
}



// check this functions not sure if correct
void BoardCriticalSectionBegin( uint32_t *mask )
{
    xt_ints_on((unsigned int)*mask);
}


// check this functions not sure if correct
void BoardCriticalSectionEnd( uint32_t *mask )
{
   xt_ints_off((unsigned int)*mask );
}
