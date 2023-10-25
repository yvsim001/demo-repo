#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Adc.hpp"

#if (__AVR_ATmega2561__ || __AVR_ATmega1281__)
    Adc::Adc(uint8_t p, uint8_t r) : prescaler(p), reference(r){
        ADCSRA |= (1<<ADEN);
    }
    void Adc::setPrescaler(uint8_t p) const{
        switch (p)
        {
        case 2:
                ADCSRA &= ~(1<<ADPS2);
                ADCSRA &= ~(1<<ADPS1);
                ADCSRA |= (1<<ADPS0);
            break;
        case 4:
                ADCSRA &= ~(1<<ADPS2);
                ADCSRA |= (1<<ADPS1);
                ADCSRA &= ~(1<<ADPS0);
            break;
        case 8:
                ADCSRA &= ~(1<<ADPS2);
                ADCSRA |= (1<<ADPS1);
                ADCSRA |= (1<<ADPS0);
            break;
        case 16:
                ADCSRA |= (1<<ADPS2);
                ADCSRA &= ~(1<<ADPS1);
                ADCSRA &= ~(1<<ADPS0);
            break;
        case 32:
                ADCSRA |= (1<<ADPS2);
                ADCSRA &= ~(1<<ADPS1);
                ADCSRA |= (1<<ADPS0);
            break;
        case 64:
                ADCSRA |= (1<<ADPS2);
                ADCSRA |= (1<<ADPS1);
                ADCSRA &= ~(1<<ADPS0);
            break;
        case 128:
                ADCSRA |= (1<<ADPS2);
                ADCSRA |= (1<<ADPS1);
                ADCSRA |= (1<<ADPS0);
            break;
        default:
                ADCSRA &= ~(1<<ADPS2);
                ADCSRA &= ~(1<<ADPS1);
                ADCSRA &= ~(1<<ADPS0);
            break;
        }
    }
    void Adc::setReference(uint8_t r) const{
        switch (r)
        {
        case Adc::REFERENCE::AREF:
                ADMUX &= ~(1<<REFS1);
                ADMUX &= ~(1<<REFS0);
            break;
        
        case Adc::REFERENCE::AVCC:
                ADMUX &= ~(1<<REFS1);
                ADMUX |= (1<<REFS0);
            break;
        case Adc::REFERENCE::INTERNAL1:
                ADMUX |= (1<<REFS1);
                ADMUX &= ~(1<<REFS0);
            break;
        case Adc::REFERENCE::INTERNAL2:
                ADMUX |= (1<<REFS1);
                ADMUX |= (1<<REFS0);
            break;
        default:
                ADMUX &= ~(1<<REFS1);
                ADMUX |= (1<<REFS0);
            break;
        }
    }
    double Adc::read_() const{
        double adc_value;

        ADCSRA |= (1<<ADSC);

        while(ADCSRA & (1<<ADSC));

        adc_value = ADC;
        adc_value = 0;

        for(uint8_t i = 0; i < 150; i++){
            ADCSRA |= ADSC;
            while(ADCSRA & (1<<ADSC));

            adc_value += ADC;
        }
        adc_value = (adc_value / 150);

        return adc_value;
    }
    double Adc::read0() const{
        setPrescaler(prescaler);
        setReference(reference);
        ADMUX &= ~(1<<MUX0); 
        ADMUX &= ~(1<<MUX1); 
        ADMUX &= ~(1<<MUX2); 
        
        return read_();
    }
    double Adc::read1() const{
        setPrescaler(prescaler);
        setReference(reference);
        ADMUX |= (1<<MUX0); 
        ADMUX &= ~(1<<MUX1); 
        ADMUX &= ~(1<<MUX2); 

        return read_();
    }
    double Adc::read2() const{
        setPrescaler(prescaler);
        setReference(reference);
        ADMUX &= ~(1<<MUX0); 
        ADMUX |= (1<<MUX1); 
        ADMUX &= ~(1<<MUX2); 

        return read_();
    }
    double Adc::read3() const{
        setPrescaler(prescaler);
        setReference(reference);
        ADMUX |= (1<<MUX0); 
        ADMUX |= (1<<MUX1); 
        ADMUX &= ~(1<<MUX2); 

        return read_();
    }
    double Adc::read4() const{
        setPrescaler(prescaler);
        setReference(reference);
        ADMUX &= ~(1<<MUX0); 
        ADMUX &= ~(1<<MUX1); 
        ADMUX |= (1<<MUX2); 

        return read_();
    }
    double Adc::read5() const{
        setPrescaler(prescaler);
        setReference(reference);
        ADMUX |= (1<<MUX0); 
        ADMUX &= ~(1<<MUX1); 
        ADMUX |= (1<<MUX2); 

        return read_();
    }
    double Adc::read6() const{
        setPrescaler(prescaler);
        setReference(reference);
        ADMUX &= ~(1<<MUX0); 
        ADMUX |= (1<<MUX1); 
        ADMUX |= (1<<MUX2); 

        return read_();
    }
    double Adc::read7() const{
        setPrescaler(prescaler);
        setReference(reference);
        ADMUX |= (1<<MUX0); 
        ADMUX |= (1<<MUX1); 
        ADMUX |= (1<<MUX2); 

        return read_();
    }
#endif