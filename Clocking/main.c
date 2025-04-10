#include "Clock_HW.h"
#include <stdio.h>


int main() {
    // Example 1: Initialize the System Oscillator (SOSC)
    SOSC_Initialize();
    // After initialization, SOSC should be stable and ready for use
    printf("SOSC Initialized and Stable\n");

    // Example 2: Initialize the System PLL (SPLL)
    SPLL_Initialize();
    // After initialization, SPLL should be stable and ready for use
    printf("SPLL Initialized and Stable\n");

    // Example 3: Switch to Normal Run mode using SOSC as the clock source
    NormalRun_SOSC();
    // After switching, the system should be using SOSC as the clock source
    printf("Switched to Normal Run mode using SOSC\n");

    // Example 4: Switch to Normal Run mode using SPLL as the clock source
    NormalRun_SPLL();
    // After switching, the system should be using SPLL as the clock source
    printf("Switched to Normal Run mode using SPLL\n");

    // Example 5: Initialize SPLL using FIRC as its reference clock
    SPLL_Initialize_FIRC();
    // After initialization, SPLL should be stable with FIRC as the reference
    printf("SPLL Initialized using FIRC as reference\n");

    // Example 6: Perform a clock transition using FIRC
    FIRC_TRansition();
    // After transition, the system should be using FIRC as the clock source
    printf("Clock transition to FIRC completed\n");

    // Example 7: Configure the system to run at high speed using SPLL
    HighSpeed_Run_SPLL();
    // After configuration, the system should be running at high speed using SPLL
    printf("System running at high speed using SPLL\n");

    // Example 8: Initialize CLKOUT to output the system clock
    CLKOUT_Initialize();
    // After initialization, CLKOUT should output the system clock at the specified frequency
    printf("CLKOUT Initialized and Outputting Clock\n");

    // Keep the system running or go to sleep
    while (1) {
    }

    return 0;
}
