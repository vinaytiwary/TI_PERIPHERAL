
#include <stdint.h>
#include <stdbool.h>
#include "GPIO.h"


void writeGPIO(uint32_t portBase, uint8_t pin, bool state)
{
    if (pin > PIN7 || !enableGPIOClock(portBase))
    {
        return;
    }

    volatile uint32_t* dataRegister = (volatile uint32_t*)(portBase + DATA_REGISTER_OFFSET);

    if (state)
    {
        *dataRegister |= (1 << pin);
    }
    else
    {
        *dataRegister &= ~(1 << pin);
    }
}

bool readGPIO(uint32_t portBase, uint8_t pin)
{
    if (pin > PIN7 || !enableGPIOClock(portBase))
    {
        return false;
    }

    volatile uint32_t* dataRegister = (volatile uint32_t*)(portBase + DATA_REGISTER_OFFSET);
    return ((*dataRegister & (1 << pin)) != 0);
}
void toggleGPIO(uint32_t portBase, uint8_t pin)
{
    if (pin > PIN7 || !enableGPIOClock(portBase))
    {
        return;
    }

    volatile uint32_t* dataRegister = (volatile uint32_t*)(portBase + DATA_REGISTER_OFFSET);

    *dataRegister ^=(1<<pin);
}
void setGPIO_Direction(uint32_t portBase, uint8_t pin, bool direction)
{
    if (pin > PIN7 || !enableGPIOClock(portBase))
    {
        return;
    }

    volatile uint32_t* directionRegister = (volatile uint32_t*)(portBase + DIRECTION_PORT_OFFSET);
    volatile uint32_t* digitalEnableRegister = (volatile uint32_t*)(portBase + ENABLE_DIGITAL_OFFSET);

    if (direction)
    {
        *directionRegister |= (1 << pin);
    }
    else
    {
        *directionRegister &= ~(1 << pin);
    }

    *digitalEnableRegister |= (1 << pin);
}

bool getGPIO_Direction(uint32_t portBase, uint8_t pin)
{
    if (pin > PIN7 || !enableGPIOClock(portBase))
    {
        return false;
    }

    volatile uint32_t* directionRegister = (volatile uint32_t*)(portBase + DIRECTION_PORT_OFFSET);
    return ((*directionRegister & (1 << pin)) != 0);
}

bool enableGPIOClock(uint32_t portBase)
{
    uint16_t portNum = getPortNum(portBase);
    if (portNum != PORT_INVALID)
    {
        GPIO_CLK_R |= portNum;
        return true;
    }
    return false;
}

uint16_t getPortNum(uint32_t portBase)
{
    return (portBase == PORTA) ? PORTA_NUM :
           (portBase == PORTB) ? PORTB_NUM :
           (portBase == PORTC) ? PORTC_NUM :
           (portBase == PORTD) ? PORTD_NUM :
           (portBase == PORTE) ? PORTE_NUM :
           (portBase == PORTF) ? PORTF_NUM :
           (portBase == PORTG) ? PORTG_NUM :
           (portBase == PORTH) ? PORTH_NUM :
           (portBase == PORTJ) ? PORTJ_NUM :
           (portBase == PORTK) ? PORTK_NUM : PORT_INVALID;
}
