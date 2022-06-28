/*
Functions for interfacing with the SPI
*/

#include "spi-board.h"

uint16_t SpiInOut( Spi_t *obj, uint16_t outData )
{
    /*
    uint8_t rxData = 0;

    if( ( obj == NULL ) || ( SpiHandle[obj->SpiId].Instance ) == NULL )
    {
        assert_param( LMN_STATUS_ERROR );
    }

    __HAL_SPI_ENABLE( &SpiHandle[obj->SpiId] );

    CRITICAL_SECTION_BEGIN( );

    while( __HAL_SPI_GET_FLAG( &SpiHandle[obj->SpiId], SPI_FLAG_TXE ) == RESET );
    SpiHandle[obj->SpiId].Instance->DR = ( uint16_t ) ( outData & 0xFF );

    while( __HAL_SPI_GET_FLAG( &SpiHandle[obj->SpiId], SPI_FLAG_RXNE ) == RESET );
    rxData = ( uint16_t ) SpiHandle[obj->SpiId].Instance->DR;

    CRITICAL_SECTION_END( );

    return( rxData );
    */
   return 0;
}