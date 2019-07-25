/*
arcade.h

Aron Lebani
27 March 2016
*/

#ifndef ARCADE_H

#define ARCADE_H

#include <string>
#include <fstream>

#define N_SCORES 3	/* The number of high scores to be stored */

class arcade
{
public:
	arcade(std::string file);
	// Initialises the level to zero
	// Use this constructor if lives are not being used

	arcade(int numLives, std::string file);
	// Initialises the number of lives, numLives
	// Initialises the level to zero
	// Use this constructor if lives are being used

	void play();
	// Plays the game

	void fReadScores();
	// Read scores from file and save into memory

	void fWriteScores();
	// Write scores from memory into file

private:
	int lives;
	// Store the number of remaining lives

	int score;
	// Store the current score

	int param;
	// Store an extra parameter to add to the scores list

	int level;
	// Store the current level

	int highScore[N_SCORES];
	// Store higest scores

	std::string highUser[N_SCORES];
	// Store user names of highest scores

	int scoreParam[N_SCORES];
	// An extra parameter that is added to the high scores list
	// Use this to append any other information to the high scores list

	bool gameState;
	// Boolean data type is true while game is being played, and false otherwise

	std::string fileName;
	// Name of file to store high score data

	std::fstream scoreFile;
	// IO stream for reading and writing to file

	void livesDown();
	// Decrements number of lives by 1
	// If number of lives decreases to zero, gameOver() is called to end the game

	void levelUp();
	// Increments the level by 1
	// Level starts at zero

	void gameOver();
	// Ends game
	// Called automatically if lives reaches zero
	// Sets state to false

	bool isHighScore();
	// Check if current score is a high score or not
	// Returns true if it is, false if not

	void updateScore(std::string initial);
	// Updates the high scores list with a new high score

protected:
	virtual void gameBeginning();
	// Implements anything the user wants to do before the game starts

	virtual bool gameAttempt(int lvl);
	// Implements an attempt at level "level" of the game
	// If the level is completed, return true
	// Function is then called again for the next level
	// If the user fails before the level is complete, return false
	// Function is then called again for the same level

	virtual void gameEnding();
	// Implements anything the user wants to do after the game ends

	virtual std::string getInitials();
	// Get initials from user to update high score with

	int getHighScore(int pos);
	// Gives access to highScore array, element "pos"

	std::string getHighUser(int pos);
	// Gives access to highUser array, element "pos"

	int getScoreParam(int pos);
	// Gives access to scoreParam array, element "pos"

	void setParam(int p);
	// Sets "scoreParam" element "pos" to "param"

	void scoreUp();
	// Increments the score by 1

	void livesUp();
	// Increments number of lives by 1

	int getLives();
	// Returns the current number of lives left

	int getScore();
	// Returns the current score

	int getLevel();
	// Returns the current level
	// Level starts at zero
};

#endif