#include "Port_Register.h"

typedef struct{
	Port_Type								*base;
	unsigned char						pull;
	unsigned char						mux;
}Port_ConfigType;

#define Pull_Up									0	
#define Pull_Down								1
#define No_Pull									2

void Port_SetGPIO(Port_Type *Port,unsigned char pin);

void Port_Pull(Port_Type *Port,unsigned char pin, unsigned char pull);