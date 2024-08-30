#include <stdint.h>
#include <stdbool.h>
#include "tm4c1233e6pz.h"
#include "TIMER.h"
#include "schedular.h"

schedular_flg_t schedular_flg;

void Timer0_Init()
{
    uint32_t load_value = (SYSTEM_CLOCK_HZ / 1000) * TIMER0_VALUE - 1;

    SYSCTL_RCGCTIMER_R |= 0x01; // Enable Timer 0
    TIMER0_CTL_R &= ~0x01;      // Disable Timer 0
    TIMER0_CFG_R = 0x00;        // 32-bit mode
    TIMER0_TAMR_R = 0x02;       // Periodic mode
    TIMER0_TAILR_R = load_value; // Load interval
    TIMER0_ICR_R = 0x01;        // Clear interrupt
    TIMER0_IMR_R = 0x01;        // Enable interrupt
    TIMER0_CTL_R |= 0x01;       // Enable Timer 0

    NVIC_EN0_R |= (1 << 19);    // Enable Timer 0 interrupt in NVIC
}


void Timer0_Handler(void)
{
    static unsigned char cnt_50ms = 0;
    static unsigned char cnt_100ms = 0;
    static unsigned int cnt_1sec = 0;

    TIMER0_ICR_R = 0x01; // Clear interrupt flag

    schedular_flg.flg_10ms  = true;
    if(cnt_50ms++ >= SCHEDULE_50MS_CNT)
    {
        cnt_50ms = 0;
        schedular_flg.flg_50ms  = true;
    }
    if(cnt_100ms++ >= SCHEDULE_100MS_CNT)
    {
        cnt_100ms = 0;
        schedular_flg.flg_100ms = true;
    }
    if(cnt_1sec++ >= SCHEDULE_1SEC_CNT)
    {
        cnt_1sec = 0;
        schedular_flg.flg_1sec = true;
    }
}

