/*
number.h

Aron Lebani
8 March 2016
*/

#ifndef NUMBER_H

#define NUMBER_H

#include "character.h"

class number : public character
{
public:
	number();
	// If no input arguments are specified, number is set to zero by default

	number(int num);
	// Set number
	// Number must be <= 2 digits

	void draw();
	// Draws number on window
	// Numbers are 5x5 characters

	void erase();
	// Erase number from window

	int getNum();
	// Return number

	void setNum(int num);
	// Set number
	// Number must be in [0, 999]

private:
	int _num;
	// Number to be drawn
};

#endif