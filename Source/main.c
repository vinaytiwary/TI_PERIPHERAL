#include <stdint.h>
#include <stdbool.h>

#include "TM4C1233E6PZ.h"
#include "GPIO.h"
#include "TIMER.h"
#include "common.h"
#include "schedular.h"
void delay_ms(uint32_t delay);
schedular_flg_t schedular_flg;
int main(void)
{
    //Timer0_Init();
    setGPIO_Direction(PORTH,PIN1,OUTPUT);
    writeGPIO(PORTH,PIN1,1);
    while(1)
    {
        //toggleGPIO(PORTF,PIN4);
        //writeGPIO(PORTH,PIN1,1);
        if(schedular_flg.flg_10ms==true)
        {
            schedular_flg.flg_10ms=false;
            toggleGPIO(PORTF,PIN4);
        }
        if(schedular_flg.flg_50ms==true)
        {
            schedular_flg.flg_50ms=false;
        }
        if(schedular_flg.flg_100ms==true)
        {
            schedular_flg.flg_100ms=false;
        }
        if(schedular_flg.flg_1sec==true)
        {
            schedular_flg.flg_1sec=false;
        }

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
