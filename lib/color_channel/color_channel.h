
#pragma once

#include <stdint.h>


/**
 * @brief color channel for r2r circuit.
 * 
 */
class r2r_color_channel
{
public:
	/**
	 * @brief Constructor
	 * 
	 * @param pin_array most significant pin first.
	 * @param pin_number number of pins.
	 * @warning the array for the r2r setup has the most significant pin connection in first position.
	 */
	r2r_color_channel(uint8_t* pin_array, uint8_t pin_number);
	~r2r_color_channel();
	void set_relative_color(float color_intensity_percent);
private:
	uint8_t* m_pin_array;
	uint8_t m_num_pins;
};

