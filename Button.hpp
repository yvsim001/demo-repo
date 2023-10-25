#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "InputPort.hpp"

class Button : InputPort 
{
    public:
        Button(volatile uint8_t* p, volatile uint8_t* pd, volatile uint8_t* pi, uint8_t b, bool ip);

        bool isPressed() const;
        bool isNotPressed() const;
        bool isActivated();
        bool isNotActivated();
        bool getRecentlyPressed() const;
        bool getNotRecentlyPressed() const;
        void resetRecentlyPressed();
        void activate();
        void deactivate();

    private:
        bool lowIsPressed_;
        bool recentlyPressed_;
        volatile bool activated_;
};

#endif