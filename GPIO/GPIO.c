#include "GPIO.h"

/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pinCount The number of configured pins in structure
 * @param[in] config The configuration structure
 * @return 
 */
 

// Initializes the pins with the given configuration structure
void GPIO_Init(const Gpio_ConfigType* ConfigPtr) {
    // Set the pin mode in the PDDR register (1 = output, 0 = input)
    if (ConfigPtr->GPIO_PinMode == 1) { // Output mode
        ConfigPtr->base->PDDR |= (1 << ConfigPtr->GPIO_PinNumber);
    } else { // Input mode
        ConfigPtr->base->PDDR &= ~(1 << ConfigPtr->GPIO_PinNumber);
    }
}

// Writes a value (1 or 0) to an output pin
void GPIO_WriteToOutputPin(GPIO_Type* pGPIOx, unsigned char PinNumber, unsigned char value) {
    if (value) {
        pGPIOx->PSOR = (1 << PinNumber); // Set the pin
    } else {
        pGPIOx->PCOR = (1 << PinNumber); // Clear the pin
    }
}

// Sets a GPIO output pin (forces it high)
void GPIO_SetOutputPin(GPIO_Type* pGPIOx, unsigned char PinNumber) {
    pGPIOx->PSOR = (1 << PinNumber); // Set the pin
}

// Resets a GPIO output pin (forces it low)
void GPIO_ResetOutputPin(GPIO_Type* pGPIOx, unsigned char PinNumber) {
    pGPIOx->PCOR = (1 << PinNumber); // Clear the pin
}

// Toggles the state of a GPIO output pin
void GPIO_ToggleOutputPin(GPIO_Type* pGPIOx, unsigned char PinNumber) {
    pGPIOx->PTOR = (1 << PinNumber); // Toggle the pin
}

// Reads the state of an input pin
unsigned char GPIO_ReadFromInputPin(GPIO_Type* pGPIOx, unsigned char PinNumber) {
    return ((pGPIOx->PDIR >> PinNumber) & 0x1); // Read the pin state
}
