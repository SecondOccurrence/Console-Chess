#include "GameManager.h"

GameManager::GameManager()
{
	blackSide = new Player(false);
}

void GameManager::displayBoard()
{
	//loop through each piece
		//note their position
	//display

	//perhaps tie each object type with numeric value
}

bool GameManager::run()
{
	bool gameEnded = false;

	displayBoard();

	//move pieces, return value
		//checkmate, clear for next move
	
	return gameEnded;
}