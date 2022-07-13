/*
Functions for interfacing with the SPI
*/

#include "spi-board.h"
#include "hal/spi_types.h"
#include "driver/spi_master.h"

#include "driver/gpio.h"
#include "esp_log.h"
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
    // Initalize Gpio_t structs to setup gpio
    Gpio_t mosi_g;
    mosi_g.pin = mosi;
    Gpio_t miso_g;
    miso_g.pin = miso;
    Gpio_t sclk_g;
    sclk_g.pin = sclk;
    Gpio_t nss_g;
    nss_g.pin = nss;
    
    // Initialize spi object
    obj->SpiId = spiId;
    obj->Mosi = mosi_g;
    obj->Miso = miso_g;
    obj->Sclk = sclk_g;
    obj->Nss = nss_g;
    
    

   //#define CONFIG_CS_GPIO nss

   spi_bus_config_t bus = {
      .miso_io_num = miso,
      .mosi_io_num = mosi,
      .sclk_io_num = sclk,
      .quadwp_io_num = -1,
      .quadhd_io_num = -1,
      .max_transfer_sz = 0
   }; 

   //#define VSPI_HOST SPI3_HOST //edited to make build work        
   esp_err_t ret = spi_bus_initialize((int) spiId, &bus, 0); // spiId
   assert(ret == ESP_OK);

   spi_device_interface_config_t dev = {
      .clock_speed_hz = 250000,//9000000,
      .mode = 0,
      .spics_io_num = -1,
      .queue_size = 1,
      .flags = 0,
      .pre_cb = NULL
   };
   ret = spi_bus_add_device((int) spiId, &dev, &__spi); // spiId
   gpio_set_level((int)obj->Nss.pin, 1); // turn the connection off
   assert(ret == ESP_OK);
}

/*!
 * \brief Sends outData and receives inData
 *
 * \param [IN] obj     SPI object
 * \param [IN] outData Byte to be sent
 * \retval inData      Received byte.
 */
#include "/Users/michael/Documents/Senior_Project/ESP/test_lorawan/main/debug.c"
uint16_t SpiInOut( Spi_t *obj, uint16_t outData )
{
    // TODO: EDIT TO USE outData !!!!!!
    //uint8_t out[2] =  {outData & 0xff, outData >> 8}; //= { 0x80 | reg, val };
    uint16_t in;
    spi_transaction_t t = {
        .flags = 0,
        .length = 8 * sizeof(outData),
        .tx_buffer = &outData,
        .rx_buffer = &in  
    };

    // handled when making call to SpiInOut
    //gpio_set_level((int)obj->Nss.pin, 0);
    // ESP32 is little-endian so in uint16_t [7:0] is sent and then [15:8] is set
    esp_err_t ret = spi_device_transmit(__spi, &t); // probably should replace this to get stuff back
    assert(ret == ESP_OK);
    
    // handled when making call to SpiInOut
    //gpio_set_level((int)obj->Nss.pin, 1);
    //printf("Byte sent\n");
    
    //printf("%d\n", in[0]);
    //printf("\n");
    //printf("%d\n", in[1]);
    // THIS IS ASSUMING in[o] is MSB
    /*
    uint16_t in_val = in[0];
    in_val = in_val << 8;
    in_val |= in[1];
    */
   //printf("%d\n", in);
    return in;
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