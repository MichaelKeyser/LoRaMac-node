/*
Functions for interfacing with the GPIOs on the ESP. The ESP does not have the same GPIO port structure like the STM.
*/
#include "gpio-board.h"
#include "hal/gpio_types.h"
#include "driver/gpio.h"
#include "gpio.h"

// Uses the IrqModes in gpio.h as indicies to map to the ESP32 IRQ modes
gpio_int_type_t IrqModes_conversion[4] = {GPIO_INTR_DISABLE, GPIO_INTR_POSEDGE, GPIO_INTR_NEGEDGE, GPIO_INTR_ANYEDGE};
gpio_mode_t PinTypes_conversion[3] = {GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_DISABLE, GPIO_MODE_DISABLE};



/*!
 * \brief Initializes the given GPIO object
 *
 * \param [IN] obj    Pointer to the GPIO object
 * \param [IN] pin    Pin name ( please look in pinName-board.h file )
 * \param [IN] mode   Pin mode [PIN_INPUT, PIN_OUTPUT,
 *                              PIN_ALTERNATE_FCT, PIN_ANALOGIC]
 * \param [IN] config Pin config [PIN_PUSH_PULL, PIN_OPEN_DRAIN]
 * \param [IN] type   Pin type [PIN_NO_PULL, PIN_PULL_UP, PIN_PULL_DOWN]
 * \param [IN] value  Default output value at initialization
 */
void GpioMcuInit( Gpio_t *obj, PinNames pin, PinModes mode, PinConfigs config, PinTypes type, uint32_t value )
{
    // update the LoRa GPIO obj
    obj->pin = pin;
    obj->pull = type;
    
    // configure a gpio on the ESP
    gpio_config_t gpio;

    // set bit mask that selects the specified gpio
    gpio.pin_bit_mask = 1 << (int)pin;//(uint64_t)((1 << (uint64_t)pin) | (0x0000000000000000));
    // select the pin mode
    gpio.mode = PinTypes_conversion[(int)mode];
    
    // configure the pin pull-up settings
    if((char)type == (char)PIN_PULL_UP) // pull-up
    {
        gpio.pull_up_en = GPIO_PULLUP_ENABLE;
        gpio.pull_down_en = GPIO_PULLDOWN_DISABLE;
    }
    else if((char)type == (char)PIN_PULL_DOWN) // pull-down
    {
        gpio.pull_up_en = GPIO_PULLUP_DISABLE;
        gpio.pull_down_en = GPIO_PULLDOWN_ENABLE;
    }
    else // neither pull-up or pull-down
    {
        gpio.pull_up_en = GPIO_PULLUP_DISABLE;
        gpio.pull_down_en = GPIO_PULLDOWN_DISABLE;
    }

    //gpio.intr_type = IrqModes_conversion[(char)]
    
    // configure the gpio
    gpio_config(&gpio);

    // set the gpio output
    gpio_num_t gpio_num = pin; // ASK ABOUT THE CASTING WITH THIS
    gpio_set_level(gpio_num, value);

}

/*!
 * \brief Sets a user defined object pointer
 *
 * \param [IN] context User defined data object pointer to pass back
 *                     on IRQ handler callback
 */
//void GpioMcuSetContext( Gpio_t *obj, void* context );

/*!
 * \brief GPIO IRQ Initialization
 *
 * \param [IN] obj         Pointer to the GPIO object
 * \param [IN] irqMode     IRQ mode [NO_IRQ, IRQ_RISING_EDGE,
 *                                   IRQ_FALLING_EDGE, IRQ_RISING_FALLING_EDGE]
 * \param [IN] irqPriority IRQ priority [IRQ_VERY_LOW_PRIORITY, IRQ_LOW_PRIORITY
 *                                       IRQ_MEDIUM_PRIORITY, IRQ_HIGH_PRIORITY
 *                                       IRQ_VERY_HIGH_PRIORITY]
 * \param [IN] irqHandler  Callback function pointer
 */
void GpioMcuSetInterrupt( Gpio_t *obj, IrqModes irqMode, IrqPriorities irqPriority, GpioIrqHandler *irqHandler )
{
    // Ignore interrupt priority level 

    // figure out if enable goes first or last
    gpio_num_t gpio_num = obj->pin;
    
    gpio_set_intr_type(gpio_num, IrqModes_conversion[irqMode]);

    // TODO: FIGURE OUT HOW TO SPECIFY INTERRUPT PRIOTITY
    gpio_intr_enable(gpio_num);
}

/*!
 * \brief Removes the interrupt from the object
 *
 * \param [IN] obj Pointer to the GPIO object
 */
void GpioMcuRemoveInterrupt( Gpio_t *obj )
{
    gpio_num_t gpio_num = obj->pin;
    gpio_intr_disable(gpio_num); // do error handling later!
}

/*!
 * \brief Writes the given value to the GPIO output
 *
 * \param [IN] obj   Pointer to the GPIO object
 * \param [IN] value New GPIO output value
 */
void GpioMcuWrite( Gpio_t *obj, uint32_t value )
{
    gpio_num_t gpio_num = obj->pin; // ASK ABOUT THE CASTING WITH THIS
    gpio_set_level(gpio_num, value);
    // TODO: PUT IN ERROR HANDLING
}

/*!
 * \brief Toggle the value to the GPIO output
 *
 * \param [IN] obj   Pointer to the GPIO object
 */
void GpioMcuToggle( Gpio_t *obj )
{
    // get the current output level of the GPIO 
    gpio_num_t gpio_num = obj->pin;
    uint32_t curr_level = GPIO_OUT_REG & ((uint32_t)(1 << gpio_num ));
    
    // set to opposite output value
    gpio_set_level(gpio_num, (curr_level ^ 1)); // do error checking later 
    
}

/*!
 * \brief Reads the current GPIO input value
 *
 * \param [IN] obj Pointer to the GPIO object
 * \retval value   Current GPIO input value
 */
uint32_t GpioMcuRead( Gpio_t *obj )
{ 
    gpio_num_t gpio_num = obj->pin;

    return (uint32_t) gpio_get_level(gpio_num); // cast from int
}