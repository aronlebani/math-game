/*
character.cpp

Aron Lebani
29 March 2016
*/

#include "../include/character.h"

character::character()
{
	// Void
}

int character::getX()
{
	return _x;
}

void character::setX(int x)
{
	_x = x;
}

int character::getY()
{
	return _y;
}

void character::setY(int y)
{
	_y = y;
}

int character::getXc()
{
	return _x + width/2;
}

void character::setXc(int x)
{
	_x = x - width/2;
}

int character::getYc()
{
	return _y + height/2;
}

void character::setYc(int y)
{
	_y = y - height/2;
}

int character::getWidth()
{
	return width;
}

int character::getHeight()
{
	return height;
}