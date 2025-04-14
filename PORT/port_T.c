#include "port_T.h"

void PORT_EnableInterrupt(PORT_Type *port, uint8_t pin, uint8_t irqc) 
{
    port->PCR[pin] = PORT_PCR_IRQC(irqc);
}


void PORT_EnableClock_PortC(void)
{
	PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock to PORT C */
}
	
void PORT_EnableClock_PortD(void)
{
	PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock to PORT D */
}

void PORT_EnableClock_PortE(void)
{
	PCC->PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORTE */
}


void PORT_Conf_GPIO_Input(PORT_Type *port, uint8_t pin_number)
{
	port->PCR[pin_number] = 0x00000110; 
}
void PORT_Conf_GPIO_Output(PORT_Type *port, uint8_t pin_number)
{
	port->PCR[pin_number] = 0x00000100; 
}

void PORT_Conf_Alt_CAN(PORT_Type *port, uint8_t pinnumber)
{
	port->PCR[pinnumber] |= PORT_PCR_MUX(5); /* Port E4: MUX = ALT5, CAN0_RX */
}
