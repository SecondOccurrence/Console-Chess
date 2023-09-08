#include <vector>

#include "GameManager.h"

GameManager::GameManager()
{
	blackSide = new Player(false);

	whiteSide = new Player(true);
}

void GameManager::displayBoard()
{
	std::vector<PieceInfo> whitePieces = whiteSide.getPiecePositions();

	//display

	//perhaps tie each object type with numeric value
}

bool GameManager::run()
{
	bool gameEnded = false;
	std::string move;

	displayBoard();

	move = whiteSide.getMove();


	//move pieces, return value
		//checkmate, clear for next move
	
	return gameEnded;
}