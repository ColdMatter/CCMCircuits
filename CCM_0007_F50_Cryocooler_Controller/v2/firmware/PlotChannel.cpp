/*

*/

#include "PlotChannel.h"
#include "Utils.h"
#include "Streaming.h"

PlotChannel::PlotChannel() {	// constructor
	name = "?";
	type = none;
}

// configure a channel for monitoring an integer variable
bool PlotChannel::configureForValue(String aName, int *aSource, uint16_t aColor, float aScaling, float aOffset) {
	type = integer;
	name = aName;
	intSource = aSource;
	color = aColor;
	offset = aOffset;
	scaling = aScaling;

	return true;
}

// configure a channel for monitoring a float variable
bool PlotChannel::configureForValue(String aName, float *aSource, uint16_t aColor, float aScaling, float aOffset) {
	type = floating;
	name = aName;
	floatSource = aSource;
	color = aColor;
	offset = aOffset;
	scaling = aScaling;

	return true;
}

// configure a channel for monitoring a digital input
bool PlotChannel::configureForDigital(String aName, int *aSource, uint16_t aColor, float aScaling, float aOffset) {
	type = digital;
	name = aName;
	digitalSource = aSource;
	color = aColor;
	offset = aOffset;
	scaling = aScaling;
//	pinMode(*aSource, INPUT);		// ensure pin is configured as an input
	return true;
}

// configure a channel for monitoring an analog input
// do not configure the pin, that happens when you call 'analogRead()'
bool PlotChannel::configureForAnalog(String aName, int *aSource, uint16_t aColor, float aScaling, float aOffset) {
	int analogChannels[8] = {A0, A1, A2, A3, A4, A5, A6, A7};
	bool channelOK = false;
	for (int i=0; i<8; i++) {		// test if the specified channel is an analog one
		if (*aSource == analogChannels[i]) { channelOK = true; }
	}
	if (!channelOK) {return false;}
	type = analog;
	name = aName;
	analogSource = aSource;
	color = aColor;
	offset = aOffset;
	scaling = aScaling;
	return true;
}

// release a channel, deleting it's configuration data
void PlotChannel::release() {
	type = none;
	color = none;
	offset = 0;
	scaling = 1;
	name = "?";
}

String PlotChannel::getName() {
	return name;
}

// sample the channel, returns 0 if channel is not configured
float PlotChannel::sample() {
	float rawValue = 0;
	switch (type) {
		case integer:
			rawValue = (float)(*intSource);					// get the value pointed by source pointer
			break;
		case floating:
			rawValue = (float)(*floatSource);
			break;
		case digital:
			rawValue = (float)digitalRead(*digitalSource);	// read in a digital value as HIGH (1) or LOW (0)
			rawValue = rawValue*3.3;						// convert to volts
			break;
		case analog:
			rawValue = (float)analogRead(*analogSource);	// 0..4095 for 0-3.3V
			rawValue = mapper(rawValue, 0, 4095, 0, 3.3);	// convert to volts
			break;
	}
	float returnValue = (scaling * rawValue) + offset;
	return returnValue;
}

uint16_t PlotChannel::getColor() {
	return color;
}
