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
      .miso_io_num = (int) 13,
      .mosi_io_num = (int) 12,
      .sclk_io_num = (int) 14,
      .quadwp_io_num = -1,
      .quadhd_io_num = -1,
      .max_transfer_sz = 0
   }; 

   //#define VSPI_HOST SPI3_HOST //edited to make build work        
   esp_err_t ret = spi_bus_initialize(SPI_2, &bus, 0); // spiId
   assert(ret == ESP_OK);

   spi_device_interface_config_t dev = {
      .clock_speed_hz = 250000,//9000000,
      .mode = 0,
      .spics_io_num = -1,
      .queue_size = 1,
      .flags = 0,
      .pre_cb = NULL
   };
   ret = spi_bus_add_device(SPI_2, &dev, &__spi); // spiId
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
    uint8_t in[2];

    //printf("out is %d, %d \n", out[1], out[0]);
    
    char letter[1] = {'H'};

    spi_transaction_t t = {
        .flags = 0,
        .length = 8 * sizeof(letter),
        .tx_buffer = letter,
        .rx_buffer = in  
    };

    gpio_set_level(15, 0);
    esp_err_t ret = spi_device_transmit(__spi, &t); // probably should replace this to get stuff back
    assert(ret == ESP_OK);
    gpio_set_level(15, 1);
    printf("Byte sent\n");
    /*
    esp_err_t ret;
    spi_transaction_t *ret_trans;
    //ToDo: check if any spi transfers in flight
    ret = spi_device_queue_trans(__spi, &t, portMAX_DELAY);
    if (ret != ESP_OK) 
    {
        printf("ERROR\n");
        return ret;
    }
    

    ret = spi_device_get_trans_result(__spi, &ret_trans, portMAX_DELAY);
    if (ret != ESP_OK) 
    {
         printf("ERROR\n");
        return ret;
    }
    assert(ret_trans == &t);
    */
    //printf("%d\n", in[0]);
    //printf("\n");
    //printf("%d\n", in[1]);
    // THIS IS ASSUMING in[o] is MSB
    uint16_t in_val = in[0];
    in_val = in_val << 8;
    in_val |= in[1];
    return in_val;
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