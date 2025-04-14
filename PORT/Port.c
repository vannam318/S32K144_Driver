#include "Port.h"

void Port_SetGPIO(Port_Type *Port,unsigned char pin){
	Port->PCRn[pin] &= ~(7<<8);
	Port->PCRn[pin] |= 1;
}

void Port_Pull(Port_Type *Port,unsigned char pin, unsigned char pull){
	if (pull == Pull_Down){
		Port->PCRn[pin] |= (1<<1);
		Port->PCRn[pin] &= ~(1<<0);
	}
	else if (pull == Pull_Up){
		Port->PCRn[pin] |= (1<<1);
		Port->PCRn[pin] = (1<<0);
	}
	if (pull == No_Pull){
		Port->PCRn[pin] &= ~(1<<1);
	}
}