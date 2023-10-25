#include <avr/io.h>
#include <stdbool.h>

#include "Button.hpp"

Button::Button(volatile uint8_t* p, volatile uint8_t* pd, volatile uint8_t* pi, uint8_t b, bool ip) : InputPort(p,pd,pi,b), lowIsPressed_(ip){
    if(lowIsPressed_){InputPort::setPullup();}
    else{InputPort::clearPullup();}
    recentlyPressed_ = false;
}

bool Button::isPressed() const{
    bool s;

    if(lowIsPressed_){s = InputPort::isLow();}
    else {s = InputPort::isHigh();}

    return s;
}

bool Button::isNotPressed() const{
    bool s;
    
    if(lowIsPressed_){s = InputPort::isHigh();}
    else {s = InputPort::isLow();}

    return s;
}

bool Button::isActivated(){
    if(activated_){
        activated_ = false;
        recentlyPressed_ = true;
        return true;
    }
    resetRecentlyPressed();
    return false;
}
bool Button::isNotActivated() {
    if(!activated_){
        return true;
    }
    activated_ = false;
    return false;
}

bool Button::getRecentlyPressed() const{
    return recentlyPressed_;
}

bool Button::getNotRecentlyPressed() const{
    return !recentlyPressed_;
}

void Button::resetRecentlyPressed(){
    recentlyPressed_ = false;
}

void Button::activate(){
    activated_ = true;
}
void Button::deactivate(){
    activated_ = false;
}