/*
bullet.h

Aron Lebani
6 March 2016
*/

#ifndef BULLET_H

#define BULLET_H

#include "character.h"

class bullet : public character
{
public:
	bullet();
	// Sets width and height

	void draw();
	// Draws bullet on window

	void erase();
	// Erases bullet from window
};

#endif