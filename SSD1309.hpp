#pragma once 

#include "I2c.hpp"
#include "OutputPort.hpp"

class SSD1309
{
    public:
        SSD1309(I2c &com, OutputPort &reset, volatile uint8_t* port, uint8_t addr, uint8_t max);
        bool init();
        bool clrScreen();
        bool gotoRealXY(uint8_t x, uint8_t y);
        bool gotoXY(uint8_t x, uint8_t y);
        bool writeChar(char c);
        bool writeString(const char* str);
        void setFontSize(uint8_t size);
        void drawArrowUp();
        void drawArrowDown();
        void restart();

    private:
        I2c Com;
        OutputPort Reset;
        volatile uint8_t* port;
        uint8_t addr;
        uint8_t max;
        uint8_t font_size;
        uint8_t pos_x;
        uint8_t pos_y;
};