#pragma once

#include "Adc.hpp"

class Pwm {
    public:
        Pwm(Adc &p, Adc &n);

        void setDutyOn(uint16_t n);
        void setDutyOff(uint16_t n);
        void setInvalid();
        void resetInvalid();
        
        uint16_t getDutyCycle() const;
        uint16_t getFrequency() const;
        uint8_t getCurrent() const;
        double getPosVoltage() const;
        double getNegVoltage() const;
    private:
        Adc &AdcPos;
        Adc &AdcNeg;
        
        volatile uint16_t dutyOn_;
        volatile uint16_t dutyOff_;
        volatile bool invalid_;
};