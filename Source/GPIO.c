#include <stdint.h>
#include <stdbool.h>
#include "TM4C1233E6PZ.h"

#include "GPIO.h"

void writeGPIO(uint32_t port, uint8_t pin, bool state)
{
    if((pin > PIN7) ||
       (port != GPIO_PORTA_DATA_R && port != GPIO_PORTB_DATA_R &&
        port != GPIO_PORTC_DATA_R && port != GPIO_PORTD_DATA_R &&
        port != GPIO_PORTE_DATA_R && port != GPIO_PORTF_DATA_R &&
        port != GPIO_PORTG_DATA_R && port != GPIO_PORTH_DATA_R &&
        port != GPIO_PORTJ_DATA_R && port != GPIO_PORTK_DATA_R))
    {
        return;
    }

    volatile uint32_t* portAddress = (volatile uint32_t*)port;

    if(state)
    {
        *portAddress |= (1 << pin);
    }
    else
    {
        *portAddress &= ~(1 << pin);
    }
}

bool readGPIO(uint32_t port, uint8_t pin)
{
    volatile uint32_t* portAddress = (volatile uint32_t*)port;
    return ((*portAddress & (1 << pin)) != 0);
}

void setGPIO_Direction(uint32_t port, uint8_t pin, bool state)
{
    if(enableGPIOClock(port))
    {
        volatile uint32_t* directionAddress = (volatile uint32_t*)(port + DIRECTION_PORT_OFFSET);
        volatile uint32_t* digitalEnableAddress = (volatile uint32_t*)(port + ENABLE_DIGITAL_OFFSET);

        if(state)
        {
            *directionAddress |= (1 << pin);
        }
        else
        {
            *directionAddress &= ~(1 << pin);
        }
        *digitalEnableAddress |= (1 << pin);
    }
}

bool getGPIO_Direction(uint32_t port, uint8_t pin)
{
    volatile uint32_t* directionAddress = (volatile uint32_t*)(port + DIRECTION_PORT_OFFSET);
    return ((*directionAddress & (1 << pin)) != 0);
}

bool enableGPIOClock(uint32_t port)
{
    uint8_t clkPort = getPortNum(port);
    if(clkPort)
    {
        SYSCTL_RCGCGPIO_R |= clkPort;
    }
    else
    {
        return false;
    }
    return true;
}


uint16_t getPortNum(uint32_t port)
{
    return (port == GPIO_PORTA_DATA_R || port == GPIO_PORTA_AHB_DATA_R) ? PORTA_NUM :
           (port == GPIO_PORTB_DATA_R || port == GPIO_PORTB_AHB_DATA_R) ? PORTB_NUM :
           (port == GPIO_PORTC_DATA_R || port == GPIO_PORTC_AHB_DATA_R) ? PORTC_NUM :
           (port == GPIO_PORTD_DATA_R || port == GPIO_PORTD_AHB_DATA_R) ? PORTD_NUM :
           (port == GPIO_PORTE_DATA_R || port == GPIO_PORTE_AHB_DATA_R) ? PORTE_NUM :
           (port == GPIO_PORTF_DATA_R || port == GPIO_PORTF_AHB_DATA_R) ? PORTF_NUM :
           (port == GPIO_PORTG_DATA_R || port == GPIO_PORTG_AHB_DATA_R) ? PORTG_NUM :
           (port == GPIO_PORTH_DATA_R || port == GPIO_PORTH_AHB_DATA_R) ? PORTH_NUM :
           (port == GPIO_PORTJ_DATA_R || port == GPIO_PORTJ_AHB_DATA_R) ? PORTJ_NUM :
           (port == GPIO_PORTK_DATA_R) ? PORTK_NUM : PORT_INVALID;
}
