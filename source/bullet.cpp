/*
bullet.cpp

Aron Lebani
29 March 2016
*/

#include "../include/character.h"
#include "../include/bullet.h"
#include "../include/tools.h"

bullet::bullet()
{
	width = 13;
	height = 2;
}

void bullet::draw()
{
	tools::printw(getY()  , getX(), "      x      ");
	tools::printw(getY()+1, getX(), "      x      ");
}

void bullet::erase()
{
	int i, j;
	for (i=0; i<height; i++)
	{
		for (j=0; j<width; j++)
		{
			tools::printw(getY()+i, getX()+j, " ");
		}
	}
}