
#pragma once

#include <stdint.h>


class color_channel
{
public:
	color_channel(uint8_t* pin_array, uint8_t pin_number);
	~color_channel();
private:
	uint8_t* m_pin_array;
	uint8_t num_pins;
};

