#ifndef CLOCK_DRIVER_H
#define CLOCK_DRIVER_H

typedef struct {
    volatile unsigned int SCG_CSR;
    volatile unsigned int SCG_RCCR;
    volatile unsigned int SCG_VCCR;
    volatile unsigned int SCG_HCCR;
    volatile unsigned int SCG_CLKOUTCNFG;
} SCG_ClockRegister;

typedef struct {
    volatile unsigned int SCG_SOSCCSR;
    volatile unsigned int SCG_SOSCDIV;
    volatile unsigned int SCG_SOSCCFG;
} SCG_SOS;

typedef struct {
    volatile unsigned int SCG_SIRCCSR;
    volatile unsigned int SCG_SIRCDIV;
    volatile unsigned int SCG_SIRCCFG;
} SCG_SIRC;

typedef struct {
    volatile unsigned int SCG_FIRCCSR;
    volatile unsigned int SCG_FIRCDIV;
    volatile unsigned int SCG_FIRCCFG;
} SCG_FIRC;

typedef struct {
    volatile unsigned int SCG_SPLLCSR;
    volatile unsigned int SCG_SPLLDIV;
    volatile unsigned int SCG_SPLLCFG;
} SCG_SPLL;

typedef struct {
		volatile unsigned int SMC_VERID;
		volatile unsigned int SMC_PARAM;
		volatile unsigned int SMC_PMPROT;
		volatile unsigned int SMC_PMCTRL;
		volatile unsigned int SMC_STOPCTRL;
		volatile unsigned int SMC_PMSTAT;
}SMC;



#define SCG_BASE 0x40064000
#define SMC_BASE 0x4007E000
#define SIM_BASE 0x40048000
#define PORTC 	 0x4004B000

#define pPRC		 (unsigned int*)(PORTC + 0xC) 


#define pCHIPCTL (unsigned int*)(SIM_BASE + 0x4)

#define pSMC					 ((SMC*)	SMC_BASE)

#define pClockRegister ((SCG_ClockRegister*)(SCG_BASE + 0x10))
#define pSOS           ((SCG_SOS*)(SCG_BASE + 0x100))
#define pSIRC          ((SCG_SIRC*)(SCG_BASE + 0x200))
#define pFIRC          ((SCG_FIRC*)(SCG_BASE + 0x300))
#define pSPLL          ((SCG_SPLL*)(SCG_BASE + 0x600))

#endif
