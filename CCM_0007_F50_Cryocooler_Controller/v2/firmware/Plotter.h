/*
This is a class of plotting routines for a tft screen.  There are a few ways
that the caller can interact with the class:

1) Explicitly plot data sent from the caller:

- initialize() creates the plot object
- setDomain() / setRange() configures the map between float inputs and screen coordinates
- showAxes() and labelAxes() can be used to draw crosshairs or label the plot frame
- plot() can be used to plot points, arrays of points, or caller-defined functions - see the function signatures
- parametricPlot() can be used to create a parametric plot using two caller-defined functions

2) Configure a 'scan' plotter with input channels, much like an oscilloscope - x axis is time in ms
Designed for high sampling speeds (relative to the plot time domain/window),
this mode keeps the uC rather busy, useful when you want to know the actual timing of signal changes.
Can have strange behavior if you sampling period is less than ~1% of the time domain window.
e.g. a 2500ms domain with a 10 Hz sampling rate - previous data won't clear correctly on time wrapping.
Typically have domain start at 0.

- initialize() creates the plot object
- setDomain() / setRange() creates the map between float inputs and screen coordinates
- showAxes() / labelAxes() configure optional crosshairs and plot frame labels
- setSampleRate() configures the number of samples per second (max 1000)
- addChannel() configures the plotting of a system int or float variable
- addDigitalChannel() configures the plotting of a digital input or output
- addAnalogChannel() configures the plotting of an analog input
- showLegend() lists the channel names above the top left corner of the plot
- beginScan() starts the scan
- isRunning() can be used to determine if the scan is active
- end() stops the scan

3) Configure a 'track' plotter with input channels - x axis is sample number rather than time
Designed for low sampling speeds, this mode uses few resources and is useful when you don't
care about the exact timing of the x-axis. Typically have domain start at 0.

- initialize() creates the plot object
- setDomain() / setRange() creates the map between float inputs and screen coordinates
- showAxes() / labelAxes() configure optional crosshairs and plot frame labels
- setSampleRate() configures the number of samples per second (max 1000)
- addChannel() configures the tracking/plotting of a system int or float variable
- addDigitalChannel() configures the tracking/plotting of a digital input or output
- addAnalogChannel() configures the tracking/plotting of an analog input
- showLegend() lists the channel names above the top left corner of the plot
- beginTrack() starts the tracking/plotting
- isRunning() can be used to determine if the track is active
- end() stops the tracking/plotting

*/

#ifndef Plotter_H
#define Plotter_H

#include "application.h"
#include "ILI9341.h"
#include "PlotChannel.h"

#define PLOTTER_BACKGROUND BLACK
#define PLOTTER_BORDER GRAY
#define PLOTTER_MAX_CHANNELS 8


class Plotter {

public:
	enum Edge {rising, falling};
	enum Status {idle, active};				// not running, actively acquiring
	enum Style {none, scan, track};			// none, oscilloscope (x-axis is time in ms), track (x-axis is sample number)

	Plotter(ILI9341& aILI9341ref);

	bool setDomain(float xmin, float xmax);
	bool setRange(float yMin, float yMax);
	void showAxes(float x = 0, float y = 0);				// include coordinate axes, with defaults
	void setAxesLabels(String xLabel, String yLabel);

	void initialize(uint16_t xOrigin, uint16_t yOrigin, uint16_t aWidth, uint16_t aHeight);	// draw the plot object
	void clear();																			// clear existing plot window

// the caller can either interact with the plotter object directly:
	void plot(float x, float y, uint16_t aColor = WHITE);						// plot a point, default color parameter
	void plot(float xs[], float ys[], int nPoints, uint16_t aColor = WHITE);	// plot a set of points
	void plot(float (*aFunction)(float x), float xmin, float xmax, int nPoints = 100, uint16_t aColor = WHITE);	// plot a caller-provided function
	void parametricPlot(float (*xFunction)(float t), float (*yFunction)(float t), float tmin, float tmax, int nPoints = 100, uint16_t aColor = WHITE);

// or configure and use 'channels', like an oscilloscope (in this case the x axis is always time, in ms)
	bool addChannel(String aName, int *aSource, uint16_t aColor, float scaling = 1, float offset = 0);	// optional offset/scaling parameters
	bool addChannel(String aName, float *aSource, uint16_t aColor, float scaling = 1, float offset = 0);				// optional offset/scaling parameters
	bool addDigitalChannel(String aName, int *aDigitalSource, uint16_t aColor, float scaling = 1, float offset = 0);
	bool addAnalogChannel(String aName, int *aAnalogSource, uint16_t aColor, float scaling = 1, float offset = 0);
	void clearChannels();											// de-configure all channels

	bool setSampleRate(float aSampleRate);							// rate (Hz) at which samples are taken, max 1000
	void beginScan();												// begin capture + plotting
	void beginTrack();												// begin capture
	void end();														// stop capture
	bool isRunning();												// just checks if the sample timer is running

	void drawBorder();												// draw plot border
	void labelAxes(String xLabel, String yLabel);					// label the axes
	void showLegend();												// write color-coded channel names on screen

	float xMin=0,xMax=100,yMin=0,yMax=100;							// domain and range limits

private:
	Status status;
	Style style;
	ILI9341& tft;					// reference member

	uint16_t xo, yo, width, height;	// size and position of plot window - in pixels!
	uint16_t getScreenX(float x);	// map numeric value to screen plot object
	uint16_t getScreenY(float y);

 	PlotChannel channels[PLOTTER_MAX_CHANNELS];
	uint8_t nChannels;
	Timer sampleTimer;				// a timer for sampling
	void sample();					// sample all active channels and plot the result

	int startTime;					// when capture started, ms

	float axesX, axesY;				// coordinates for axes

	bool axes;						// whether or not to include axes

	int trackCounter;

};

#endif
