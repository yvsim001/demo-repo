#include <avr/io.h>

#include "Number.hpp"

Number::Number() {
    number_ = 0;
    ready_ = false;
}

void Number::increaseNumber() {
    number_++;
}

uint16_t Number::getNumber() const{
    return number_;
}

void Number::setNumber(uint16_t n){
    number_ = n;
}

void Number::resetNumber(){
    number_ = 0;
}

bool Number:: isReady() const{
    return ready_;
}

void Number::resetReady(){
    ready_ = false;
}

void Number::setReady(){
    ready_ = true;
}

bool Number::isNotReady() const{
    return !ready_;
}