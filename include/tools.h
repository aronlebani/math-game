/*
tools.h

Aron Lebani
9 March 2016
*/

#ifndef TOOLS_H

#define TOOLS_H

#include <string>


#ifdef _WIN32

#include "curses.h"
#include "ConLib.h"

#else

#include <ncurses.h>

#endif


#define LEFT -2
#define RIGHT -3
#define UP -4
#define DOWN -5
#define ENTER -6
#define SPACE -7

namespace tools
{
	void cont(int y, int x);
	// Waits for user input before continuing
	// Prints message at coord (x,y)

	void clearw();
	// Executes the system command to clear the terminal

	void initw();
	// Initialise screen

	void maximisew();
	// Maximises the window
	// Only works for windows OS

	void endw();
	// Restore normal terminal behaviour

	void getmaxw(int& yMax, int& xMax);
	// Get x and y extent of window
	// o--------> x
	// |
	// |
	// |
	// v
	// y

	void printw(int y, int x, std::string data);
	// Print a string to the window at coord (x,y)

	void printw(int y, int x, int num);
	// Print an int to the window at coord (x,y)

	void printw(int y, int x, char a);
	// Print a char tot he window at coord (x,y)

	void refreshw();
	// Refresh window
	// Call after drawing to window

	int getnum();
	// Get number from user
	// Hit return to finalise number input

	void delay(int ms);
	// Delay by ms milliseconds

	int getkey();
	// Get left/right/up/down arrow key or number key or enter key or space key from user
	// If a number key is entered, press enter to finalise number entry to allow for multiple digit numbers
	// Macros defined for respective keys:
	// LEFT
	// RIGHT
	// UP
	// DOWN
	// ENTER
	// SPACE
	// Returns -1 if anything else is entered
	// Numbers must be less than or equal to 3 digits long

	char getCharacter();
	// Gets a single character from the user
}

#endif