#ifndef CLOCK_HW_H
#define CLOCK_HW_H

#include <stdint.h>
#include "Clock_Driver.h"

// Function prototypes
void SOSC_Initialize(void);
void SPLL_Initialize(void);
void NormalRun_SOSC(void);
void NormalRun_SPLL(void);
void SPLL_Initialize_FIRC(void);
void FIRC_TRansition(void);
void HighSpeed_Run_SPLL(void);
void CLKOUT_Initialize(void);

#endif // CLOCK_HW_H