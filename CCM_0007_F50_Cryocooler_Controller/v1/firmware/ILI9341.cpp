/***************************************************
This is an Arduino Library for the Adafruit 2.2" SPI display.
This library works with the Adafruit 2.2" TFT Breakout w/SD card
----> http://www.adafruit.com/products/1480

Check out the links above for our tutorials and wiring diagrams
These displays use SPI to communicate, 4 or 5 pins are required to
interface (RST is optional)
Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.
MIT license, all text above must be included in any redistribution
****************************************************/

#include "ILI9341.h"
#include <limits.h>
#include "application.h"

// Constructor when using hardware SPI.  Faster, but must use specific SPI pins (http://docs.spark.io/#/hardware):
// A2 : SS(Slave Select)
// A3 : SCK(Serial Clock)
// A4 : MISO(Master In Slave Out)
// A5 : MOSI(Master Out Slave In)
// The other pins are: cs - Chip select (aka slave select), dc - D/C or A0 on the screen (Command/Data switch), rst - Reset
ILI9341::ILI9341(uint8_t rst, uint8_t cs, uint8_t dc, uint8_t bl) : GFX(ILI9341_TFTWIDTH, ILI9341_TFTHEIGHT) {
	_cs = cs;
	_dc = dc;
	_rst = rst;
	_bl = bl;
	_mosi = _sclk = 0;

}

inline void ILI9341::spiwrite(uint8_t c)
{
	SPI.transfer(c);
}

inline void ILI9341::writecommand(uint8_t c)
{
	digitalWrite(_dc, LOW);
	digitalWrite(_sclk, LOW);
	digitalWrite(_cs, LOW);
	spiwrite(c);
	digitalWrite(_cs, HIGH);
}

inline void ILI9341::writedata(uint8_t c)
{
	digitalWrite(_dc, HIGH);
	digitalWrite(_sclk, LOW);
	digitalWrite(_cs, LOW);
	spiwrite(c);
	digitalWrite(_cs, HIGH);
}

// Rather than a bazillion writecommand() and writedata() calls, screen
// initialization commands and arguments are organized in these tables
// stored in PROGMEM.  The table may look bulky, but that's mostly the
// formatting -- storage-wise this is hundreds of bytes more compact
// than the equivalent code.  Companion function follows.
#define DELAY 0x80

// Companion code to the above tables.  Reads and issues
// a series of LCD commands stored in PROGMEM byte array.
void ILI9341::commandList(uint8_t *addr) {

	uint8_t numCommands, numArgs;
	uint16_t ms;

	numCommands = pgm_read_byte(addr++);   // Number of commands to follow
	while (numCommands--) {                 // For each command...
		writecommand(pgm_read_byte(addr++)); //   Read, issue command
		numArgs = pgm_read_byte(addr++);    //   Number of args to follow
		ms = numArgs & DELAY;          //   If hibit set, delay follows args
		numArgs &= ~DELAY;                   //   Mask out delay bit
		while (numArgs--) {                   //   For each argument...
			writedata(pgm_read_byte(addr++));  //     Read, issue argument
		}

		if (ms) {
			ms = pgm_read_byte(addr++); // Read post-command delay time (ms)
			if (ms == 255) {
				ms = 500;     // If 255, delay for 500 ms
			}
			delay(ms);
		}
	}
}

void ILI9341::begin(void) {
	pinMode(_rst, OUTPUT);					// configure I/O pins
	pinMode(_dc, OUTPUT);
	pinMode(_cs, OUTPUT);
	pinMode(_bl,OUTPUT);

	digitalWrite(_rst, LOW);

	mosiport = &_mosi;
	clkport = &_sclk;
	rsport = &_rst;
	csport = &_cs;
	dcport = &_dc;

	SPI.begin();
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	SPI.setBitOrder(MSBFIRST);
	SPI.setDataMode(SPI_MODE0);

	// toggle RST low to reset
	digitalWrite(_rst, HIGH);
	delay(5);
	digitalWrite(_rst, LOW);
	delay(20);
	digitalWrite(_rst, HIGH);
	delay(150);

	writecommand(0xEF);
	writedata(0x03);
	writedata(0x80);
	writedata(0x02);

	writecommand(0xCF);
	writedata(0x00);
	writedata(0XC1);
	writedata(0X30);

	writecommand(0xED);
	writedata(0x64);
	writedata(0x03);
	writedata(0X12);
	writedata(0X81);

	writecommand(0xE8);
	writedata(0x85);
	writedata(0x00);
	writedata(0x78);

	writecommand(0xCB);
	writedata(0x39);
	writedata(0x2C);
	writedata(0x00);
	writedata(0x34);
	writedata(0x02);

	writecommand(0xF7);
	writedata(0x20);

	writecommand(0xEA);
	writedata(0x00);
	writedata(0x00);

	writecommand(ILI9341_PWCTR1);    //Power control
	writedata(0x23);   //VRH[5:0]

	writecommand(ILI9341_PWCTR2);    //Power control
	writedata(0x10);   //SAP[2:0];BT[3:0]

	writecommand(ILI9341_VMCTR1);    //VCM control
	writedata(0x3e);
	writedata(0x28);

	writecommand(ILI9341_VMCTR2);    //VCM control2
	writedata(0x86);  //--

	writecommand(ILI9341_MADCTL);    // Memory Access Control
	writedata(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);

	writecommand(ILI9341_PIXFMT);
	writedata(0x55);

	writecommand(ILI9341_FRMCTR1);
	writedata(0x00);
	writedata(0x18);

	writecommand(ILI9341_DFUNCTR);    // Display Function Control
	writedata(0x08);
	writedata(0x82);
	writedata(0x27);

	writecommand(0xF2);    // 3Gamma Function Disable
	writedata(0x00);

	writecommand(ILI9341_GAMMASET);    //Gamma curve selected
	writedata(0x01);

	writecommand(ILI9341_GMCTRP1);    //Set Gamma
	writedata(0x0F);
	writedata(0x31);
	writedata(0x2B);
	writedata(0x0C);
	writedata(0x0E);
	writedata(0x08);
	writedata(0x4E);
	writedata(0xF1);
	writedata(0x37);
	writedata(0x07);
	writedata(0x10);
	writedata(0x03);
	writedata(0x0E);
	writedata(0x09);
	writedata(0x00);

	writecommand(ILI9341_GMCTRN1);    //Set Gamma
	writedata(0x00);
	writedata(0x0E);
	writedata(0x14);
	writedata(0x03);
	writedata(0x11);
	writedata(0x07);
	writedata(0x31);
	writedata(0xC1);
	writedata(0x48);
	writedata(0x08);
	writedata(0x0F);
	writedata(0x0C);
	writedata(0x31);
	writedata(0x36);
	writedata(0x0F);

	writecommand(ILI9341_SLPOUT);    // Exit Sleep
	delay(120);
	writecommand(ILI9341_DISPON);    // Display on

	sleeping = false;
}

bool ILI9341::isAsleep() {return sleeping;}

bool ILI9341::isAwake() {return !sleeping;}

void ILI9341::wakeup() {
	for(uint8_t i = 0 ; i <= backlight; i++) {				// ramp the backlight on
	  analogWrite(_bl,i);
	  delay(1);
	}
	sleeping = false;
}

void ILI9341::sleep() {
	for (uint8_t i=backlight; i==0; i--) {
		analogWrite(_bl,i);
		delay(1);
	}
	sleeping = true;
}

void ILI9341::clearScreen() {fillScreen(background);}

void ILI9341::clearScreen(uint16_t color) {fillScreen(color);}

void ILI9341::showCoordinates(uint16_t x, uint16_t y) {
	drawCircle(x, y, 10, GREEN);
	setCursor(x - 50, y - 30);
	setTextSize(2);
	setTextColor(BLUE);
	print("(");
	print(x);
	print(",");
	print(y);
	print(")");
}

void ILI9341::introScreen() {
	clearScreen();
	fillRect(71, 70, 50, 100, JJCOLOR);
	fillRect(134, 70, 50, 100, JJCOLOR);
	fillRect(197, 70, 50, 100, JJCOLOR);
	drawRect(46, 45, 228, 150, WHITE);
	delay(250);
	drawString(85, 100, "A", WHITE, 5);
	delay(250);
	drawString(147, 100, "c", WHITE, 5);
	delay(250);
	drawString(210, 100, "r", WHITE, 5);
	delay(500);

	clearScreen();
	fillRect(0, 0, 320, 10, JJCOLOR); // status bar
	drawhomeicon(); // draw the home icon
	drawString(1, 1, "Your status bar message here.    JOS 1.3 Beta", WHITE, 1);
	ant(); 											// draw the bas "antenna" line without the "signal waves"
	signal(); 										// draw the "signal waves" around the "antenna"
	homescr(); 										// draw the homescreen
	drawRect(40, 200, 240, 40, WHITE); 				// message box (xo,yo,width,height,color)
	delay(500);
}

// set backlight 0-255
void ILI9341::setBacklight(uint8_t brightness) {
	backlight = brightness;
	analogWrite(_bl, backlight, 500);
}

uint8_t ILI9341::getBacklight() {
	return backlight;
}

void ILI9341::setBackground(uint16_t color) {
	background = color;
	clearScreen();
}

uint16_t ILI9341::getBackground() {
	return background;
}

void ILI9341::drawhomeicon() { // draws a white home icon
	drawLine(280, 219, 299, 200, WHITE);
	drawLine(300, 200, 304, 204, WHITE);
	drawLine(304, 203, 304, 200, WHITE);
	drawLine(305, 200, 307, 200, WHITE);
	drawLine(308, 200, 308, 208, WHITE);
	drawLine(309, 209, 319, 219, WHITE);
	drawLine(281, 219, 283, 219, WHITE);
	drawLine(316, 219, 318, 219, WHITE);
	drawRect(284, 219, 32, 21, WHITE);
	drawRect(295, 225, 10, 15, WHITE);
}

void ILI9341::drawhomeiconred() { // draws a red home icon
	drawLine(280, 219, 299, 200, RED);
	drawLine(300, 200, 304, 204, RED);
	drawLine(304, 203, 304, 200, RED);
	drawLine(305, 200, 307, 200, RED);
	drawLine(308, 200, 308, 208, RED);
	drawLine(309, 209, 319, 219, RED);
	drawLine(281, 219, 283, 219, RED);
	drawLine(316, 219, 318, 219, RED);
	drawRect(284, 219, 32, 21, RED);
	drawRect(295, 225, 10, 15, RED);
}

void ILI9341::signal() { // draws a whit 'signal indicator'
	drawLine((antpos + 4), 4, (antpos + 4), 5, WHITE);
	drawPixel((antpos + 3), 2, WHITE);
	drawPixel((antpos + 3), 7, WHITE);
	drawPixel((antpos + 2), 0, WHITE);
	drawLine((antpos + 2), 3, (antpos + 2), 6, WHITE);
	drawPixel((antpos + 2), 9, WHITE);
	drawPixel((antpos + 1), 1, WHITE);
	drawPixel((antpos + 1), 8, WHITE);
	drawLine(antpos, 2, antpos, 7, WHITE);
	drawLine((antpos + 6), 4, (antpos + 6), 5, WHITE);
	drawPixel((antpos + 7), 2, WHITE);
	drawPixel((antpos + 7), 7, WHITE);
	drawPixel((antpos + 8), 0, WHITE);
	drawLine((antpos + 8), 3, (antpos + 8), 6, WHITE);
	drawPixel((antpos + 8), 9, WHITE);
	drawPixel((antpos + 9), 1, WHITE);
	drawPixel((antpos + 9), 8, WHITE);
	drawLine((antpos + 10), 2, (antpos + 10), 7, WHITE);
}

void ILI9341::ant() {
	fillRect((antpos + 5), 4, 1, 6, WHITE); // draws the "antenna" for the signal indicator
}

void ILI9341::boxes() { // redraw the button outline boxes
	drawRect(0, 20, 150, 50, JJCOLOR);
	drawRect(170, 20, 150, 50, JJCOLOR);
	drawRect(0, 80, 150, 50, JJCOLOR);
	drawRect(170, 80, 150, 50, JJCOLOR);
	drawRect(0, 140, 150, 50, JJCOLOR);
	drawRect(170, 140, 150, 50, JJCOLOR);
}

void ILI9341::homescr() {
	boxes();
	drawString(41, 37, "LEDs", WHITE, 2);
	drawString(210, 37, "Sensors", WHITE, 2);
	drawString(41, 97, "Info", WHITE, 2);
	drawString(210, 97, "Settings", WHITE, 2);
//	drawString(41, 157, "Menu 5", WHITE, 2);
//	drawString(200, 157, "Settings", WHITE, 2);
}


void ILI9341::setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1,	uint16_t y1) {

	writecommand(ILI9341_CASET); // Column addr set
	writedata(x0 >> 8);
	writedata(x0 & 0xFF);     // XSTART
	writedata(x1 >> 8);
	writedata(x1 & 0xFF);     // XEND

	writecommand(ILI9341_PASET); // Row addr set
	writedata(y0 >> 8);
	writedata(y0);     // YSTART
	writedata(y1 >> 8);
	writedata(y1);     // YEND

	writecommand(ILI9341_RAMWR); // write to RAM
}

void ILI9341::pushColor(uint16_t color) {
	digitalWrite(_dc, HIGH);
	digitalWrite(_cs, LOW);
	spiwrite(color >> 8);
	spiwrite(color);
	digitalWrite(_cs, HIGH);
}

void ILI9341::drawPixel(int16_t x, int16_t y, uint16_t color) {
	if ((x < 0) || (x >= _width) || (y < 0) || (y >= _height)) {return;}
	setAddrWindow(x, y, x + 1, y + 1);
	digitalWrite(_dc, HIGH);
	digitalWrite(_cs, LOW);
	spiwrite(color >> 8);
	spiwrite(color);
	digitalWrite(_cs, HIGH);
}

void ILI9341::drawFastVLine(int16_t x, int16_t y, int16_t h,
	uint16_t color) {
	// Rudimentary clipping
	if ((x >= _width) || (y >= _height)) {
		return;
	}
	if ((y + h - 1) >= _height) {
		h = _height - y;
	}

	setAddrWindow(x, y, x, y + h - 1);

	uint8_t hi = color >> 8, lo = color;

	digitalWrite(_dc, HIGH);
	digitalWrite(_cs, LOW);

	while (h--) {
		spiwrite(hi);
		spiwrite(lo);
	}

	digitalWrite(_cs, HIGH);
}

void ILI9341::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {

	// Rudimentary clipping
	if ((x >= _width) || (y >= _height)) {
		return;
	}

	if ((x + w - 1) >= _width) {
		w = _width - x;
	}

	setAddrWindow(x, y, x + w - 1, y);

	uint8_t hi = color >> 8, lo = color;

	digitalWrite(_dc, HIGH);
	digitalWrite(_cs, LOW);

	while (w--) {
		spiwrite(hi);
		spiwrite(lo);
	}

	digitalWrite(_cs, HIGH);
}

void ILI9341::drawString(uint16_t x, uint16_t y, const String& aString) {
	setCursor(x,y);
	print(aString);
}

void ILI9341::drawString(uint16_t x, uint16_t y, const String& aString, uint16_t color) {
	uint16_t oldTextColor = getTextColor();
	setCursor(x,y);
	setTextColor(color);
	print(aString);
	setTextColor(oldTextColor);
}

void ILI9341::drawString(uint16_t x, uint16_t y, const String& aString, uint16_t color, uint8_t size) {
	uint8_t oldTextSize = getTextSize();
	uint16_t oldTextColor = getTextColor();
	setCursor(x,y);
	setTextColor(color);
	setTextSize(size);
	print(aString);
	setTextColor(oldTextColor);
	setTextSize(oldTextSize);
}

void ILI9341::fillScreen(uint16_t color) {
	fillRect(0, 0, _width, _height, color);
}

// fill a rectangle
void ILI9341::fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
	uint16_t color) {

	// rudimentary clipping (drawChar w/big text requires this)
	if ((x >= _width) || (y >= _height)) return;
	if ((x + w - 1) >= _width) {
		w = _width - x;
	}
	if ((y + h - 1) >= _height) {
		h = _height - y;
	}

	setAddrWindow(x, y, x + w - 1, y + h - 1);

	uint8_t hi = color >> 8, lo = color;

	digitalWrite(_dc, HIGH);
	digitalWrite(_cs, LOW);

	for (y = h; y > 0; y--) {
		for (x = w; x > 0; x--) {
			spiwrite(hi);
			spiwrite(lo);
		}
	}

	digitalWrite(_cs, HIGH);
}

// Pass 8-bit (each) R,G,B, get back 16-bit packed color
uint16_t ILI9341::color565(uint8_t r, uint8_t g, uint8_t b) {
	return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

void ILI9341::setRotation(uint8_t m) {

	writecommand(ILI9341_MADCTL);
	rotation = m % 4; // can't be higher than 3

	switch (rotation) {
	case 0:
		writedata(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);
		_width = ILI9341_TFTWIDTH;
		_height = ILI9341_TFTHEIGHT;
		break;
	case 1:
		writedata(ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
		_width = ILI9341_TFTHEIGHT;
		_height = ILI9341_TFTWIDTH;
		break;
	case 2:
		writedata(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
		_width = ILI9341_TFTWIDTH;
		_height = ILI9341_TFTHEIGHT;
		break;
	case 3:
		writedata(
			ILI9341_MADCTL_MV | ILI9341_MADCTL_MY | ILI9341_MADCTL_MX
			| ILI9341_MADCTL_BGR);
		_width = ILI9341_TFTHEIGHT;
		_height = ILI9341_TFTWIDTH;
		break;
	}
}

void ILI9341::invertDisplay(boolean i) {
	writecommand(i ? ILI9341_INVON : ILI9341_INVOFF);
}

////////// stuff not actively being used, but kept for posterity

inline uint8_t ILI9341::spiread(void) {
	uint8_t r = 0;

	r = SPI.transfer(0x00);
	//Serial.print("read: 0x"); Serial.print(r, HEX);

	return r;
}

inline uint8_t ILI9341::readdata(void) {
	digitalWrite(_dc, HIGH);
	digitalWrite(_cs, LOW);
	uint8_t r = spiread();
	digitalWrite(_cs, HIGH);

	return r;
}

inline uint8_t ILI9341::readcommand8(uint8_t c) {
	digitalWrite(_dc, LOW);
	digitalWrite(_sclk, LOW);
	digitalWrite(_cs, LOW);
	spiwrite(c);
	digitalWrite(_dc, HIGH);
	uint8_t r = spiread();
	digitalWrite(_cs, HIGH);
	return r;
}
