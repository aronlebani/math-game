/*
main.cpp

Aron Lebani
29 December 2015
*/

#include "../include/math.h"
#include "../include/menu.h"
#include "../include/tools.h"

int main()
{
	// Game variables
	int lives = 3;	// Number of lives
	int nScores = 3;	// Number of scores to store in High Scores

	// Initialise window
	tools::initw();

	// Maximise window
	tools::maximisew();

	// Define game types
	math multiplication("../score/scores.dat");

	// Read scores from file
	multiplication.fReadScores();
	
	// Run game
	menu(multiplication);

	// End window
	tools::endw();

	// Write scores back to file
	multiplication.fWriteScores();

	return 0;
}