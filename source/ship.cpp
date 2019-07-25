/*
ship.cpp

Aron Lebani
29 March 2016
*/

#include "../include/character.h"
#include "../include/ship.h"
#include "../include/tools.h"
#include "../include/bullet.h"

ship::ship()
{
	width = 13;
	height = 6;
}

void ship::draw()
{
	tools::printw(getY()  , getX(), "      x      ");
	tools::printw(getY()+1, getX(), "     xxx     ");
	tools::printw(getY()+2, getX(), "     xxx     ");
	tools::printw(getY()+3, getX(), " xxxxxxxxxxx ");
	tools::printw(getY()+4, getX(), "xxxxxxxxxxxxx");
	tools::printw(getY()+5, getX(), "xxxxxxxxxxxxx");
}

void ship::erase()
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

void ship::explode()
{
	erase();
	int x = getX()+width/2;
	int y = getY()+height/2;
	tools::printw(y, x, "*");
	tools::delay(100);
	tools::printw(y-1, x-1, " * ");
	tools::printw(y  , x-1, "* *");
	tools::printw(y+1, x-1, " * ");
	tools::delay(100);
	tools::printw(y-2, x-4, "   ***  ");
	tools::printw(y-1, x-4, " *     * ");
	tools::printw(y  , x-4, "*       *");
	tools::printw(y+1, x-4, " *     * ");
	tools::printw(y+2, x-4, "   ***   ");
	tools::delay(100);
	tools::printw(y-3, x-5, "   *****   ");
	tools::printw(y-2, x-5, " *       * ");
	tools::printw(y-1, x-5, "*         *");
	tools::printw(y  , x-5, "*         *");
	tools::printw(y+1, x-5, "*         *");
	tools::printw(y+2, x-5, " *       * ");
	tools::printw(y+3, x-5, "   *****   ");
	tools::delay(100);
	tools::printw(y-3, x-5, "           ");
	tools::printw(y-2, x-5, "           ");
	tools::printw(y-1, x-5, "           ");
	tools::printw(y  , x-5, "           ");
	tools::printw(y+1, x-5, "           ");
	tools::printw(y+2, x-5, "           ");
	tools::printw(y+3, x-5, "           ");
}

void ship::fire(int distance)
{
	torp.setX(getX());
	for (int i=1; i<distance; i++)
	{
		torp.setY(getY()-1-i);
		torp.draw();
		tools::delay(20);
		torp.erase();
	}
}