/*
tools.cpp

Aron Lebani
9 March 2016
*/

#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>


#ifdef _WIN32

#include "curses.h"

#else

#include <ncurses.h>

#endif


#include "../include/tools.h"

#define KEY_RETURN '\n'
#define KEY_SPACE ' '

void tools::cont(int y, int x)
{
	printw(y, x, "Press enter to continue");
	getch();
}

void tools::clearw()
{
	clear();
}

void tools::initw()
{
	initscr();	// Initialise window
	noecho();	// Don't echo any keypresses
	curs_set(FALSE);	// Don't display a cursor
	cbreak();	// Disable line buffering
	keypad(stdscr, TRUE);	// Enable reading of arrow keys
}

void tools::maximisew()
{
	#ifdef _WIN32

	//bool win = ConLibSetWinSize();

	Console.WindowWidth = Console.LargestWindowWidth;
	Console.WindowHeight = Console.LargestWindowHeight;

	#endif
}

void tools::endw()
{
	endwin();
}

void tools::getmaxw(int& yMax, int& xMax)
{
	getmaxyx(stdscr, yMax, xMax);
}

void tools::printw(int y, int x, std::string data)
{
	mvprintw(y, x, data.c_str());
	refresh();
}

void tools::printw(int y, int x, int num)
{
	mvprintw(y, x, "%d", num);
	refresh();
}

void tools::printw(int y, int x, char a)
{
	mvprintw(y, x, "%c", a);
	refresh();
}

void tools::refreshw()
{
	refresh();
}

int tools::getnum()
{
	int a;
	std::cin >> a;
	return a;
}

void tools::delay(int ms)
{
	//delays by ms milli seconds
	int num_clicks = CLOCKS_PER_SEC * ms / 1000;
	time_t prev_time = clock();
	time_t clicks;
	do
	{
		clicks = clock() - prev_time;
	}
	while (clicks < num_clicks);
}

int tools::getkey()
{
	int key;
	key = getch();
	if (key == KEY_LEFT)
	{
		return -2;
	}
	else if (key == KEY_RIGHT)
	{
		return -3;
	}
	else if (key == KEY_UP)
	{
		return -4;
	}
	else if (key == KEY_DOWN)
	{
		return -5;
	}
	else if (key == KEY_RETURN)
	{
		return -6;
	}
	else if (key == KEY_SPACE)
	{
		return -7;
	}
	else if (key >= 48 && key <= 57)
	{
		int num[] = {0, 0, 0};
		num[2] = key - 48;	// Fill from end
		for (int i=0; i<3; i++)
		{
			key = getch();
			if (key != KEY_RETURN)
			{
				// Shift values down an index
				int temp[3];
				for (int j=0; j<2; j++)
				{
					temp[j] = num[j+1];
				}
				for (int j=0; j<3; j++)
				{
					num[j] = temp[j];
				}
				// Put new key in end of array
				num[2] = key - 48;
			}
			else
			{
				i = 3;	// Break out of loop
			}
		}
		return 100*num[0] + 10*num[1] + num[2];
	}
	else
	{
		return -1;
	}
	return key;
}

char tools::getCharacter()
{
	return getch();
}