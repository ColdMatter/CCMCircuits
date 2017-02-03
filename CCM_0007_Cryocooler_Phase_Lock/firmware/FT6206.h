/***************************************************

 ****************************************************/

#ifndef FT6206_H
#define FT6206_H

#include "application.h"

#define FT6206_ADDR           	0x38
#define FT6206_G_FT5201ID     	0xA8
#define FT6206_REG_NUMTOUCHES 	0x02

#define FT6206_NUM_X          	0x33
#define FT6206_NUM_Y          	0x34

#define FT6206_REG_MODE 		0x00
#define FT6206_REG_CALIBRATE 	0x02
#define FT6206_REG_WORKMODE 	0x00
#define FT6206_REG_FACTORYMODE 	0x40
#define FT6206_REG_THRESHHOLD 	0x80
#define FT6206_REG_POINTRATE 	0x88
#define FT6206_REG_FIRMVERS 	0xA6
#define FT6206_REG_CHIPID 		0xA3
#define FT6206_REG_VENDID 		0xA8

#define FT6206_DEFAULT_THRESHOLD 128

class TS_Point {

 public:
  	TS_Point(void);
  	TS_Point(uint16_t x, uint16_t y, uint16_t z);

  	bool operator==(TS_Point);		// overloading == operator for usage with this object
  	bool operator!=(TS_Point);		// overloading != operator for usage with this object

  	uint16_t x, y, z;
};

class FT6206 {

 public:

  	FT6206();									// constructor
  	bool begin(uint8_t thresh = FT6206_DEFAULT_THRESHOLD);	// optionaldefault argument

  	void writeRegister8(uint8_t reg, uint8_t val);
  	uint8_t readRegister8(uint8_t reg);
  	void readData(uint16_t *x, uint16_t *y);

  	bool 	isBeingTouched(void);
  	TS_Point getPoint(void);

 private:
	 uint8_t _int, touches;
	 uint16_t touchX[2], touchY[2], touchID[2];


};

#endif
