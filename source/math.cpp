/*
math.cpp

Aron Lebani
29 March 2016
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#include "../include/arcade.h"
#include "../include/math.h"
#include "../include/tools.h"
#include "../include/alien.h"
#include "../include/ship.h"
#include "../include/bullet.h"
#include "../include/number.h"

math::math(std::string file) : arcade(file)
{
	set = 0;	// Initialise
	rows = 0;	// Initialise
	columns = 0;	// Initialise
	success = false;	// Initialise
	iAlign = -1;	// Initialise
	jAlign = -1;	// Initialise
	tools::getmaxw(yMax, xMax);	// Get extent of window
}

void math::scores()
{
	tools::clearw();

	tools::printw(0, 0, "High Scores:");

	tools::printw(2, 0, "User      Score     Set of times tables");

	for (int i = 0; i < N_SCORES; i++)
	{
		tools::printw(4+i, 0, getHighUser(i).c_str());
		tools::printw(4+i, 10, getHighScore(i));
		tools::printw(4+i, 20, getScoreParam(i));
	}
	tools::cont(8, 0);
}

void math::instructions()
{
	tools::clearw();
	tools::printw(0, 0, "Instructions:");
	tools::printw(2, 0, "Aliens are invading the earth! Due to your mathematical abilities, you are the only one who can save the world.\n\nEach alien has a times-tables problem for you to answer. Type in your answer and shoot the alien. Answer\ncorrectly, and you destroy the alien. Answer incorrectly, and the aliens get closer to earth...\n\nIf the aliens reach earth before they are destroyed, game over. If you destroy all the aliens on the screen,\nyou go to the next level. Beware, each level more aliens come. And in greater numbers...\n\nHow to play:\n\nType in a number and press ENTER to choose your answer. The number you typed will appear at the bottom left\nof the screen.\n\nPress SPACE to fire.\n\nUse the LEFT and RIGHT arrow keys to move your spaceship.\n\nGood luck! The future of humankind depends on you.");
	tools::cont(22, 0);
}

void math::gameBeginning()
{
	// Set up a few bits and pieces

	srand(time(NULL));	// Seed random number generator for call to function "operate"

	// Get window size again in case it changed
	tools::getmaxw(yMax, xMax);

	// Ask which set of times tables to play

	tools::clearw();	// Clear window
	tools::printw(1, xMax/2-24, "Which set of times tables would you like to play?");
	number *sel = new number;	// Currently selected number on screen, initialise to zero
	sel->setNum(0);
	sel->setXc(xMax/2);
	sel->setY(3);
	set = selectNum(*sel, 12);	// Get number from user
	setParam(set);	// Set extra score parameter to be the set of times tables being used
	delete sel;
}

bool math::gameAttempt(int lvl)
{
	tools::getmaxw(yMax, xMax);	// Get window size again in case it changed

	tools::clearw();	// Clear window

	int key;	// Stores key entered by user

	printData();	// Print lives, scores data to screen, set position of number

	xwing.setXc(xMax/2);
	xwing.setY(yMax-xwing.getHeight()-selected.getHeight());
	xwing.draw();

	levelMap();	// Get dimensions of alien array based on level (set vars "rows" and "columns")

	NevaKey.resize(rows*columns);
	num.resize(rows*columns);
	ans.resize(rows*columns);

	// Not a fan
	// Initialise NevaKey
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			NevaKey[getIndex(i,j)].setState(true);
		}
	}
	// End not a fan

	operate();	// Get equations to solve
	setNumAliens();	// Set numbers on aliens in array
	setTypeAliens();
	setPosAliens();	// Set positions of aliens in array
	printAliens();	// Print aliens in array

	tryCounter = 0;	// Initialise
	gameAttemptFlag = true;	// Initialise

	while(gameAttemptFlag)
	{
		// Print data to screen
		printData();
		// Get key from user
		key = tools::getkey();
		// Handle input
		if (key >= 0 && key <= 999)
		{
			eventNum(key);
		}
		else if (key == LEFT)
		{
			eventLeft();
		}
		else if (key == RIGHT)
		{
			eventRight();
		}
		else if (key == SPACE)
		{
			eventSpace();
		}
		// Print data to screen
		//printData();
	}
	if (success)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void math::gameEnding()
{
	//
}

void math::eventNum(int key)
{
	selected.erase();
	selected.setNum(key);
	selected.draw();
}

void math::eventLeft()
{
	if (xwing.getX()>=2)
	{
		xwing.erase();
		xwing.setX(xwing.getX()-2);
		xwing.draw();
	}
}

void math::eventRight()
{
	if (xwing.getX()+xwing.getWidth()<=xMax-2)
	{
		xwing.erase();
		xwing.setX(xwing.getX()+2);
		xwing.draw();
	}
}

void math::eventSpace()
{
	bool aligned = isInline();
	xwing.fire(xwing.getY()-NevaKey[iAlign].getY()-NevaKey[iAlign].getHeight());
	if (aligned)
	{
		if (isCorrect())
		{
			NevaKey[getIndex(iAlign, jAlign)].kill();
			scoreUp();	// Increment score
			if (isRowDestroyed())
			{
				eraseAliens();
				shiftAliensDown();
				printAliens();
			}
			if (isAliensDead())
			{
				success = true;
				gameAttemptFlag = false;
				printLevelUp();
			}
		}
		else
		{
			if (isTriesExpired())
			{
				xwing.explode();
				success = false;
				gameAttemptFlag = false;
				printGameOver();
			}
			else
			{
				eraseAliens();
				shiftAliensDown();
				printAliens();
			}
		}
	}
}

void math::operate()
{
	int maxint = 10;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			num[getIndex(i, j)] = rand() % maxint;
			ans[getIndex(i, j)] = set * num[getIndex(i, j)];
		}
	}
}

void math::printData()
{
	// Print data
	selected.setX(0);
	selected.setY(yMax-selected.getHeight());
	selected.draw();
	tools::printw(yMax-1, xMax/2-11, "Score: ");
	tools::printw(yMax-1, xMax/2-4, getScore());
	tools::printw(yMax-1, xMax/2+1, "Level: ");
	tools::printw(yMax-1, xMax/2+8, getLevel());
	// Print alien minimap
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<columns; j++)
		{
			if (NevaKey[getIndex(i, j)].isAlive())
			{
				tools::printw(rows-i, j, '@');
			}
			else
			{
				tools::printw(rows-i, j, ' ');
			}
		}
	}
}

int math::selectNum(number& num, int max)
{

	tools::printw(num.getY()  , num.getXc()-num.getWidth()-6, "  x                 x  ");
	tools::printw(num.getY()+1, num.getXc()-num.getWidth()-6, " xx                 xx ");
	tools::printw(num.getY()+2, num.getXc()-num.getWidth()-6, "xxx                 xxx");
	tools::printw(num.getY()+3, num.getXc()-num.getWidth()-6, " xx                 xx ");
	tools::printw(num.getY()+4, num.getXc()-num.getWidth()-6, "  x                 x  ");

	int key = RIGHT;	// Not ENTER
	int pos = 0;
	num.setNum(pos);
	num.draw();

	while (key != ENTER)
	{
		key = tools::getkey();
		if (key == RIGHT)
		{
			if (pos == max)
			{
				pos = 0;
			}
			else
			{
				pos ++;
			}
		}
		else if (key == LEFT)
		{
			if (pos == 0)
			{
				pos == max;
			}
			else
			{
				pos --;
			}
		}
		num.erase();	// Erase number
		num.setNum(pos);	// Set number
		num.setXc(xMax/2);	// Adjust position if necessary
		num.draw();	// Draw number
	}
	return pos;
}

bool math::isInline()
{
	iAlign = -1;
	jAlign = -1;
	// Check which column is in overlap
	for (int j=0; j<columns; j++)
	{
		int shipCentre = xwing.getXc();
		int alienCentre = NevaKey[getIndex(0, j)].getXc();
		int overlap = shipCentre - alienCentre;
		if (overlap < NevaKey[getIndex(0, j)].getWidth()/2 && overlap > -NevaKey[getIndex(0, j)].getWidth()/2)
		{
			jAlign = j;	// Should only ever be at most one alien in line with ship
		}
	}
	// Check which row is at the bottom (visible to the ship)
	for (int i=rows-1; i>=0; i--)
	{
		if (NevaKey[getIndex(i, jAlign)].isAlive())
		{
			iAlign = i;
		}
	}
	if (iAlign != -1 && jAlign != -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string math::getInitials()
{
	tools::clearw();
	tools::printw(yMax/2-2, xMax/2-21, "Congratulations! You got a new high score!");
	tools::printw(yMax/2, xMax/2-23, "Enter your 3 letter initials, then press enter.");
	// Get initials from user
	char init[4];
	for (int i=0; i<3; i++)
	{
		init[i] = tools::getCharacter();
		tools::printw(yMax/2+2, xMax/2-1+i, init[i]);
	}
	// Wait until enter is pressed
	int key = 0;
	while (key != ENTER)
	{
		key = tools::getkey();
	}
	return init;
}

void math::levelMap()
{
	if (getLevel() >= 0 && getLevel() <= 3)
	{
		columns = 1+2*getLevel();	// Increment x dimension in lots of two
		rows = 1;	// Y dimension stays the same
	}
	else if (getLevel() > 3)
	{
		columns = 7;	// X dimension stays the same
		rows = getLevel()-2;	// Increment y dimension by one row
	}
}

void math::setNumAliens()
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			NevaKey[getIndex(i, j)].setNum(set, num[getIndex(i, j)]);	// Set numbers on aliens
		}
	}

}

void math::setPosAliens()
{
	int w = NevaKey[0].getWidth()+4;
	int h = NevaKey[0].getHeight()+1;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			NevaKey[getIndex(i, j)].setXc(xMax/2-(columns-1)*w/2+j*w);
			NevaKey[getIndex(i, j)].setY(h-i*h);
		}
	}
}

void math::setTypeAliens()
{
	int type = 1;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			NevaKey[getIndex(i, j)].setType(type);
		}
		if (type == 4)
		{
			type = 1;
		}
		else
		{
			type ++;
		}
	}
}

void math::printAliens()
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			NevaKey[getIndex(i, j)].draw();
		}
	}
}

void math::eraseAliens()
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			NevaKey[getIndex(i, j)].erase();
		}
	}
}

void math::shiftAliensDown()
{
	int h = NevaKey[0].getHeight();
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			NevaKey[getIndex(i, j)].setY(NevaKey[getIndex(i, j)].getY()+(yMax-15-h)/4);	// Shift alien down a third of the play screen
		}
	}
	tryCounter ++;
}

bool math::isCorrect()
{
	if (selected.getNum() == ans[getIndex(iAlign, jAlign)])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool math::isAliensDead()
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			if (NevaKey[getIndex(i, j)].isAlive())
			{
				return false;
			}
		}
	}
	return true;
}

int math::getIndex(int i, int j)
{
	return i*columns+j;
}

bool math::isTriesExpired()
{
	int numAlive = 0;
	for (int i=0; i<rows; i++)
	{
		numAlive = 0;
		for (int j=0; j<columns; j++)
		{
			if (!NevaKey[getIndex(i, j)].isAlive())
			{
				numAlive ++;
			}
		}
		if (numAlive == columns)
		{
			tryCounter ++;
		}
	}
	if (tryCounter == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool math::isRowDestroyed()
{
	int counter = 0;
	for (int j=0; j<columns; j++)
	{
		if (!NevaKey[getIndex(iAlign, j)].isAlive())
		{
			counter ++;
		}
	}
	if (counter == columns)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void math::printGameOver()
{
	int x = xMax/2 - 25;
	int y = yMax/2 - 2;
	tools::clearw();
	tools::printw(y  , x, " ###   ###  #   # #####     ###  #   # ##### #### ");
	tools::printw(y+1, x, "#     #   # ## ## #        #   # #   # #     #   #");
	tools::printw(y+2, x, "#  ## ##### # # # #####    #   # #   # ##### #### ");
	tools::printw(y+3, x, "#   # #   # #   # #        #   #  # #  #     #   #");
	tools::printw(y+4, x, " ###  #   # #   # #####     ###    #   ##### #   #");
	tools::delay(1000);
}

void math::printLevelUp()
{
	int x = xMax/2 - 22;
	int y = yMax/2 - 2;
	tools::clearw();
	tools::printw(y  , x, "#     ##### #   # ##### #        #   # #### ");
	tools::printw(y+1, x, "#     #     #   # #     #        #   # #   #");
	tools::printw(y+2, x, "#     ##### #   # ##### #        #   # #### ");
	tools::printw(y+3, x, "#     #      # #  #     #        #   # #    ");
	tools::printw(y+4, x, "##### #####   #   ##### #####     ###  #    ");
	tools::delay(1000);
}