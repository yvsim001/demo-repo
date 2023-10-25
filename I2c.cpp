#include <avr/io.h>
#include <util/delay.h>

#include "I2c.hpp"

I2c::I2c(uint8_t sda, uint8_t scl, volatile uint8_t* port, uint32_t frequency) : sda(sda), scl(scl), port(port), frequency(frequency){
    *reinterpret_cast<volatile uint8_t*> (port) |= (1<<sda | 1<<scl);
    TWCR = 0;
    TWSR = 0;
    TWBR = ((F_CPU/frequency)-16)/2;
    _delay_ms(50);
}
bool I2c::start(uint8_t addr){
    uint8_t timeout = 0;

    TWCR = (1<< TWINT | 1<<TWSTA | 1<<TWEN);
    while(!(TWCR & (1<<TWINT)));

    TWDR = addr;
    TWCR = (1<<TWINT | 1<<TWEN);
    while(!(TWCR & (1<<TWINT)));

    while((TWSR & 0xF8) != 0x18){
        if(timeout++ >= 100) return false;

        TWDR = addr;
        TWCR = (1<<TWINT | 1<<TWEN);
        while(!(TWCR & (1<<TWINT)));
    }

    return true;
}
bool I2c::sendByte(uint8_t byte){
    uint8_t timeout = 0;

    TWDR = byte;
    TWCR = (1<<TWINT | 1<<TWEN);
    while(!(TWCR & (1<<TWINT)));

    while((TWSR & 0xF8) != 0x28){
        if(timeout++ >= 100) return false;

        TWDR = byte;
        TWCR = (1<<TWINT | 1<<TWEN);
        while(!(TWCR & (1<<TWINT)));

    }

    return true;
}
void I2c::stop(){
    TWCR = (1<<TWINT | 1<<TWSTO | 1<<TWEN);
    TWCR = 0;
}
