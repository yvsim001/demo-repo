#pragma once

class Phase : InputPort {
    public:
        Phase(volatile uint8_t* p, volatile uint8_t* pd, volatile uint8_t* pi, uint8_t b);
        bool isActive() const;
        bool isNotActive() const;
        bool getDetected() const;
        bool getNotDetected() const;
        void setDetected();
        void resetDetected();

    private:
        bool detected_;
};