/*
 * schedular.h
 *
 *  Created on: 30-Aug-2024
 *      Author: DELL
 */

#ifndef SOURCE_SCHEDULAR_H_
#define SOURCE_SCHEDULAR_H_

typedef struct
{
    volatile uint8_t flg_10ms;
    volatile uint8_t flg_50ms;
    volatile uint8_t flg_100ms;
    volatile uint8_t flg_1sec;
}schedular_flg_t;

#define SCHEDULE_10MS_CNT   10/TIMER0_VALUE
#define SCHEDULE_50MS_CNT   50/TIMER0_VALUE
#define SCHEDULE_100MS_CNT  100/TIMER0_VALUE
#define SCHEDULE_1SEC_CNT   1000/TIMER0_VALUE

void schedularInit( void );



#endif /* SOURCE_SCHEDULAR_H_ */
