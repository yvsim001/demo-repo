#pragma once

#include <avr/io.h>

#include "Language.hpp"
#include "Timer.hpp"
#include "OutputPort.hpp"
#include "InputPort.hpp"
#include "Button.hpp"
#include "Phase.hpp"
#include "RotatingField.hpp"
#include "Number.hpp"
#include "Adc.hpp"
#include "StandardTest.hpp"
#include "I2c.hpp"
#include "SSD1309.hpp"

namespace OBJECTS
{
	Language SysLanguage;

	namespace TIMER
	{
		Timer Hz0
		{
			0,
			64,
			6
		};
	}
	
	namespace PORTS
	{
		OutputPort Selfretention
		{
			&PORTF,
			&DDRF,
			&PINF,
			PF6     //SELBSHALTUNG
		};
		OutputPort DisplayReset 
		{
			&PORTD,
			&DDRD,
			&PIND,
			PD4
		};
	}
	I2c Com
	{
		PD1,
		PD2,
		&PORTD,
		200000
	};
	SSD1309 Display 
	{
			Com,
			PORTS::DisplayReset,
			&PORTC,
			0x78, 
			30  
	};

	namespace BUTTONS
	{
		Button Links 
		{
			&PORTF,
			&DDRF,
			&PINF,
			PF5,      //TASTENFEEDBACK_MCU
			false,    //pull down
		};
		Button Oben 
		{
			&PORTD,
			&DDRD,
			&PIND,
			PD7,
			true,
		};
		Button Mitte 
		{
			&PORTD,
			&DDRD,
			&PIND,
			PD5,
			true
		};
		Button Unten 
		{
			&PORTD,
			&DDRD,
			&PIND,
			PD6,
			true	//pullup
		};
		Button Rechts 
		{
			&PORTC,
			&DDRC,
			&PINC,
			PC0,
			true
		};
	}
}