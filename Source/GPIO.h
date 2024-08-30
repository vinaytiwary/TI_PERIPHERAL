#ifndef GPIO_H_
#define GPIO_H_


//#define GPIO_AHB
#define GPIO_CLK_R       (*((volatile uint32_t *)0x400FE608))
// Base addresses for GPIO ports as integers
#ifndef GPIO_AHB
#define PORTA  (0x40004000)
#define PORTB  (0x40005000)
#define PORTC  (0x40006000)
#define PORTD  (0x40007000)
#define PORTE  (0x40024000)
#define PORTF  (0x40025000)
#define PORTG  (0x40026000)
#define PORTH  (0x40027000)
#define PORTJ  (0x4006A000)
#define PORTK  (0x4006B000)
#else
#define PORTA  (0x40058000) // AHB Base Address for PORTA
#define PORTB  (0x40059000) // AHB Base Address for PORTB
#define PORTC  (0x4005A000) // AHB Base Address for PORTC
#define PORTD  (0x4005B000) // AHB Base Address for PORTD
#define PORTE  (0x4005C000) // AHB Base Address for PORTE
#define PORTF  (0x4005D000) // AHB Base Address for PORTF
#define PORTG  (0x4005E000) // AHB Base Address for PORTG
#define PORTH  (0x4005F000) // AHB Base Address for PORTH
#define PORTJ  (0x40060000) // AHB Base Address for PORTJ
#define PORTK  (0x40061000) // AHB Base Address for PORTK
#endif
// Offsets
#define DIRECTION_PORT_OFFSET  (0x400)
#define ENABLE_DIGITAL_OFFSET  (0x51C)
#define DATA_REGISTER_OFFSET   (0x3FC)

// Pin definitions
#define PIN0   (0)
#define PIN1   (1)
#define PIN2   (2)
#define PIN3   (3)
#define PIN4   (4)
#define PIN5   (5)
#define PIN6   (6)
#define PIN7   (7)

// Port numbers for enabling clock
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
#define PORT_INVALID (0x00)

// Function prototypes
void writeGPIO(uint32_t portBase, uint8_t pin, bool state);
bool readGPIO(uint32_t portBase, uint8_t pin);
void toggleGPIO(uint32_t portBase, uint8_t pin);
void setGPIO_Direction(uint32_t portBase, uint8_t pin, bool direction);
bool getGPIO_Direction(uint32_t portBase, uint8_t pin);
bool enableGPIOClock(uint32_t portBase);
uint16_t getPortNum(uint32_t portBase);

#endif /* GPIO_H_ */
