/*
Functions for interfacing with the SPI
*/

#include "spi-board.h"
#include "hal/spi_types.h"
#include "driver/spi_master.h"

static spi_device_handle_t __spi;

spi_host_device_t Spi_Id_conversion[3] = {SPI1_HOST, SPI2_HOST, SPI3_HOST};



/*!
 * \brief Initializes the SPI object and MCU peripheral
 *
 * \remark When NSS pin is software controlled set the pin name to NC otherwise
 *         set the pin name to be used.
 *
 * \param [IN] obj  SPI object
 * \param [IN] mosi SPI MOSI pin name to be used
 * \param [IN] miso SPI MISO pin name to be used
 * \param [IN] sclk SPI SCLK pin name to be used
 * \param [IN] nss  SPI NSS pin name to be used
 */
void SpiInit( Spi_t *obj, SpiId_t spiId, PinNames mosi, PinNames miso, PinNames sclk, PinNames nss )
{
    /* Initialize all this later
    obj->SpiId = (SpiId_t)spiId;
    obj->Mosi = mosi;
    obj->Miso = miso;
    obj->Sclk = sclk;
    obj->Nss = nss;
    */

   //#define CONFIG_CS_GPIO nss

   spi_bus_config_t bus = {
      .miso_io_num = (int) miso,
      .mosi_io_num = (int) mosi,
      .sclk_io_num = (int) sclk,
      .quadwp_io_num = -1,
      .quadhd_io_num = -1,
      .max_transfer_sz = 0
   }; 

   #define VSPI_HOST SPI3_HOST //edited to make build work        
   esp_err_t ret = spi_bus_initialize(VSPI_HOST, &bus, 0); 
   assert(ret == ESP_OK);

   spi_device_interface_config_t dev = {
      .clock_speed_hz = 9000000,
      .mode = 0,
      .spics_io_num = -1,
      .queue_size = 1,
      .flags = 0,
      .pre_cb = NULL
   };
   ret = spi_bus_add_device(VSPI_HOST, &dev, &__spi);
   assert(ret == ESP_OK);
}

/*!
 * \brief Sends outData and receives inData
 *
 * \param [IN] obj     SPI object
 * \param [IN] outData Byte to be sent
 * \retval inData      Received byte.
 */
uint16_t SpiInOut( Spi_t *obj, uint16_t outData )
{
    // TODO: EDIT TO USE outData !!!!!!
    uint8_t out[2]; //= { 0x80 | reg, val };
    uint8_t in[2];

    spi_transaction_t t = {
        .flags = 0,
        .length = 8 * sizeof(out),
        .tx_buffer = out,
        .rx_buffer = in  
    };

    //gpio_set_level(CONFIG_CS_GPIO, 0);
    spi_device_transmit(__spi, &t);

    // TODO: COMPLETE RECEIING PART LATER!


    //gpio_set_level(CONFIG_CS_GPIO, 1);
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