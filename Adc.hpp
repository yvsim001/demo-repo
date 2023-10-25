#ifndef ADC_HPP_
#define ADC_HPP_

class Adc {
    public:
        enum REFERENCE {
            AREF,
            AVCC,
            INTERNAL1,
            INTERNAL2
        };

        Adc(uint8_t p, uint8_t r);

        double read0() const;
        double read1() const;
        double read2() const;
        double read3() const;
        double read4() const;
        double read5() const;
        double read6() const;
        double read7() const;
        
    private:
        uint8_t prescaler;
        uint8_t reference;

        void setPrescaler(uint8_t p) const;
        void setReference(uint8_t r) const;
        double read_() const;
};
#endif