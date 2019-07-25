/*
alien.cpp

Aron Lebani
6 March 2016
*/

#include "../include/character.h"
#include "../include/number.h"
#include "../include/alien.h"
#include "../include/tools.h"

alien::alien()
{
	a = -1;
	b = -1;
	_type = 1;
	width = 11;
	height = 8;
	alive = true;
}

alien::alien(int numA, int numB, int type)
{
	a = numA;
	b = numB;
	_type = type;
	width = 11;
	if (numA >= 0 && numB >= 0)
	{
		height = 10;
	}
	else
	{
		height = 8;
	}
	alive = true;
}

void alien::draw()
{
	if (alive)
	{
		if (_type == 1)
		{
			tools::printw(getY()  , getX(), "  @     @  ");
			tools::printw(getY()+1, getX(), "   @   @   ");
			tools::printw(getY()+2, getX(), "  @@@@@@@  ");
			tools::printw(getY()+3, getX(), " @@ @@@ @@ ");
			tools::printw(getY()+4, getX(), "@@@@@@@@@@@");
			tools::printw(getY()+5, getX(), "@ @@@@@@@ @");
			tools::printw(getY()+6, getX(), "@ @     @ @");
			tools::printw(getY()+7, getX(), "   @@ @@   ");
		}
		else if (_type == 2)
		{
			tools::printw(getY()  , getX(), "  @     @  ");
			tools::printw(getY()+1, getX(), "@  @   @  @");
			tools::printw(getY()+2, getX(), "@ @@@@@@@ @");
			tools::printw(getY()+3, getX(), "@@@ @@@ @@@");
			tools::printw(getY()+4, getX(), "@@@@@@@@@@@");
			tools::printw(getY()+5, getX(), " @@@@@@@@@ ");
			tools::printw(getY()+6, getX(), "  @     @  ");
			tools::printw(getY()+7, getX(), " @       @ ");
		}
		else if (_type == 3)
		{
			tools::printw(getY()  , getX(), "    @@@    ");
			tools::printw(getY()+1, getX(), "   @@@@@   ");
			tools::printw(getY()+2, getX(), "  @@@@@@@  ");
			tools::printw(getY()+3, getX(), " @@ @@@ @@ ");
			tools::printw(getY()+4, getX(), " @@@@@@@@@ ");
			tools::printw(getY()+5, getX(), "  @ @@@ @  ");
			tools::printw(getY()+6, getX(), " @       @ ");
			tools::printw(getY()+7, getX(), "  @     @  ");
		}
		else if (_type == 4)
		{
			tools::printw(getY()  , getX(), "    @@@    ");
			tools::printw(getY()+1, getX(), "   @@@@@   ");
			tools::printw(getY()+2, getX(), "  @@@@@@@  ");
			tools::printw(getY()+3, getX(), " @@ @@@ @@ ");
			tools::printw(getY()+4, getX(), " @@@@@@@@@ ");
			tools::printw(getY()+5, getX(), "   @   @   ");
			tools::printw(getY()+6, getX(), "  @ @@@ @  ");
			tools::printw(getY()+7, getX(), " @ @   @ @ ");
		}

		if (a >= 0 && b >= 0)
		{
			tools::printw(getY()+9, getX(), " [   x   ] ");
			tools::printw(getY()+9, getX()+3, a);
			tools::printw(getY()+9, getX()+7, b);
		}
	}
}

void alien::erase()
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

bool alien::isAlive()
{
	return alive;
}

void alien::setState(bool state)
{
	alive = state;
}

void alien::kill()
{
	explode();
	alive = false;
}

int alien::getNumA()
{
	return a;
}

int alien::getNumB()
{
	return b;
}

void alien::setNum(int numA, int numB)
{
	a = numA;
	b = numB;
	if (numA >= 0 && numB >= 0)
	{
		height = 10;
	}
	else
	{
		height = 8;
	}
}

void alien::setType(int type)
{
	_type = type;
}

int alien::getType()
{
	return _type;
}

void alien::explode()
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