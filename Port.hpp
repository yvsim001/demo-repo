#pragma once

class Port {
    public:
        typedef uint8_t port_type;
        typedef uint8_t bval_type;

        Port(volatile port_type* p, volatile port_type* pd, volatile port_type* pi, bval_type bval);

    protected:
        volatile port_type* port;
        volatile port_type* pdir;
        volatile port_type* pin;
        bval_type bval;
};