#pragma once 

#include "Port.hpp"
class OutputPort : Port
{
    public:
        OutputPort(volatile uint8_t* p, volatile uint8_t* pd, volatile uint8_t* pi, uint8_t b);
        void toggle();
        void setHigh();
        void setLow();
        bool isHigh() const;
        bool isLow() const;
};


