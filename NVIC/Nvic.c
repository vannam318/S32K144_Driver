#include "Nvic.h"




void NVIC_EnableInterrupt(IRQn_Type IRQ_number)
{
    /* Enable the interrupt in the ISER register */
    NVIC->ISER[IRQ_number / 32] = (1u << (IRQ_number % 32));
}

void NVIC_DisableInterrupt(IRQn_Type IRQ_number)
{
    /* Disable the interrupt in the ICER register */
    NVIC->ICER[IRQ_number / 32] = (1u << (IRQ_number % 32));
}

void NVIC_ClearPendingFlag(IRQn_Type IRQ_number)
{
    /* Clear the pending flag in the ICPR register */
    NVIC->ICPR[IRQ_number / 32] = (1u << (IRQ_number % 32));
}

void NVIC_SetPriority(IRQn_Type IRQ_number, unsigned char priority)
{
    /* Set the priority for the interrupt in the IPR register */
    NVIC->IPR[IRQ_number] = priority & 0xFFu; // Mask to 8 bits
}
