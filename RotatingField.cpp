#include <avr/io.h>

#include "RotatingField.hpp"

RotatingField::RotatingField(){
    rotation_ = 0;
}

void RotatingField::setRightRotation(){
    rotation_ = 2;
}

void RotatingField::setLeftRotation(){
    rotation_ = 1;
}

void RotatingField::resetRotation(){
    rotation_ = 0;
}

uint8_t RotatingField::getRotation() const{
    return rotation_;
}