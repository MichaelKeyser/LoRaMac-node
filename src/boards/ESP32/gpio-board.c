/*
Functions for interfacing with the GPIOs on the ESP. The ESP does not have the same GPIO port structure like the STM.
*/
#include "gpio-board.h"
#include "hal/gpio_types.h"
#include "driver/gpio.h"
#include "gpio.h"

// Uses the IrqModes in gpio.h as indicies to map to the ESP32 IRQ modes
char IrqModes_conversion[4] = {GPIO_INTR_DISABLE, GPIO_INTR_POSEDGE, GPIO_INTR_NEGEDGE, GPIO_INTR_ANYEDGE};


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
    obj->pin = pin;
    obj->pull = type;

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
    esp_err_t out = gpio_set_level(gpio_num, value);
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