#ifndef NVIC_REG_H
#define NVIC_REG_H

#include <stdint.h>

/** NVIC Register Map */
typedef struct {
    volatile uint32_t ISER[8];      /**< Interrupt Set Enable Registers (0xE000E100 - 0xE000E11C) */
    uint32_t RESERVED0[24];        /**< Reserved (0xE000E120 - 0xE000E17C) */
    volatile uint32_t ICER[8];     /**< Interrupt Clear Enable Registers (0xE000E180 - 0xE000E19C) */
    uint32_t RESERVED1[24];        /**< Reserved (0xE000E1A0 - 0xE000E1FC) */
    volatile uint32_t ISPR[8];     /**< Interrupt Set Pending Registers (0xE000E200 - 0xE000E21C) */
    uint32_t RESERVED2[24];        /**< Reserved (0xE000E220 - 0xE000E27C) */
    volatile uint32_t ICPR[8];     /**< Interrupt Clear Pending Registers (0xE000E280 - 0xE000E29C) */
    uint32_t RESERVED3[24];        /**< Reserved (0xE000E2A0 - 0xE000E2FC) */
    volatile uint32_t IABR[8];     /**< Interrupt Active Bit Registers (0xE000E300 - 0xE000E31C) */
    uint32_t RESERVED4[56];        /**< Reserved (0xE000E320 - 0xE000E3FC) */
    volatile uint8_t IPR[240];     /**< Interrupt Priority Registers (0xE000E400 - 0xE000E4EF) */
    uint32_t RESERVED5[644];       /**< Reserved (0xE000E4F0 - 0xE000EFFF) */
    volatile uint32_t STIR;        /**< Software Trigger Interrupt Register (0xE000EF00) */
} NVIC_Type;

/** Peripheral NVIC base address */
#define NVIC_BASE_ADDRESS                    (0xE000E100u)

/** Peripheral NVIC base pointer */
#define NVIC                                 ((NVIC_Type *)NVIC_BASE_ADDRESS)

#endif
