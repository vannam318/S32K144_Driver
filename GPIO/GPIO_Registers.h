#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

/** GPIO - Register Layout Typedef */
typedef struct {
  volatile unsigned int PDOR;
	volatile unsigned int PSOR;
	volatile unsigned int PCOR;
	volatile unsigned int PTOR;
	volatile const unsigned int PDIR;
	volatile unsigned int PDDR;
	volatile unsigned int PIDR;
} GPIO_Type;

/** Peripheral GPIO base address */
#define GPIOA_BASE 	0x40010800
#define GPIOB_BASE 	0x40010C00
#define GPIOC_BASE 	0x40011000
#define GPIOD_BASE 	0x40011400
#define GPIOE_BASE 	0x40011800
#define GPIOF_BASE 	0x40011C00
#define GPIOG_BASE 	0x40012000

/** Peripheral GPIO pointer */
#define pGPIOA 			((GPIO_Type*) GPIOA_BASE)
#define pGPIOB			((GPIO_Type*) GPIOB_BASE)
#define pGPIOC			((GPIO_Type*) GPIOC_BASE)
#define pGPIOD			((GPIO_Type*) GPIOD_BASE)
#define pGPIOE			((GPIO_Type*) GPIOE_BASE)
#define pGPIOF			((GPIO_Type*) GPIOF_BASE)
#define pGPIOG			((GPIO_Type*) GPIOG_BASE)

#endif /* GPIO_REGISTERS_H */
