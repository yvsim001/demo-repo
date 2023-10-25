#include <avr/io.h>

#include "InputPort.hpp"
#include "Phase.hpp"

Phase::Phase(volatile uint8_t* p, volatile uint8_t* pd, volatile uint8_t* pi, uint8_t b) : InputPort(p,pd,pi,b) {
    InputPort::setPullup();
    detected_ = false;
}

bool Phase::isActive() const{
    return InputPort::isLow();
}

bool Phase::isNotActive() const{
    return InputPort::isHigh();
}

void Phase::setDetected(){
    detected_ = true;
}

void Phase::resetDetected(){
    detected_ = false;
}

bool Phase::getDetected() const{
    return detected_;
}

bool Phase::getNotDetected() const{
    return !detected_;
}