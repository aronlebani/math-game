/*
menu.cpp

Aron Lebani
6 March 2016
*/

#include "../include/menu.h"
#include "../include/math.h"
#include "../include/tools.h"
#include "../include/alien.h"

void menu(math& game)
{
	bool run = true;
	int xMax, yMax;

	while (run)
	{
		tools::clearw();

		int pos;

		alien Mawhonic(-1, -1, 1);

		Mawhonic.setX(0);
		Mawhonic.setY(0);

		tools::printw(Mawhonic.getHeight()*1/2, Mawhonic.getWidth()+2, "Play game");
		tools::printw(Mawhonic.getHeight()*3/2, Mawhonic.getWidth()+2, "High Scores");
		tools::printw(Mawhonic.getHeight()*5/2, Mawhonic.getWidth()+2, "Instructions");
		tools::printw(Mawhonic.getHeight()*7/2, Mawhonic.getWidth()+2, "Quit");

		pos = selectItem(Mawhonic);

		switch (pos)
		{
		case 0:
			game.play();
			break;
		case 1:
			game.scores();
			break;
		case 2:
			game.instructions();
			break;
		case 3:
			run = false;
			break;
		}
	}
}

int selectItem(alien& dudBolt)
{	
	int pos = 0;
	int key = UP;

	dudBolt.draw();

	while (key != ENTER)
	{
		key = tools::getkey();
		if (key == UP && pos != 0)
		{
			pos --;
		}
		else if (key == DOWN && pos != 3)
		{
			pos ++;
		}
		dudBolt.erase();
		dudBolt.setY(pos*dudBolt.getHeight());
		dudBolt.draw();
	}
	return pos;
}