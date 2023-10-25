/*
 * Timer.hpp
 *
 *  Created on: 25.10.2021
 *      Author: Maximilian Frank
 */

#pragma once

class Timer {
	public:
		Timer(uint8_t timernumber, uint16_t prescaler, uint16_t preload);
		uint16_t getPreload() const;
		void resetPreload() const;
		void activate() const;
		void deactivate() const;
	private:
		uint8_t timernumber_;
		uint16_t preload_;
};
