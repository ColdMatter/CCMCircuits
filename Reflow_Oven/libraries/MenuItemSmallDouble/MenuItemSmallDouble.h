/************************************
*
* Serial Menu display.
*
* Used to display the Menus over a serial port.
* 
*************************************
* (C) Toby Wilkinson - tobes@tobestool.net - 2013.
************************************/
#ifndef MenuItemSmallDouble_h
#define MenuItemSmallDouble_h

#include "../MenuBase/MenuBase.h"
//#include <WProgram.h>

class MenuItemSmallDouble: public MenuItem {
public: 
	MenuItemSmallDouble (void);
	MenuItemSmallDouble (const char *newName, double *targetDouble, const double min, const double max);
	void init(const char *newName, double *targetDouble, const double min, const double max);
	void init(const __FlashStringHelper *newName_P, double *targetDouble, const double min, const double max);
	void getValueString (char *);
	void select(MenuDisplay *controller);
	void exit(MenuDisplay *controller);
	void inc(MenuDisplay *controller);
	void dec(MenuDisplay *controller);

private:
	double *TargetDouble;
	double CurrentValue;
	double myMin, myMax;
	
};

#endif
