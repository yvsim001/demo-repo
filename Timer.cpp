/*
 * Timer.cpp
 *
 *  Created on: 25.10.2021
 *      Author: Maximilian Frank
 */

#include <avr/io.h>
#include "Timer.hpp"

#if (__AVR_ATmega2561__ || __AVR_ATmega1281__)
	Timer::Timer(uint8_t timernumber, uint16_t prescaler, uint16_t preload) : timernumber_(timernumber), preload_(preload) {
		switch(timernumber){
		case 0:
				TCCR0A = 0x00;

				switch(prescaler){
				case 0:
						TCCR0B |= (1 << CS00);
						TCCR0B &= ~(1 << CS01);
						TCCR0B &= ~(1 << CS02);
					break;
				case 8:
						TCCR0B &= ~(1 << CS00);
						TCCR0B |= (1 << CS01);
						TCCR0B &= ~(1 << CS02);
					break;
				case 64:
						TCCR0B |= (1 << CS00);
						TCCR0B |= (1 << CS01);
						TCCR0B &= ~(1 << CS02);
					break;
				case 256:
						TCCR0B &= ~(1 << CS00);
						TCCR0B &= ~(1 << CS01);
						TCCR0B |= (1 << CS02);
					break;
				case 1024:
						TCCR0B |= (1 << CS00);
						TCCR0B &= ~(1 << CS01);
						TCCR0B |= (1 << CS02);
					break;
				}
				TCNT0 = preload;
				TIMSK0 |= (1 << TOIE0); //enable counter
			break;
		case 1:
				TCCR1A = 0x00;

				switch(prescaler){
				case 0:
						TCCR1B |= (1 << CS10);
						TCCR1B &= ~(1 << CS11);
						TCCR1B &= ~(1 << CS12);
					break;
				case 8:
						TCCR1B &= ~(1 << CS10);
						TCCR1B |= (1 << CS11);
						TCCR1B &= ~(1 << CS12);
					break;
				case 64:
						TCCR1B |= (1 << CS10);
						TCCR1B |= (1 << CS11);
						TCCR1B &= ~(1 << CS12);
					break;
				case 256:
						TCCR1B &= ~(1 << CS10);
						TCCR1B &= ~(1 << CS11);
						TCCR1B |= (1 << CS12);
					break;
				case 1024:
						TCCR1B |= (1 << CS10);
						TCCR1B &= ~(1 << CS11);
						TCCR1B |= (1 << CS12);
					break;
				}
				TCNT1 = preload;
				TIMSK1 |= (1 << TOIE1); //enable counter

			break;
		case 2:
				TCCR2A = 0x00;

				switch(prescaler){
				case 0:
						TCCR2B |= (1 << CS20);
						TCCR2B &= ~(1 << CS21);
						TCCR2B &= ~(1 << CS22);
					break;
				case 8:
						TCCR2B &= ~(1 << CS20);
						TCCR2B |= (1 << CS21);
						TCCR2B &= ~(1 << CS22);
					break;
				case 64:
						TCCR2B |= (1 << CS20);
						TCCR2B |= (1 << CS21);
						TCCR2B &= ~(1 << CS22);
					break;
				case 256:
						TCCR2B &= ~(1 << CS20);
						TCCR2B &= ~(1 << CS21);
						TCCR2B |= (1 << CS22);
					break;
				case 1024:
						TCCR2B |= (1 << CS20);
						TCCR2B &= ~(1 << CS21);
						TCCR2B |= (1 << CS22);
					break;
				}
				TCNT2 = preload;
				TIMSK2 |= (1 << TOIE2); //enable counter

			break;
		case 3:
				TCCR3A = 0x00;

				switch(prescaler){
				case 0:
						TCCR3B |= (1 << CS30);
						TCCR3B &= ~(1 << CS31);
						TCCR3B &= ~(1 << CS32);
					break;
				case 8:
						TCCR3B &= ~(1 << CS30);
						TCCR3B |= (1 << CS31);
						TCCR3B &= ~(1 << CS32);
					break;
				case 64:
						TCCR3B |= (1 << CS30);
						TCCR3B |= (1 << CS31);
						TCCR3B &= ~(1 << CS32);
					break;
				case 256:
						TCCR3B &= ~(1 << CS30);
						TCCR3B &= ~(1 << CS31);
						TCCR3B |= (1 << CS32);
					break;
				case 1024:
						TCCR3B |= (1 << CS30);
						TCCR3B &= ~(1 << CS31);
						TCCR3B |= (1 << CS32);
					break;
				}
				TCNT3 = preload;
				TIMSK3 |= (1 << TOIE3); //enable counter
			break;
		case 4:
				TCCR0A = 0x00;

				switch(prescaler){
				case 0:
						TCCR4B |= (1 << CS40);
						TCCR4B &= ~(1 << CS41);
						TCCR4B &= ~(1 << CS42);
					break;
				case 8:
						TCCR4B &= ~(1 << CS40);
						TCCR4B |= (1 << CS41);
						TCCR4B &= ~(1 << CS42);
					break;
				case 64:
						TCCR4B |= (1 << CS40);
						TCCR4B |= (1 << CS41);
						TCCR4B &= ~(1 << CS42);
					break;
				case 256:
						TCCR4B &= ~(1 << CS40);
						TCCR4B &= ~(1 << CS41);
						TCCR4B |= (1 << CS42);
					break;
				case 1024:
						TCCR4B |= (1 << CS40);
						TCCR4B &= ~(1 << CS41);
						TCCR4B |= (1 << CS42);
					break;
				}
				TCNT4 = preload;
				TIMSK4 |= (1 << TOIE4); //enable counter
			break;
		case 5:
				TCCR0A = 0x00;

				switch(prescaler){
				case 0:
						TCCR5B |= (1 << CS50);
						TCCR5B &= ~(1 << CS51);
						TCCR5B &= ~(1 << CS52);
					break;
				case 8:
						TCCR5B &= ~(1 << CS50);
						TCCR5B |= (1 << CS51);
						TCCR5B &= ~(1 << CS52);
					break;
				case 64:
						TCCR5B |= (1 << CS50);
						TCCR5B |= (1 << CS51);
						TCCR5B &= ~(1 << CS52);
					break;
				case 256:
						TCCR5B &= ~(1 << CS50);
						TCCR5B &= ~(1 << CS51);
						TCCR5B |= (1 << CS52);
					break;
				case 1024:
						TCCR5B |= (1 << CS50);
						TCCR5B &= ~(1 << CS51);
						TCCR5B |= (1 << CS52);
					break;
				}
				TCNT5 = preload;
				TIMSK5 |= (1 << TOIE5); //enable counter 
			break;
		}
	}
	uint16_t Timer::getPreload() const{
		return preload_;
	}
	void Timer::resetPreload() const{
		switch(timernumber_){
		case 0:
				TCNT0 = preload_;
			break;
		case 1:
				TCNT1 = preload_;
			break;
		case 2:
				TCNT2 = preload_;
			break;
		case 3:
				TCNT3 = preload_;
			break;
		case 4:
				TCNT4 = preload_;
			break;
		case 5:
				TCNT5 = preload_;
			break;
		}
	}
	void Timer::activate() const{
		switch (timernumber_)
		{
		case 0:
				TIMSK0 |= (1 << TOIE0); 
			break;
		case 1:
				TIMSK1 |= (1 << TOIE1); 
			break;
		case 2:
				TIMSK2 |= (1 << TOIE2); 
			break;
		case 3:
				TIMSK3 |= (1 << TOIE3); 
			break;
		case 4:
				TIMSK4 |= (1 << TOIE4); 
			break;
		case 5:
				TIMSK5 |= (1 << TOIE5); 
			break;
		}	
	}
	void Timer::deactivate() const{
		switch (timernumber_)
		{
		case 0:
				TIMSK0 &= ~(1 << TOIE0); 
			break;
		case 1:
				TIMSK1 &= ~(1 << TOIE1); 
			break;
		case 2:
				TIMSK2 &= ~(1 << TOIE2); 
			break;
		case 3:
				TIMSK3 &= ~(1 << TOIE3); 
			break;
		case 4:
				TIMSK4 &= ~(1 << TOIE4); 
			break;
		case 5:
				TIMSK5 &= ~(1 << TOIE5); 
			break;
		}	
	}
#endif
#if (__AVR_ATmega328P__ || __AVR_ATmega328PB__)
	Timer::Timer(uint8_t timernumber, uint16_t prescaler, uint16_t preload) : timernumber(timernumber_), preload(preload_) {
		switch(timernumber){
		case 0:
				TCCR0A = 0x00;

				switch(prescaler){
				case 0:
						TCCR0B |= (1 << CS00);
						TCCR0B &= ~(1 << CS01);
						TCCR0B &= ~(1 << CS02);
					break;
				case 8:
						TCCR0B &= ~(1 << CS00);
						TCCR0B |= (1 << CS01);
						TCCR0B &= ~(1 << CS02);
					break;
				case 64:
						TCCR0B |= (1 << CS00);
						TCCR0B |= (1 << CS01);
						TCCR0B &= ~(1 << CS02);
					break;
				case 256:
						TCCR0B &= ~(1 << CS00);
						TCCR0B &= ~(1 << CS01);
						TCCR0B |= (1 << CS02);
					break;
				case 1024:
						TCCR0B |= (1 << CS00);
						TCCR0B &= ~(1 << CS01);
						TCCR0B |= (1 << CS02);
					break;
				}
				TCNT0 = preload;
				TIMSK0 |= (1 << TOIE0); //enable counter
			break;
		case 1:
				TCCR1A = 0x00;

				switch(prescaler){
				case 0:
						TCCR1B |= (1 << CS10);
						TCCR1B &= ~(1 << CS11);
						TCCR1B &= ~(1 << CS12);
					break;
				case 8:
						TCCR1B &= ~(1 << CS10);
						TCCR1B |= (1 << CS11);
						TCCR1B &= ~(1 << CS12);
					break;
				case 64:
						TCCR1B |= (1 << CS10);
						TCCR1B |= (1 << CS11);
						TCCR1B &= ~(1 << CS12);
					break;
				case 256:
						TCCR1B &= ~(1 << CS10);
						TCCR1B &= ~(1 << CS11);
						TCCR1B |= (1 << CS12);
					break;
				case 1024:
						TCCR1B |= (1 << CS10);
						TCCR1B &= ~(1 << CS11);
						TCCR1B |= (1 << CS12);
					break;
				}
				TCNT1 = preload;
				TIMSK1 |= (1 << TOIE1); //enable counter

			break;
		case 2:
				TCCR2A = 0x00;

				switch(prescaler){
				case 0:
						TCCR2B |= (1 << CS20);
						TCCR2B &= ~(1 << CS21);
						TCCR2B &= ~(1 << CS22);
					break;
				case 8:
						TCCR2B &= ~(1 << CS20);
						TCCR2B |= (1 << CS21);
						TCCR2B &= ~(1 << CS22);
					break;
				case 64:
						TCCR2B |= (1 << CS20);
						TCCR2B |= (1 << CS21);
						TCCR2B &= ~(1 << CS22);
					break;
				case 256:
						TCCR2B &= ~(1 << CS20);
						TCCR2B &= ~(1 << CS21);
						TCCR2B |= (1 << CS22);
					break;
				case 1024:
						TCCR2B |= (1 << CS20);
						TCCR2B &= ~(1 << CS21);
						TCCR2B |= (1 << CS22);
					break;
				}
				TCNT2 = preload;
				TIMSK2 |= (1 << TOIE2); //enable counter

			break;
		}
	}
	uint16_t Timer::getPreload() const{
		return preload_;
	}
	void Timer::resetPreload() const{
		switch(timernumber_){
		case 0:
				TCNT0 = preload_;
			break;
		case 1:
				TCNT1 = preload_;
			break;
		case 2:
				TCNT2 = preload_;
			break;
		}
	}
#endif

