#include <Arduino.h>
#include <cmath>
#include <stdexcept>

#include "color_channel.h"



r2r_color_channel::r2r_color_channel(uint8_t* pin_array, uint8_t number_of_pins)
{
	if ( (number_of_pins>16) || (number_of_pins<4) )
	{
		throw std::invalid_argument("received wrong number of pins!");
	}
	
	this->m_pin_array = pin_array;
	this->m_num_pins = number_of_pins;
}

r2r_color_channel::~r2r_color_channel()
{
	;
}

void r2r_color_channel::set_relative_color(float color_intensity_percent)
{
	uint16_t counter;

	/* check input value */
	if ( (1 < color_intensity_percent) || (0 > color_intensity_percent) )
	{
		/* wrong parameter! */
		return;
	}
	
	/* split output until divided into digital values */
	for (counter = 0; counter < m_num_pins; counter++)
	{
		if (color_intensity_percent > (1.0f/(float)(1<<(counter+1))))
		{
			digitalWrite(m_pin_array[counter], HIGH);
			color_intensity_percent = color_intensity_percent - (1.0f/(float)(1<<(counter+1)));
		}
		else
		{
			digitalWrite(m_pin_array[counter], LOW);
		}
	}
}



