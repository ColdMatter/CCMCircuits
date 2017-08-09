#include "FT6206.h"

FT6206::FT6206()
{
}

bool FT6206::begin(uint8_t threshhold)
{
	if ( !Wire.isEnabled() ) Wire.begin();

  	// change threshhold to be higher/lower
  	writeRegister8(FT6206_REG_THRESHHOLD, threshhold);
	if ((readRegister8(FT6206_REG_VENDID) != 17) || (readRegister8(FT6206_REG_CHIPID) != 6)) return false;
  	return true;
}

bool FT6206::isBeingTouched(void)
{
  	uint8_t n = readRegister8(FT6206_REG_NUMTOUCHES);
  	if ((n == 1) || (n == 2)) return true;
  	return false;
}

/*****************************/

void FT6206::readData(uint16_t *x, uint16_t *y) {
  	uint8_t i2cdat[16];
  	Wire.beginTransmission(FT6206_ADDR);
  	Wire.write((byte)0);
  	Wire.endTransmission();
  	Wire.beginTransmission(FT6206_ADDR);
  	Wire.requestFrom((byte)FT6206_ADDR, (byte)32);
  	for (uint8_t i=0; i<16; i++)
    	i2cdat[i] = Wire.read();
  	Wire.endTransmission();

  	touches = i2cdat[0x02];

  	if (touches > 2) {
    	touches = 0;
    	*x = *y = 0;
  	}
  	if (touches == 0) {
    	*x = *y = 0;
    	return;
  	}

    for (uint8_t i=0; i<2; i++) {
      	touchX[i] = i2cdat[0x03 + i*6] & 0x0F;
      	touchX[i] <<= 8;
      	touchX[i] |= i2cdat[0x04 + i*6];
      	touchY[i] = i2cdat[0x05 + i*6] & 0x0F;
      	touchY[i] <<= 8;
      	touchY[i] |= i2cdat[0x06 + i*6];
      	touchID[i] = i2cdat[0x05 + i*6] >> 4;
    }

    *x = touchX[0]; *y = touchY[0];
}

TS_Point FT6206::getPoint(void) {
  	uint16_t x, y;
  	uint8_t z;
  	readData(&x, &y);
  	return TS_Point(x, y, 1);
}


uint8_t FT6206::readRegister8(uint8_t reg) {
  	uint8_t x ;
   // use i2c
    Wire.beginTransmission(FT6206_ADDR);
    Wire.write((byte)reg);
    Wire.endTransmission();
    Wire.beginTransmission(FT6206_ADDR);
    Wire.requestFrom((byte)FT6206_ADDR, (byte)1);
    x = Wire.read();
    Wire.endTransmission();
  	return x;
}

void FT6206::writeRegister8(uint8_t reg, uint8_t val) {
   // use i2c
    Wire.beginTransmission(FT6206_ADDR);
    Wire.write((byte)reg);
    Wire.write((byte)val);
    Wire.endTransmission();
}

/****************/

TS_Point::TS_Point(void) {
  	x = y = 0;
}

TS_Point::TS_Point(uint16_t x0, uint16_t y0, uint16_t z0) {
  	x = x0;
  	y = y0;
  	z = z0;
}

bool TS_Point::operator==(TS_Point p1) {
  	return  ((p1.x == x) && (p1.y == y) && (p1.z == z));
}

bool TS_Point::operator!=(TS_Point p1) {
  	return  ((p1.x != x) || (p1.y != y) || (p1.z != z));
}
