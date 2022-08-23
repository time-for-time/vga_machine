#include <Arduino.h>
#include <stdint.h>

#include "color_channel.h"


unsigned long my_time;
r2r_color_channel* color_red;
r2r_color_channel* color_green;
r2r_color_channel* color_blue;

void setup()
{
	
	Serial.begin(115200);

	uint8_t my_array[] = {20, 18, 17, 16, 15, 14, 13, 12};
	color_red = new r2r_color_channel(my_array, sizeof(my_array)/sizeof(my_array[0]));
	color_green = new r2r_color_channel(my_array, sizeof(my_array)/sizeof(my_array[0]));
	color_blue = new r2r_color_channel(my_array, sizeof(my_array)/sizeof(my_array[0]));
}

void loop()
{


	my_time = micros();
	color_red->set_relative_color(0.99999f);
	color_green->set_relative_color(0.99999f);
	color_blue->set_relative_color(0.99999f);
	my_time = micros() - my_time;
	Serial.print("calc time:");
	Serial.println(my_time);
	Serial.print(" microsec\n");

	delay(1000);

	my_time = micros();
	color_red->set_relative_color(0.00001f);
	color_green->set_relative_color(0.00001f);
	color_blue->set_relative_color(0.00001f);
	my_time = micros() - my_time;
	Serial.print("calc time:");
	Serial.println(my_time);
	Serial.print(" microsec\n");

	delay(1000);
}


