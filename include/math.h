/*
math.h

Aron Lebani
28 March 2016
*/

#ifndef MATH_H

#define MATH_H

#include <vector>

#include "arcade.h"
#include "number.h"
#include "ship.h"
#include "alien.h"

class math : public arcade
{
public:
	math(std::string file);
	// Constructor

	void scores();
	// Displays high scores on the screen

	void instructions();
	// Displays the instructions on the screen

private:
	ship xwing;
	// Ship to be used by player

	std::vector<alien> NevaKey;
	// Alien array

	std::vector<int> num;
	// Number in times tables problems

	std::vector<int> ans;
	// Answer to times tables problems

	int set;
	// The set of times tables to be used by player

	int rows;
	// Number of rows of aliens

	int columns;
	// Number of columns of aliens

	number selected;
	// Currently selected number

	bool success;
	// Stores state of whether an individual attempt at the game is successful or not

	int xMax;
	// Width of window

	int yMax;
	// Height of window

	int tryCounter;
	// Keeps track of the number of times the aliens have moved down

	int iAlign;
	// Element of alien array in x direction that is inline with the ship

	int jAlign;
	// Element of alien array in y direction that is inline with the ship

	bool gameAttemptFlag;
	// True if game attempt is in progress, when game ends because of
	// level completion or failure, set to false

	virtual void gameBeginning();
	// Sets up bits and pieces for game
	// Gets input from user on what set of times tables to play

	virtual bool gameAttempt(int lvl);
	// Implements an attempt at the game
	// If all aliens are destroyed before all lives are lost, success = true
	// If all allowed tries are exceeded before destroying all aliens, success = false

	virtual void gameEnding();
	// Prints users final score to the screen after the game ends

	void eventNum(int key);
	// Handles the event where a number is entered at the keyboard

	void eventLeft();
	// Handles the event where the left arrow is entered at the keyboard

	void eventRight();
	// Handles the event where the right arrow key is entered at the keyboard

	void eventSpace();
	// Handles the event where the space key is entered at the keyboard

	void operate();
	// Returns ans = set * num
	// The function srand() must be called with an appropriate seed before using this function

	void printData();
	// Prints lives and current score data to screen
	// Draws number "num" on screen

	int selectNum(number& num, int max);
	// Scrolls through numbers using up and down arrow keys
	// Returns selected number
	// Resets to zero after number reaches "max"

	bool isInline();
	// Checks if ship is inline with alien
	// Returns true if so, else false
	// Sets i and j to the coords of the alien that is inline

	std::string getInitials();
	// Gets initaials from the user to update high score with

	void levelMap();
	// Sets parameters "rows" and "columns" to the dimensions of the array of aliens based on the current level

	void setNumAliens();
	// Sets numbers on aliens in array

	void setPosAliens();
	// Set positions of aliens in array

	void setTypeAliens();
	// Sets the type of the aliens in the array

	void printAliens();
	// Prints the aliens in a grid with their respective equations

	void eraseAliens();
	// Erases aliens in array

	void shiftAliensDown();
	// Shifts all aliens down a third of the play screen

	bool isCorrect();
	// Checks if answer is correct

	bool isAliensDead();
	// Returns true if all aliens are dead, else returns false

	int getIndex(int i, int j);
	// Returns the linear index of element (i,j) in a 2d array

	bool isTriesExpired();
	// Checks if aliens have reached the bottom of the screen, returns true if so, else false

	bool isRowDestroyed();
	// Checks if entire bottom row is destoryed, returns true if so, else false

	void printGameOver();
	// Prints a "game over" message to the screen

	void printLevelUp();
	// Prints a "level up" message to the screen
};

#endif