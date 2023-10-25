#include <avr/io.h>
#include "Port.hpp"

Port::Port(volatile port_type* p, volatile port_type* pd, volatile port_type* pi, bval_type b) : port(p), pdir(pd), pin(pi), bval(b){}