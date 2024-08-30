#include <stdint.h>
#include <stdbool.h>

#include "TM4C1233E6PZ.h"
#include "GPIO.h"
#include "TIMER.h"
#include "common.h"

void delay_ms(uint32_t delay);
int main(void)
{
    //Timer0_Init();
    setGPIO_Direction(PORTH,PIN1,OUTPUT);
    writeGPIO(PORTH,PIN1,1);
    while(1)
    {
        //toggleGPIO(PORTF,PIN4);
        writeGPIO(PORTH,PIN1,1);
       // delay_ms(1000);
    }
}

void delay_ms(uint32_t delay)
{
    uint32_t i;
    uint32_t cycles = (SYSTEM_CLOCK_HZ / 3000) * delay;  // Approximate loop cycles for 1 ms delay

    for (i = 0; i < cycles; i++) {
        // Empty loop to create delay
        __asm("NOP");
    }
}
