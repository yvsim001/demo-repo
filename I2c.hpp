#pragma once 

class I2c
{
    public:
        I2c(uint8_t sda, uint8_t scl, volatile uint8_t* port, uint32_t frequency);
        bool start(uint8_t addr);
        bool sendByte(uint8_t byte);
        void stop();
    private:
        uint8_t sda;
        uint8_t scl;
        volatile uint8_t* port;
        uint32_t frequency;
};