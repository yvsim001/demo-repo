#include <avr/io.h>
#include "OutputPort.hpp"

OutputPort::OutputPort(volatile uint8_t* p, volatile uint8_t* pd, volatile uint8_t* pi, uint8_t b) : Port(p,pd,pi,b){
    *reinterpret_cast<volatile uint8_t*> (pdir) |= (1<<bval);
}
void OutputPort::toggle(){
    *reinterpret_cast<volatile uint8_t*> (port) ^= (1<<bval);
}
void OutputPort::setHigh(){
    *reinterpret_cast<volatile uint8_t*> (port) |= (1<<bval);
}
void OutputPort::setLow(){
    *reinterpret_cast<volatile uint8_t*> (port) &= ~(1<<bval);
}
bool OutputPort::isHigh() const{
    return (bool)(*reinterpret_cast<volatile uint8_t*> (pin) & (1<<bval));
}
bool OutputPort::isLow() const{
	return (bool)(!(*reinterpret_cast<volatile uint8_t*> (pin) & (1 << bval)));
}