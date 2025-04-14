#ifndef PORT_T_H
#define PORT_T_H

#include "S32K144.h"

void PORT_EnableInterrupt(PORT_Type *port, uint8_t pin, uint8_t irqc);
void PORT_EnableClock_PortC(void);
void PORT_EnableClock_PortD(void);
void PORT_EnableClock_PortE(void);
void PORT_Conf_GPIO_Input(PORT_Type *port, uint8_t pin_number);
void PORT_Conf_GPIO_Onput(PORT_Type *port, uint8_t pin_number);

#endif // PORT_T_H
