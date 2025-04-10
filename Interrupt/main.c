#define PCC_PORTC           (*(volatile unsigned int*)(0x40065000u + 0x12C))
#define PORTC_PCR_PIN12     (*(volatile unsigned int*)(0x4004B000u + 0x30))
#define GPIOC_PDDR          (*(volatile unsigned int*)(0x400FF080u + 0x12))    
#define GPIOC_PDIR          (*(volatile const unsigned int*)(0x400FF080u + 0x10))

#define PCC_PORTD           (*(volatile unsigned int*)(0x40065000u + 0x130))   
#define PORTD_PCR_PIN16     (*(volatile unsigned int*)(0x4004C000 + 16*4))
#define PORTD_PCR_PIN0      (*(volatile unsigned int*)(0x4004C000 + 0*4))
#define PORTD_PCR_PIN15     (*(volatile unsigned int*)(0x4004C000 + 15*4))
#define GPIOD_PDDR          (*(volatile unsigned int*)(0x400FF0C0 + 0x14))
#define GPIOD_PDOR          (*(volatile unsigned int*)(0x400FF0C0 + 0))
    
#define NVIC_ISER_1         (*(volatile unsigned int*)(0xE000E100u + 4*1))
    
volatile int state = 0;  // Initialize to 0 (Reset state)

int main() {
    // Step 1: Interrupt enable register 
    NVIC_ISER_1 |= (1 << 29);
    
    /*------- Config Button --------*/
    // Step 1: Enable clock for Port C
    PCC_PORTC |= (1 << 30);
    
    // Step 2: Configure Pin 12 of Port C as GPIO
    PORTC_PCR_PIN12 |= (1 << 8);
    
    // Step 3: Set rising-edge interrupt 
    PORTC_PCR_PIN12 |= (9 << 16);
    
    // Step 4: Configure Pin 12 as input 
    GPIOC_PDDR &= ~(1 << 12);
    
    /*------ Config LEDs: Green / Red / Blue --------*/
    // Step 1: Enable clock for Port D
    PCC_PORTD |= (1 << 30);
    
    // Step 2: Configure Pins 16 (Green), 15 (Red), and 0 (Blue) as GPIO
    PORTD_PCR_PIN16 |= (1 << 8);
    PORTD_PCR_PIN15 |= (1 << 8);
    PORTD_PCR_PIN0  |= (1 << 8);
    
    // Step 3: Configure Pins 16, 15, 0 as outputs
    GPIOD_PDDR |= ((1 << 16) | (1 << 15) | (1 << 0));
    
    // Turn on Green LED initially (Reset state)
		GPIOD_PDOR |= (0xffffffff);
		GPIOD_PDOR = ~(1 << 16);
    while (1) {
        // Main loop can be used for additional tasks if needed
    }
}

void PORTC_IRQHandler(void) {
    // Check interrupt flag and clear it
    if (PORTC_PCR_PIN12 & (1 << 24)) {
        PORTC_PCR_PIN12 |= (1 << 24);
        
        // Update state
        state = (state + 1) % 3;  // Reset to 0 after 3
        
        // Control LEDs based on state
        switch (state) {
            case 0:  // Green state
									GPIOD_PDOR |= (0xffffffff);
                GPIOD_PDOR = ~(1 << 16);  // Green ON, others OFF
                break;
            case 1:  // Red state
									GPIOD_PDOR |= (0xffffffff);
                GPIOD_PDOR = ~(1 << 15);  // Red ON, others OFF
                break;
            case 2:  // Blue state
								GPIOD_PDOR |= (0xffffffff);
                GPIOD_PDOR = ~(1 << 0);   // Blue ON, others OFF
                break;
            default:
              
                break;
        }
    }
}
