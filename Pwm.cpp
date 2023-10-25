#include <avr/io.h>
#include <math.h>

#include "Adc.hpp"
#include "Pwm.hpp"

Pwm::Pwm(Adc &p, Adc &n) : AdcPos(p), AdcNeg(n){
    dutyOff_ = 0;
    dutyOn_ = 0;
}
        
void Pwm::setDutyOn(uint16_t n){
    dutyOn_ = n;
}

void Pwm::setDutyOff(uint16_t n){
    dutyOff_ = n;
}

uint16_t Pwm::getDutyCycle() const{
    if(!invalid_){
        double duty;

        duty = dutyOn_ + dutyOff_;
        duty = dutyOff_ / duty;
        duty *= 100;
        duty = round(duty);

        return (uint16_t)duty;
    }
    else{return 0;}
}

uint16_t Pwm::getFrequency() const{
    if(!invalid_){
        double period;

        period = dutyOn_ + dutyOff_;
        period = period / 2000000;
        period = 1/period;
        period = round(period);

        return (uint16_t) period;
    }
    else{return 0;}
}
        
uint8_t Pwm::getCurrent() const{
    uint16_t duty = getDutyCycle();
    uint8_t current = 255;

    if(duty < 8 || duty > 96){current = 0;}
    else if (duty >= 8 && duty < 10){current = 6;}
    else if (duty >= 10 && duty < 85){current = round(duty * 0.6);}
    else if (duty <= 96) {current = round((duty - 64) * 2.5);}

    return current;
}

void Pwm::setInvalid() {
    invalid_ = true;
}

void Pwm::resetInvalid() {
    invalid_ = false;
}

double Pwm::getPosVoltage() const{
    return (double)(AdcPos.read1() / 68.25);
}

double Pwm::getNegVoltage() const{
    return (double)(AdcNeg.read0() / 68.25);
}