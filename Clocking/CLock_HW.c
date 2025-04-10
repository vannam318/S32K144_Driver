#include "Clock_HW.h"

// Function to initialize the System Oscillator (SOSC)
void SOSC_Initialize() {
    // Step 1: Configure SOSC dividers (SOSC_DIV1 = 2, SOSC_DIV2 = 8)
    pSOS->SCG_SOSCDIV = (1 << 0) | (7 << 8);  // Set divisor values

    // Step 2: Configure high-frequency range and high-gain mode for SOSC
    pSOS->SCG_SOSCCFG = (3 << 4) | (1 << 3);  // High frequency, high gain mode

    // Step 3: Unlock SCG_SOSCCSR register if locked
    if (pSOS->SCG_SOSCCSR & (1 << 23)) {  // Check if LK bit is set
        pSOS->SCG_SOSCCSR &= ~(1 << 23);  // Clear LK bit to unlock
    }

    // Step 4: Enable SOSC by setting the SOSCEN bit
    pSOS->SCG_SOSCCSR |= (1 << 0);

    // Step 5: Wait until SOSC becomes valid (SOSCVLD bit is set)
    while (!(pSOS->SCG_SOSCCSR & (1 << 24))) {
        // Wait for SOSC to stabilize
    }
}

// Function to initialize the System PLL (SPLL)
void SPLL_Initialize() {
    // Step 1: Disable SPLL if it's already enabled
    if (pSPLL->SCG_SPLLCSR & (1 << 0)) {
        pSPLL->SCG_SPLLCSR &= ~(1 << 0);  // Disable SPLL
    }

    // Step 2: Configure SPLL dividers (SPLLDIV1 = 2, SPLLDIV2 = 6)
    pSPLL->SCG_SPLLDIV = (1 << 1) | (5 << 8);

    // Step 3: Configure SPLL multiplier (MULT = 40) and pre-divider (PREDIV = 0)
    pSPLL->SCG_SPLLCFG = (8 << 16) | (0 << 8);

    // Step 4: Unlock SCG_SPLLCSR register if locked
    if (pSPLL->SCG_SPLLCSR & (1 << 23)) {  // Check if LK bit is set
        pSPLL->SCG_SPLLCSR &= ~(1 << 23);  // Clear LK bit to unlock
    }

    // Step 5: Enable SPLL by setting the SPLLEN bit
    pSPLL->SCG_SPLLCSR |= (1 << 0);

    // Step 6: Wait until SPLL becomes valid (SPLLVLD bit is set)
    while (!(pSPLL->SCG_SPLLCSR & (1 << 24))) {
        // Wait for SPLL to stabilize
    }
}

// Function to switch to Normal Run mode using SOSC as the clock source
void NormalRun_SOSC() {
    // Step 1: Configure SCG_RCCR to use SOSC as the clock source
    pClockRegister->SCG_RCCR &= ~(0b111 << 24);  // Clear current clock source
    pClockRegister->SCG_RCCR |= (1 << 24);       // Set SOSC as the clock source

    // Step 2: Set clock dividers for Core, Bus, and Slow clocks
    pClockRegister->SCG_RCCR = (1 << 28) | (1 << 16) | (1 << 8); // Set DIVCORE, DIVBUS, DIVSLOW

    // Step 3: Wait until SOSC becomes valid
    while (!(pSOS->SCG_SOSCCSR & (1 << 24))) {
        // Wait for SOSC to stabilize
    }
}

// Function to switch to Normal Run mode using SPLL as the clock source
void NormalRun_SPLL() {
    // Step 1: Configure SCG_RCCR to use SPLL as the clock source
    pClockRegister->SCG_RCCR &= ~(0b111 << 24);  // Clear current clock source
    pClockRegister->SCG_RCCR |= (6 << 24);       // Set SPLL as the clock source

    // Step 2: Set clock dividers for Core, Bus, and Slow clocks
    pClockRegister->SCG_RCCR = (1 << 28) | (2 << 16) | (1 << 8); // Set DIVCORE, DIVBUS, DIVSLOW

    // Step 3: Wait until SPLL becomes valid
    while (!(pSPLL->SCG_SPLLCSR & (1 << 24))) {
        // Wait for SPLL to stabilize
    }
}

// Function to initialize SPLL using FIRC as its reference clock
void SPLL_Initialize_FIRC() {
    // Step 1: Disable SPLL if already enabled
    if (pSPLL->SCG_SPLLCSR & (1 << 0)) {
        pSPLL->SCG_SPLLCSR &= ~(1 << 0);  // Disable SPLL
    }

    // Step 2: Configure SPLL dividers (SPLLDIV1 = 2, SPLLDIV2 = 6)
    pSPLL->SCG_SPLLDIV = (1 << 1) | (5 << 8);

    // Step 3: Configure SPLL multiplier (MULT = 40) and pre-divider (PREDIV = 4)
    pSPLL->SCG_SPLLCFG = (8 << 16) | (4 << 8);

    // Step 4: Unlock SCG_SPLLCSR register if locked
    if (pSPLL->SCG_SPLLCSR & (1 << 23)) {  // Check if LK bit is set
        pSPLL->SCG_SPLLCSR &= ~(1 << 23);  // Clear LK bit to unlock
    }

    // Step 5: Enable SPLL by setting the SPLLEN bit
    pSPLL->SCG_SPLLCSR |= (1 << 0);

    // Step 6: Wait until SPLL becomes valid (SPLLVLD bit is set)
    while (!(pSPLL->SCG_SPLLCSR & (1 << 24))) {
        // Wait for SPLL to stabilize
    }
}

// Function for clock transition using FIRC
void FIRC_TRansition() {
    // Step 1: Update clock configuration to switch to FIRC
    pClockRegister->SCG_RCCR |= ((1 << 24) | (1 << 25));  // Set FIRC as source for both system and high-speed clocks
    pClockRegister->SCG_HCCR |= ((1 << 24) | (1 << 25));

    // Step 2: Enable low power mode for clock transition
    pSMC->SMC_PMPROT |= (1 << 7);  // Allow low power mode transition
    pSMC->SMC_PMCTRL |= (3 << 5);  // Enable sleep and deep sleep modes

    // Step 3: Wait for the transition to complete
    while (!(pSMC->SMC_PMSTAT & (1 << 7))) {
        // Wait for clock transition to finish
    }
}

// Function to configure the system to run at high speed using SPLL
void HighSpeed_Run_SPLL() {
    // Step 1: Disable SPLL if already enabled
    if (pSPLL->SCG_SPLLCSR & (1 << 0)) {
        pSPLL->SCG_SPLLCSR &= ~(1 << 0);  // Disable SPLL
    }

    // Step 2: Configure SPLL for 112 MHz (multiplier = 16, divider = 2)
    pSPLL->SCG_SPLLDIV = (1 << 0) | (3 << 8);  // SPLL_DIV1 = 1, SPLL_DIV2 = 3
    pSPLL->SCG_SPLLCFG = (16 << 16) | (1 << 8);  // Multiplier = 16, Pre-divider = 1

    // Step 3: Enable SPLL
    pSPLL->SCG_SPLLCSR = (1 << 0);  // Enable SPLL
    while (!(pSPLL->SCG_SPLLCSR & (1 << 24))) {
        // Wait for SPLL to stabilize
    }

    // Step 4: Configure dividers for Core, Bus, and Slow clocks
    pClockRegister->SCG_RCCR =
        (6 << 28) |  // Select SPLL as the system clock source (SCS = 0110)
        (0 << 16) |  // DIVCORE = 0 (112 MHz)
        (1 << 12) |  // DIVBUS = 1 (56 MHz)
        (3 << 8);    // DIVSLOW = 3 (28 MHz)

    // Step 5: Wait for the clock switch to complete
    while ((pClockRegister->SCG_RCCR & (0xF << 28)) != (6 << 28)) {
        // Wait until SPLL is selected as the system clock source
    }
}

// Function to initialize the clock output on Port C Pin 3 (CLKOUT)
void CLKOUT_Initialize() {
    // Step 1: Configure Port C Pin 3 for CLKOUT functionality
    *pPRC = (*pPRC & ~0x0700) | (1 << 8);  // Set MUX to 001 (CLKOUT)

    // Step 2: Select System Oscillator (SOSC) as the clock source for CLKOUT
    *pCHIPCTL = (*pCHIPCTL & ~0x03) | (0x01 << 0);

    // Step 3: Set divide ratio to 4 (8 MHz / 4 = 2 MHz)
    *pCHIPCTL = (*pCHIPCTL & ~0x1F00) | (3 << 8);

    // Step 4: Enable CLKOUT output
    *pCHIPCTL |= (1 << 0);  // Set CLKOUTEN bit to enable output
}