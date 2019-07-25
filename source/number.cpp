/*
number.cpp

Aron Lebani
8 March 2016
*/

#include "../include/character.h"
#include "../include/number.h"
#include "../include/tools.h"

number::number()
{
	_num = 0;
	width = 5;
	height = 5;
}

number::number(int num)
{
	_num = num;
	height = 5;
	if (_num <= 9)
	{
		width = 5;
	}
	else if (_num <= 99)
	{
		width = 11;
	}
	else if (_num < 999)
	{
		width = 17;
	}
}

void number::draw()
{
	if (_num == 0)
	{
		tools::printw(getY()  , getX(), " xxx ");
		tools::printw(getY()+1, getX(), "x   x");
		tools::printw(getY()+2, getX(), "x   x");
		tools::printw(getY()+3, getX(), "x   x");
		tools::printw(getY()+4, getX(), " xxx ");
	}
	else if (_num == 1)
	{
		tools::printw(getY()  , getX(), " xx  ");
		tools::printw(getY()+1, getX(), "  x  ");
		tools::printw(getY()+2, getX(), "  x  ");
		tools::printw(getY()+3, getX(), "  x  ");
		tools::printw(getY()+4, getX(), " xxx ");
	}
	else if (_num == 2)
	{
		tools::printw(getY()  , getX(), " xxx ");
		tools::printw(getY()+1, getX(), "x   x");
		tools::printw(getY()+2, getX(), "   x ");
		tools::printw(getY()+3, getX(), " x   ");
		tools::printw(getY()+4, getX(), "xxxxx");
	}
	else if (_num == 3)
	{
		tools::printw(getY()  , getX(), "xxxxx");
		tools::printw(getY()+1, getX(), "    x");
		tools::printw(getY()+2, getX(), "xxxxx");
		tools::printw(getY()+3, getX(), "    x");
		tools::printw(getY()+4, getX(), "xxxxx");
	}
	else if (_num == 4)
	{
		tools::printw(getY()  , getX(), "x    ");
		tools::printw(getY()+1, getX(), "x    ");
		tools::printw(getY()+2, getX(), "x x  ");
		tools::printw(getY()+3, getX(), "xxxxx");
		tools::printw(getY()+4, getX(), "  x  ");
	}
	else if (_num == 5)
	{
		tools::printw(getY()  , getX(), "xxxxx");
		tools::printw(getY()+1, getX(), "x    ");
		tools::printw(getY()+2, getX(), "xxxxx");
		tools::printw(getY()+3, getX(), "    x");
		tools::printw(getY()+4, getX(), "xxxxx");
	}
	else if (_num == 6)
	{
		tools::printw(getY()  , getX(), "xxxxx");
		tools::printw(getY()+1, getX(), "x    ");
		tools::printw(getY()+2, getX(), "xxxxx");
		tools::printw(getY()+3, getX(), "x   x");
		tools::printw(getY()+4, getX(), "xxxxx");
	}
	else if (_num == 7)
	{
		tools::printw(getY()  , getX(), "xxxxx");
		tools::printw(getY()+1, getX(), "    x");
		tools::printw(getY()+2, getX(), "    x");
		tools::printw(getY()+3, getX(), "    x");
		tools::printw(getY()+4, getX(), "    x");
	}
	else if (_num == 8)
	{
		tools::printw(getY()  , getX(), "xxxxx");
		tools::printw(getY()+1, getX(), "x   x");
		tools::printw(getY()+2, getX(), "xxxxx");
		tools::printw(getY()+3, getX(), "x   x");
		tools::printw(getY()+4, getX(), "xxxxx");
	}
	else if (_num == 9)
	{
		tools::printw(getY()  , getX(), "xxxxx");
		tools::printw(getY()+1, getX(), "x   x");
		tools::printw(getY()+2, getX(), "xxxxx");
		tools::printw(getY()+3, getX(), "    x");
		tools::printw(getY()+4, getX(), "    x");
	}
	else if (_num > 9 && _num <= 99)
	{
		int numTemp = _num;
		int xTemp = getX();
		_num = numTemp / 10;
		draw();
		setX(xTemp + width/2 + 1);
		_num = numTemp % 10;
		draw();
		_num = numTemp;
		setX(xTemp);
	}
	else if (_num > 99 && _num <= 999)
	{
		int numTemp = _num;
		int xTemp = getX();
		_num = numTemp / 100;
		draw();
		setX(xTemp + width/3 + 1);
		_num = (numTemp / 10) % 10;
		draw();
		setX(xTemp + 2*(width/3) + 2);
		_num = numTemp % 10;
		draw();
		_num = numTemp;
		setX(xTemp);
	}
}

void number::erase()
{
	int i, j;
	int w;
	for (i=0; i<height; i++)
	{
		for (j=0; j<width; j++)
		{
			tools::printw(getY()+i, getX()+j, " ");
		}
	}
}

int number::getNum()
{
	return _num;
}

void number::setNum(int num)
{
	_num = num;
	height = 5;
	if (_num <= 9)
	{
		width = 5;
	}
	else if (_num <= 99)
	{
		width = 11;
	}
	else if (_num < 999)
	{
		width = 17;
	}
}