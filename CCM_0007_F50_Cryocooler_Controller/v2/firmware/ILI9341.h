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

#ifndef ILI9341_H
#define ILI9341_H

#include "GFX.h"
#include "application.h"

//#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
//#define pgm_read_word(addr) (*(const unsigned short *)(addr))

#define inline inline __attribute__((always_inline))

#define ILI9341_TFTWIDTH  240
#define ILI9341_TFTHEIGHT 320

#define ILI9341_NOP     0x00
#define ILI9341_SWRESET 0x01
#define ILI9341_RDDID   0x04
#define ILI9341_RDDST   0x09

#define ILI9341_SLPIN   0x10
#define ILI9341_SLPOUT  0x11
#define ILI9341_PTLON   0x12
#define ILI9341_NORON   0x13

#define ILI9341_RDMODE  0x0A
#define ILI9341_RDMADCTL  0x0B
#define ILI9341_RDPIXFMT  0x0C
#define ILI9341_RDIMGFMT  0x0A
#define ILI9341_RDSELFDIAG  0x0F

#define ILI9341_INVOFF  0x20
#define ILI9341_INVON   0x21
#define ILI9341_GAMMASET 0x26
#define ILI9341_DISPOFF 0x28
#define ILI9341_DISPON  0x29

#define ILI9341_CASET   0x2A
#define ILI9341_PASET   0x2B
#define ILI9341_RAMWR   0x2C
#define ILI9341_RAMRD   0x2E

#define ILI9341_PTLAR   0x30
#define ILI9341_MADCTL  0x36

#define ILI9341_MADCTL_MY  0x80
#define ILI9341_MADCTL_MX  0x40
#define ILI9341_MADCTL_MV  0x20
#define ILI9341_MADCTL_ML  0x10
#define ILI9341_MADCTL_RGB 0x00
#define ILI9341_MADCTL_BGR 0x08
#define ILI9341_MADCTL_MH  0x04

#define ILI9341_PIXFMT  0x3A

#define ILI9341_FRMCTR1 0xB1
#define ILI9341_FRMCTR2 0xB2
#define ILI9341_FRMCTR3 0xB3
#define ILI9341_INVCTR  0xB4
#define ILI9341_DFUNCTR 0xB6

#define ILI9341_PWCTR1  0xC0
#define ILI9341_PWCTR2  0xC1
#define ILI9341_PWCTR3  0xC2
#define ILI9341_PWCTR4  0xC3
#define ILI9341_PWCTR5  0xC4
#define ILI9341_VMCTR1  0xC5
#define ILI9341_VMCTR2  0xC7

#define ILI9341_RDID1   0xDA
#define ILI9341_RDID2   0xDB
#define ILI9341_RDID3   0xDC
#define ILI9341_RDID4   0xDD

#define ILI9341_GMCTRP1 0xE0
#define ILI9341_GMCTRN1 0xE1

// Color definitions (5:6:5 R:G:B formatted)
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY	0x8C71
#define AMBER	0xFD01
#define LIGHTGRAY 0xD75C
#define TEST	0x1BF5
#define JJCOLOR 0x1CB6
#define JJORNG	0xFD03
#define ORANGE  0xE9A2


class ILI9341 : public GFX {

public:
	ILI9341(uint8_t rst, uint8_t cs, uint8_t dc, uint8_t bl);

	void     begin(),
		setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1),
		pushColor(uint16_t color),
		fillScreen(uint16_t color),
		drawPixel(int16_t x, int16_t y, uint16_t color),
		drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
		drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),
		fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
		setRotation(uint8_t r),
		invertDisplay(boolean i),
		drawString(uint16_t x, uint16_t y, const String& aString),
		drawString(uint16_t x, uint16_t y, const String& aString, uint16_t color),
		drawString(uint16_t x, uint16_t y, const String& aString, uint16_t color, uint8_t size),
		showCoordinates(uint16_t x, uint16_t y),
		clearScreen(),
		clearScreen(uint16_t color),
		introScreen(void);

	uint16_t color565(uint8_t r, uint8_t g, uint8_t b);

	void setBacklight(uint8_t value);
	uint8_t getBacklight();
	void wakeup();
	bool isAwake();
	bool isAsleep();
	void sleep();


	void setBackground(uint16_t color);
	uint16_t getBackground(void);

	/* These are not for current use, 8-bit protocol only! */
	uint8_t  readdata(void), readcommand8(uint8_t);

	void     spiwrite(uint8_t),
		writecommand(uint8_t c),
		writedata(uint8_t d),
		commandList(uint8_t *addr);
	uint8_t  spiread(void);

	void homescr();
	void settingsscr();
	void ledsscr();
	void sensorsscr();
	void infoscr();

	void drawhomeicon();
	void drawhomeiconred();
	void clearmessage();
	void signalact();
	void signal();
	void boxes();
	void ant();
	void blbar();
	void blightdown();
	void blightup();
	void showsleep();
	void sleepdec();
	void sleepinc();
	void clearsettings();
	void clearcenter();
	void redraw();

private:
	volatile uint8_t *mosiport, *clkport, *dcport, *rsport, *csport;
	uint8_t  _cs, _dc, _rst, _mosi, _miso, _sclk, _bl, backlight;
	uint16_t background;
	bool sleeping;

	const uint16_t antpos = 278;


};

#endif
