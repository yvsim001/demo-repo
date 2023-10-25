#pragma once

#include "Port.hpp"

class InputPort : Port
{
	public:
		//constructor
		InputPort(volatile uint8_t* p, volatile uint8_t* pd, volatile uint8_t* pi, uint8_t b);
		void setPullup();
		void clearPullup();
		bool isHigh() const;
		bool isLow() const;
};
