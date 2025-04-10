#include <stdint.h>
#include "GPIO.h"


#define PORTC_BASE_ADDR  0x4004B000
#define GPIOC_BASE_ADDR  0X400FF080
#define PORTD_BASE_ADDR  0x4004C000
#define GPIOD_BASE_ADDR  0x400FF0C0

#define PCC_PORTC 			 0x12C
#define PCC_PORTD				 0x130
#define PCC_BASE_ADDR 	 0x40065000
#define pPCC_PORTC 			(unsigned int*)(PCC_BASE_ADDR + PCC_PORTC)
#define pPCC_PORTD 		  (unsigned int*)(PCC_BASE_ADDR + PCC_PORTD)
	
#define GREEN_LED_BASE_ADDR 	16
#define BLUE_LED_BASE_ADDR		0

// Delay function
void delay_ms(uint32_t ms) {
    for (volatile uint32_t i = 0; i < ms * 4000; i++) {
        __asm("NOP");
    }
}


int main(){
	
//Enable Clock
	*pPCC_PORTC = 0x40000000;
	*pPCC_PORTD = 0x40000000;

//Setting MUX
	unsigned int* pPortC_PCR13 = (unsigned int*)(PORTC_BASE_ADDR + 0x34);
	*pPortC_PCR13 = (*pPortC_PCR13 & ~0x0700) | (1 << 8);
	unsigned int* pPortD_PCR16 = (unsigned int*)(PORTD_BASE_ADDR + 0x40);
	*pPortD_PCR16 = (*pPortD_PCR16 & ~0x0700) | (1 << 8);
	unsigned int* pPortD_PCR0 = (unsigned int*)(PORTD_BASE_ADDR + 0x00);
	*pPortD_PCR0 = (*pPortD_PCR0 & ~0x0700) | (1 << 8 );

//Setting Pins 
	unsigned int* pPortC_PDDR = (unsigned int*)(GPIOC_BASE_ADDR + 0x14);
	*pPortC_PDDR &= ~(1 << 13); // setting input
	unsigned int* pPortD_PDDR_LG = (unsigned int*)(GPIOD_BASE_ADDR + 0x14);
	*pPortD_PDDR_LG |= (1 << GREEN_LED_BASE_ADDR ); // setting ouput 
	unsigned int* pPortD_PDDR_LB = (unsigned int*)(GPIOD_BASE_ADDR + 0x14);
	*pPortD_PDDR_LB |= (1 << BLUE_LED_BASE_ADDR); // setting output 
	
//Set-Clear Registor 
	unsigned int* LED_GREEN_PSOR = (unsigned int*)(GPIOD_BASE_ADDR + 0x04);
	unsigned int* LED_GREEN_PCOR = (unsigned int*)(GPIOD_BASE_ADDR + 0x08);
	
	unsigned int* LED_BLUE_PSOR  = (unsigned int*)(GPIOD_BASE_ADDR + 0x04);
	unsigned int* LED_BLUE_PCOR  = (unsigned int*)(GPIOD_BASE_ADDR + 0x08);

//Data Input Register
	unsigned int* SW13_PDIR 		 = (unsigned int*)(GPIOC_BASE_ADDR + 0x10);
	
// Turn off all lights 
	*LED_GREEN_PCOR = (1 << GREEN_LED_BASE_ADDR);
	*LED_BLUE_PSOR  = (1 << BLUE_LED_BASE_ADDR);

// Logic
   uint8_t state = 0;

while(1){
//	if((*SW13_PDIR & (1 << 13)) == 0){
//		delay_ms(50);
//	} 
		state = (*SW13_PDIR>>13)&0x01;
		if(state){
					*LED_GREEN_PSOR = (1 << GREEN_LED_BASE_ADDR);
					*LED_BLUE_PCOR  = (1 << BLUE_LED_BASE_ADDR);
			}else{
					*LED_GREEN_PCOR = (1 << GREEN_LED_BASE_ADDR);
					*LED_BLUE_PSOR  = (1 << BLUE_LED_BASE_ADDR);
			}
		}
//	}		
}


