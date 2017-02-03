/*
This class describes something similar to an oscilloscope channel, which has a
source for sampling (reading voltages), a color for plotting, and an optional
offset and scaling to put it into the plot window of interest.

This class doesn't know anything about plotting, it just does the sampling.
*/

#ifndef PlotChannel_H
#define PlotChannel_H

#include "application.h"
#include "ILI9341.h"


class PlotChannel {

public:
	enum channelType {none, integer, floating, digital, analog};

	PlotChannel();

	bool configureForValue(String aName, int *aSource, uint16_t aColor, float aScaling = 1, float aOffset = 0);
	bool configureForValue(String aName, float *aSource, uint16_t aColor, float aScaling = 1, float aOffset = 0);
	bool configureForDigital(String aName, int *aSource, uint16_t aColor, float aScaling = 1, float aOffset = 0);
	bool configureForAnalog(String aName, int *aSource, uint16_t aColor, float aScaling = 1, float aOffset = 0);

	void release();				// deconfigure the channel

	uint16_t getColor();		// get channel color
	float sample();				// take a sample
	String getName();			// return the channel name (for plot labeling)


private:
	String name;				// channel name,
	uint16_t color;				// RGB565 color code for this channel
	float offset,scaling;		// offset and scaling to be applied before returning sample value
	channelType type;
	int* intSource;				// pointers to possible source types
	float* floatSource;
	int* digitalSource;
	int* analogSource;
};

#endif
