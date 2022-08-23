
#include <stdexcept>

#include "color_channel.h"



color_channel::color_channel(uint8_t* pin_array, uint8_t number_of_pins)
{
	if ( (number_of_pins>16) || (number_of_pins<4) )
	{
		throw std::invalid_argument("received wrong number of pins!");
	}
	
	this->m_pin_array = pin_array;
}

color_channel::~color_channel()
{
}




