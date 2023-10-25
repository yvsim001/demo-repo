#pragma once 

class Number {
    public:
        Number();
        void increaseNumber();
        uint16_t getNumber() const;
        void setNumber(uint16_t n);
        void resetNumber();
        void resetReady();
        bool isReady() const;
        void setReady();
        bool isNotReady() const;


    private:
        volatile uint16_t number_;
        bool ready_;
};