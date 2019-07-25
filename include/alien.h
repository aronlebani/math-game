/*
alien.h

Aron Lebani
6 March 2016
*/

#ifndef ALIEN_H

#define ALIEN_H

#include "character.h"
#include "number.h"

class alien : public character
{
public:
	alien();
	// Creates a single alien

	alien(int numA, int numB, int type);
	// Creates a single alien
	// Set numbers on alien
	// set numbers to -1 for no number
	// "type" is the type of alien to be drawn, 1 <= type <= 4

	void draw();
	// Draws alien on window
	// Alien will only be drawn if it's state is "alive"

	void erase();
	// Erases alien from window

	bool isAlive();
	// Returns state of alien, true = alive, false = dead

	void setState(bool state);
	// Set state of alien, true = alive, false = dead

	void kill();
	// Set state of alien to false
	// Alien explodes

	int getNumA();
	// Returns number A stored on alien

	int getNumB();
	// Returns number B stored on alien

	void setNum(int numA, int numB);
	// Sets number stored on alien
	// Set numbers to -1 for no number

	void setType(int type);
	// Set alien type
	// "type" is an integer between 1 and 4 inclusive

	int getType();
	// Returns alien type

private:
	bool alive;
	// State of alien: true = alive, fale = dead

	int a;
	// Number stored on alien: left side

	int b;
	// Number stored on alien: right side

	int _type;
	// Type of alien

	void explode();
	// Explodes alien
};

#endif