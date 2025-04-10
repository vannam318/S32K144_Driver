#ifndef GPIO_H
#define GPIO_H

#include "GPIO_Registers.h"

typedef struct{
	GPIO_Type* 			base;
	unsigned char 	GPIO_PinNumber;
	unsigned char 	GPIO_PinMode;
} Gpio_ConfigType;
	
/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] ConfigPtr:  The configuration structure
 * @return 
 */

void GPIO_Init(const Gpio_ConfigType* ConfigPtr);
void GPIO_WriteToOutputPin(GPIO_Type* pGPIOx, unsigned char PinNumber, unsigned char value);
void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PiNumber);
void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);


#endif