/*
ship.h

Aron Lebani
29 March 2016
*/

#ifndef SHIP_H

#define SHIP_H

#include "character.h"
#include "number.h"
#include "bullet.h"

class ship : public character
{
public:
	ship();
	// Sets width and height

	void draw();
	// Draws ship on window

	void erase();
	// Erases ship from window

	void explode();
	// Explodes ship

	void fire(int distance);
	// Fires bullet

private:
	bullet torp;
	// Bullet to be used with ship
};

#endif