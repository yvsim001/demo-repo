#include <avr/io.h>
#include "InputPort.hpp"

InputPort::InputPort(volatile uint8_t* p, volatile uint8_t* pd, volatile uint8_t* pi, uint8_t b) : Port(p,pd,pi,b) {
	*reinterpret_cast<volatile uint8_t*> (pdir) &= ~(1 << bval); //set input
}
void InputPort::setPullup() {
	*reinterpret_cast<volatile uint8_t*> (port) |= (1 << bval);
}
void InputPort::clearPullup(){
	*reinterpret_cast<volatile uint8_t*> (port) &= ~(1 << bval);
}
bool InputPort::isHigh() const{
	return (bool)(*reinterpret_cast<volatile uint8_t*> (pin) & (1 << bval));
}
bool InputPort::isLow() const{
	return (bool)(!(*reinterpret_cast<volatile uint8_t*> (pin) & (1 << bval)));
}