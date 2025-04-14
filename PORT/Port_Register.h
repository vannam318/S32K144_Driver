#ifndef	PORT_REGISTER_H
#define PORT_REGISTER_H

typedef struct{
	unsigned int PCRn[32];
	unsigned int GPCLR;
	unsigned int GPCHR;
	unsigned int GICLR;
	unsigned int GICHR;
	unsigned int ISFR;
	unsigned int DFER;
	unsigned int DFCR;
	unsigned int DFWR;
} Port_Type;

#define	PortA_Base							(0x40049000)
#define	PortB_Base							(0x4004A000)
#define	PortC_Base							(0x4004B000)
#define	PortD_Base							(0x4004C000)
#define	PortE_Base							(0x4004D000)

#define PORTA										(Port_Type*)(PortA_Base)
#define PORTB										(Port_Type*)(PortB_Base)
#define PORTC										(Port_Type*)(PortC_Base)
#define PORTD										(Port_Type*)(PortD_Base)
#define PORTE										(Port_Type*)(PortE_Base)

#endif