/*

*/

#include "Plotter.h"
#include "Utils.h"
#include "Streaming.h"

Plotter::Plotter(ILI9341& aILI9341ref)
:
tft(aILI9341ref),
sampleTimer(1000, &Plotter::sample, *this)
{
}

void Plotter::initialize(uint16_t xOrigin, uint16_t yOrigin, uint16_t aWidth, uint16_t aHeight) {
	xo = xOrigin;
	yo = yOrigin;
	width = aWidth;
	height = aHeight;

	clear();
	drawBorder();
	status = idle;
	nChannels = 0;
	axes = false;
	axesX = 0;
	axesY = 0;
	style = none;
}

void Plotter::showAxes(float x, float y) {
	axes = true;
	axesX = x;
	axesY = y;
	tft.drawFastHLine(xo, getScreenY(y), width, PLOTTER_BORDER);	// x-axis
	tft.drawFastVLine(getScreenX(x), yo, height, PLOTTER_BORDER);	// y-axis
}

bool Plotter::isRunning() {
	return sampleTimer.isActive();
}

// channel that monitors an int variable
bool Plotter::addChannel(String aName, int *aSource, uint16_t aColor, float scaling, float offset) {
	if (nChannels == PLOTTER_MAX_CHANNELS) {return false;}	// no more channels allowed!
	nChannels++;
	return channels[nChannels-1].configureForValue(aName, aSource, aColor, scaling, offset);
}

// channel that monitors a float variable
bool Plotter::addChannel(String aName, float *aSource, uint16_t aColor, float scaling, float offset) {
	if (nChannels == PLOTTER_MAX_CHANNELS) {return false;}	// no more channels allowed!
	nChannels++;
	return channels[nChannels-1].configureForValue(aName, aSource, aColor, scaling, offset);
}

bool Plotter::addDigitalChannel(String aName, int *aSource, uint16_t aColor, float scaling, float offset) {
	if (nChannels == PLOTTER_MAX_CHANNELS) {return false;}	// no more channels allowed!
	nChannels++;
	return channels[nChannels-1].configureForDigital(aName, aSource, aColor, scaling, offset);
}

bool Plotter::addAnalogChannel(String aName, int *aSource, uint16_t aColor, float scaling, float offset) {
	if (nChannels == PLOTTER_MAX_CHANNELS) {return false;}	// no more channels allowed!

	bool attempt = channels[nChannels-1].configureForAnalog(aName, aSource, aColor, scaling, offset);
	if (!attempt) {return false;}
	else{ nChannels++; return true;}
}

void Plotter::clearChannels() {
	for (int i=0; i<nChannels; i++) {
		channels[i].release();
	}
	nChannels = 0;
}

// sample configured channels and plot them
// this function is called from the sampling timer - there should be no y-axis showing
void Plotter::sample() {
	float xValue;									// x coordinate, value
	uint16_t xVal;									// x coordinate, screen pixels
	uint8_t eraseWidth;
	uint16_t xAxisPosition, yAxisPosition;

	switch (style) {
		case scan:
			xValue = millis() - startTime + xMin;		// ms elapsed since capture began
			if (xValue >= xMax) {					// if the time-axis has filled up
				startTime = millis();				// and reset the x-axis timer
				xValue = xMin;						// should wrap
			}
			xVal = getScreenX(xValue);
			eraseWidth = min(5,xo+width-xVal-1);						// clearing out previous data just ahead
			xAxisPosition = getScreenY(axesY);							// height of x-axis
			yAxisPosition = getScreenX(axesX);							// position of y-axis
			tft.fillRect(xVal+1, yo, eraseWidth, height, PLOTTER_BACKGROUND);
			if (axes) {
				tft.drawFastHLine(xVal+1, xAxisPosition, eraseWidth, PLOTTER_BORDER);			// replace possibly-erased x-axis segment
				if (yAxisPosition >= xVal && yAxisPosition < xVal + eraseWidth ) {tft.drawFastVLine(yAxisPosition, yo, height, PLOTTER_BORDER);}		// replace erased y-axis
			}
			break;
		case track:
			trackCounter++;
			if (trackCounter >= xo + width) {
				trackCounter = xo;
				clear();							// OK to take the time to clear the screen
				if (axes) { showAxes(); }			// tracking is not meant to be fast anyway
			}
			xVal = trackCounter;
			break;
		default:
			xVal = xo;
	}

	for (int i=0; i<nChannels; i++) {
		float yValue = channels[i].sample();
		tft.drawPixel(xVal, getScreenY(yValue), channels[i].getColor());
	}

	sampleTimer.reset();					// reset the timer for the next sample
}

// start the scan
void Plotter::beginScan() {
	startTime = millis();
//	if (axes) { showAxes(axesX, axesY); }
	status = active;
	style = scan;
	sampleTimer.start();
}

// start the sample timer and plotting
void Plotter::beginTrack() {
	startTime = millis();
//	if (axes) { showAxes(axesX, axesY); }
	status = active;
	style = track;
	trackCounter = xo;
	sampleTimer.start();
}

// end acquisition, stop sampling timer
void Plotter::end() {
	sampleTimer.stop();					// stop the sampling timer
	status = idle;
	sampleTimer.reset();
}

bool Plotter::setDomain(float aXmin, float aXmax) {
	if (aXmin >= aXmax) {return false;}
	xMin = aXmin;
	xMax = aXmax;
	return true;
}

bool Plotter::setRange(float aYmin, float aYmax) {
	if (aYmin >= aYmax) {return false;}
	yMin = aYmin;
	yMax = aYmax;
	return true;
}

// draw the plot border
void Plotter::drawBorder() {
	tft.drawRect(xo-1, yo-1, width+2, height+2, PLOTTER_BORDER);
}

void Plotter::showLegend() {
	tft.setTextSize(1);
	tft.setCursor(xo, yo - 10);				// upper left corner
	for (int i=0; i<nChannels; i++) {
		tft.setTextColor(channels[i].getColor());
		tft.print(channels[i].getName());
		if (i<nChannels-1) {tft.print(",");}
	}
	tft.setTextSize(2);
}

void Plotter::labelAxes(String xLabel, String yLabel) {
	tft.setTextSize(1);
	uint8_t charWidth = 6;
	uint8_t charHeight = 8;
	uint16_t labelWidth = (charWidth+1)*xLabel.length();	// length of two labels
	uint16_t labelHeight = (charWidth+1)*yLabel.length();
//	if (labelWidth > width || labelHeight > height) {return;}
// print x-axis label
	tft.setCursor(xo + (width - labelWidth)/2, yo + height + 1);
	tft.print(xLabel);
// print y-axis label
	tft.setRotation(0);		// rotate for printing
	tft.setCursor(tft.width() - yo - height + (height - labelHeight)/2, xo - charHeight - 1);
	tft.print(yLabel);
	tft.setRotation(1);		// restore rotation
	tft.setTextSize(2);
}

// clear the active part of the plotting region
void Plotter::clear() {
	tft.fillRect(xo, yo, width, height, PLOTTER_BACKGROUND);
}

// change the sample rate, specified in Hz, max 1000
bool Plotter::setSampleRate(float aSampleRate) {
	if (aSampleRate <= 0 || aSampleRate > 1000) {return false;}	// abort if out of allowed range
	uint sampleDelay = uint(1000/aSampleRate);
	sampleTimer.changePeriod(sampleDelay);	// delay between samples (ms)
	return false;
}

// plot a set of points from a caller-defined array to the screen
void Plotter::plot(float xs[], float ys[], int nPoints, uint16_t aColor) {
	for (int i=0; i<nPoints; i++) {
		plot(xs[i], ys[i], aColor);
	}
}

// plot a set of points from a caller-defined function, nPoints from xmin to xmax
// the function pointed to must take a single float parameter and return a float
void Plotter::plot(float (*aFunction)(float x), float xmin, float xmax, int nPoints, uint16_t aColor) {
	for (int i=0; i<nPoints; i++) {
		float xValue = xmin + i*(xmax - xmin)/nPoints;
		float yValue = (*aFunction)(xValue);
		plot(xValue, yValue, aColor);
	}
}

// parametric plot of points using two caller-defined functions
void Plotter::parametricPlot(float (*xFunction)(float t), float (*yFunction)(float t), float tmin, float tmax, int nPoints, uint16_t aColor) {
	for (int i=0; i<nPoints; i++) {
		float tValue = tmin + i*(tmax - tmin)/nPoints;
		float xValue = (*xFunction)(tValue);
		float yValue = (*yFunction)(tValue);
		plot(xValue, yValue, aColor);
	}
}

// plot a point to the screen, color uses default value if not specified
void Plotter::plot(float x, float y, uint16_t aColor) {
	tft.drawPixel(getScreenX(x), getScreenY(y), aColor);
}

// map a x-value float to the plot object
uint16_t Plotter::getScreenX(float x) {
	if (x < xMin) { return xo; }
	if (x > xMax) { return xo + width; }
	return (uint16_t)mapper(x, xMin, xMax, xo, xo + width);
}

// map a y-value float to the plot object
uint16_t Plotter::getScreenY(float y) {
	if (y < yMin) { return yo; }
	if (y > yMax) { return yo+height; }
	return (uint16_t)round(mapper(y, yMin, yMax, yo + height, yo));
}
