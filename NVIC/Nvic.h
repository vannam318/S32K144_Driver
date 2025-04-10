#ifndef NVIC_H
#define NVIC_H

#include "Nvic_Registers.h"

typedef enum
{
  DMA_0_IRQn                   = 0u,
  LPUART1_RxTx_IRQn            = 33u,              /**< LPUART1 Transmit / Receive  Interrupt */
  PORTA_IRQn                   = 59u,              /**< Port A pin detect interrupt */
  PORTB_IRQn                   = 60u,              /**< Port B pin detect interrupt */
  PORTC_IRQn                   = 61u,              /**< Port C pin detect interrupt */
  PORTD_IRQn                   = 62u,              /**< Port D pin detect interrupt */
  PORTE_IRQn                   = 63u,              /**< Port E pin detect interrupt */
} IRQn_Type;



void NVIC_EnableInterrupt(IRQn_Type IRQ_number);
void NVIC_DisableInterrupt(IRQn_Type IRQ_number);
void NVIC_ClearPendingFlag(IRQn_Type IRQ_number);
void NVIC_SetPriority(IRQn_Type IRQ_number, unsigned char priority);

#endif
