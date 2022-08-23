#include <Arduino.h>
#include <stdint.h>

#include "color_channel.h"


unsigned long myTime;

void setup()
{
	
	Serial.begin(115200);

	uint8_t my_array[] = {1,2,3,4,5,6};

	color_channel* blue;
	blue = new color_channel(my_array, sizeof(my_array)/sizeof(my_array[0]));
	delete blue;
}

void loop()
{
	Serial.print("Time: ");
	myTime = millis();

	Serial.println(myTime); // prints time since program started
	delay(1000);          // wait a second so as not to send massive amounts of data
}


