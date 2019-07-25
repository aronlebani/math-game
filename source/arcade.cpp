/*
arcade.cpp

Aron Lebani
27 March 2016
*/

#include <string>
#include <fstream>

#include "../include/arcade.h"

arcade::arcade(std::string file)
{
	fileName = file;
	level = 0;
}

arcade::arcade(int numLives, std::string file)
{
	lives = numLives;
	fileName = file;
	level = 0;
}

void arcade::play()
{
	gameBeginning();
	gameState = true;
	score = 0;
	level = 0;
	bool success;
	while (gameState)
	{
		success = gameAttempt(level);
		if (success)
		{
			levelUp();
		}
		else
		{
			gameState = false;
		}
	}
	gameEnding();
	if (isHighScore())
	{
		std::string init = getInitials();
		updateScore(init);
	}
}

void arcade::fReadScores()
{
	// Read score data from file
	scoreFile.open(fileName.c_str(), std::ios::in);
	int i;
	for (i = 0; i < N_SCORES; i++)
	{
		scoreFile >> highUser[i];
		scoreFile >> highScore[i];
		scoreFile >> scoreParam[i];
	}
	scoreFile.close();
}

void arcade::fWriteScores()
{
	// Write score data to file
	scoreFile.open(fileName.c_str(), std::ios::out);
	int i;
	for (i = 0; i < N_SCORES; i++)
	{
		scoreFile << highUser[i] << '\n';
		scoreFile << highScore[i] << '\n';
		scoreFile << scoreParam[i] << '\n';
	}
	scoreFile.close();
}

void arcade::livesDown()
{
	lives --;
	if (lives == 0)
	{
		gameOver();
	}
}

void arcade::levelUp()
{
	level ++;
}

void arcade::gameOver()
{
	gameState = false;
}

bool arcade::isHighScore()
{
	if (score > highScore[N_SCORES-1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void arcade::updateScore(std::string initial)
{
	// Calculate position
	int pos;
	if (score > highScore[0])
	{
		pos = 0;
	}
	else if (score > highScore[1])
	{
		pos = 1;
	}
	else
	{
		pos = 2;
	}
	// Shift Scores down
	std::string tempUser[N_SCORES];
	int tempScore[N_SCORES];
	int tempScoreParam[N_SCORES];
	int i;
	for (i = pos; i < N_SCORES; i++)
	{
		if (i+1 < N_SCORES)
		{
			tempUser[i+1] = highUser[i];
			tempScore[i+1] = highScore[i];
			tempScoreParam[i+1] = scoreParam[i];
		}
	}
	for (i = pos; i < N_SCORES; i++)
	{
		highUser[i] = tempUser[i];
		highScore[i] = tempScore[i];
		scoreParam[i] = tempScoreParam[i];
	}
	// Update high scores
	highUser[pos] = initial;
	highScore[pos] = score;
	scoreParam[pos] = param;
}

void arcade::gameBeginning()
{
	//
}

bool arcade::gameAttempt(int lvl)
{
	return true;
}

void arcade::gameEnding()
{
	//
}

std::string arcade::getInitials()
{
	return "aaa";
}

int arcade::getHighScore(int pos)
{
	return highScore[pos];
}

std::string arcade::getHighUser(int pos)
{
	return highUser[pos];
}

int arcade::getScoreParam(int pos)
{
	return scoreParam[pos];
}

void arcade::setParam(int p)
{
	param = p;
}

void arcade::scoreUp()
{
	score ++;
}

void arcade::livesUp()
{
	lives ++;
}

int arcade::getLives()
{
	return lives;
}

int arcade::getScore()
{
	return score;
}

int arcade::getLevel()
{
	return level;
}