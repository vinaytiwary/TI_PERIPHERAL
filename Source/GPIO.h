/*
 * GPIO.h
 *
 *  Created on: 28-Aug-2024
 *      Author: DELL
 */

#ifndef GPIO_H_
#define GPIO_H_

//#define true  (1)
//#define false (0)

#define PORTA  (GPIO_PORTA_DATA_R)
#define PORTB  (GPIO_PORTB_DATA_R)
#define PORTC  (GPIO_PORTC_DATA_R)
#define PORTD  (GPIO_PORTD_DATA_R)
#define PORTE  (GPIO_PORTE_DATA_R)
#define PORTF  (GPIO_PORTF_DATA_R)
#define PORTG  (GPIO_PORTG_DATA_R)
#define PORTH  (GPIO_PORTH_DATA_R)
#define PORTJ  (GPIO_PORTJ_DATA_R)
#define PORTK  (GPIO_PORTK_DATA_R)

#define DIRECTION_PORT_OFFSET  (0x04)
#define ENABLE_DIGITAL_OFFSET  (0X120)

#define PIN0   (0)
#define PIN1   (1)
#define PIN2   (2)
#define PIN3   (3)
#define PIN4   (4)
#define PIN5   (5)
#define PIN6   (6)
#define PIN7   (7)

#define PORTA_NUM  (0x01)
#define PORTB_NUM  (0x02)
#define PORTC_NUM  (0x04)
#define PORTD_NUM  (0x08)
#define PORTE_NUM  (0x10)
#define PORTF_NUM  (0x20)
#define PORTG_NUM  (0x40)
#define PORTH_NUM  (0x80)
#define PORTJ_NUM  (0x100)
#define PORTK_NUM  (0x200)
#define PORT_INVALID (0X00)

void writeGPIO(uint32_t PORT,uint8_t pin, bool state);
bool readGPIO(uint32_t PORT,uint8_t pin);
void setGPIO_Direction(uint32_t PORT , uint8_t pin, bool state);
bool getGPIO_Direction(uint32_t PORT, uint8_t pin);
bool enableGPIOClock(uint32_t portBase);
uint16_t getPortNum(uint32_t port);
#endif /* GPIO_H_ */
