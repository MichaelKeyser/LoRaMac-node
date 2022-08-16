#include <stdint.h>
#include "utilities.h"

#include "esp_system.h"

#define ROW 100
#define COL 100
static uint8_t eeprom[ROW][COL];

/*!
 * Writes the given buffer to the EEPROM at the specified address.
 *
 * \param[IN] addr EEPROM address to write to
 * \param[IN] buffer Pointer to the buffer to be written.
 * \param[IN] size Size of the buffer to be written.
 * \retval status [LMN_STATUS_OK, LMN_STATUS_ERROR]
 */
LmnStatus_t EepromMcuWriteBuffer( uint16_t addr, uint8_t *buffer, uint16_t size )
{
    if (addr >= ROW || size >= COL)
    {
        abort();
    }
    for(int i = 0; i < size; i++)
    {
        eeprom[addr][i] = buffer[i];
    }
    return LMN_STATUS_OK;
}

/*!
 * Reads the EEPROM at the specified address to the given buffer.
 *
 * \param[IN] addr EEPROM address to read from
 * \param[OUT] buffer Pointer to the buffer to be written with read data.
 * \param[IN] size Size of the buffer to be read.
 * \retval status [LMN_STATUS_OK, LMN_STATUS_ERROR]
 */
LmnStatus_t EepromMcuReadBuffer( uint16_t addr, uint8_t *buffer, uint16_t size )
{
    if (addr >= ROW || size >= COL)
    {
        abort();
    }
    for(int i = 0; i < size; i++)
    {
        buffer[i] = eeprom[addr][i];
    }
    return LMN_STATUS_OK;
}

/*!
 * Sets the device address.
 *
 * \remark Useful for I2C external EEPROMS
 *
 * \param[IN] addr External EEPROM address
 */
void EepromMcuSetDeviceAddr( uint8_t addr )
{
    abort();
}

/*!
 * Gets the current device address.
 *
 * \remark Useful for I2C external EEPROMS
 *
 * \retval addr External EEPROM address
 */
LmnStatus_t EepromMcuGetDeviceAddr( void )
{
    abort();
}