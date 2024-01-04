#include "GameManager.h"

#include <vector>

GameManager::GameManager()
{
	whiteSide = Player(WHITE);
	blackSide = Player(BLACK);
	sideToMove = WHITE;
}

void GameManager::displayBoard()
{
	const char pieces[13] = {'p', 'n', 'b', 'r', 'q', 'k', 'P', 'N', 'B', 'R', 'Q', 'K', '.'};

	int yAxis = 8;
	std::cout << std::endl; //formatting
	std::cout << "           BLACK       " << std::endl;
	std::cout << "    +-----------------+" << std::endl;
	for (int i = 7; i >= 0; i--)
	{
		std::cout << "  " << yAxis << " "; //print out y-axis grid number
		yAxis--;
		for (int j = 9; j >= 0; j--)
		{
			if (j == 0 || j == 9)
			{
				std::cout << "| ";
				continue;
			}
			std::cout << pieces[board.getPieceAtPos(j - 1, i)] << " "; //print out board position
		}
		std::cout << std::endl;
	}
	std::cout << "    +-----------------+" << std::endl;
	std::cout << "      a b c d e f g h" << std::endl;
	std::cout << "           WHITE      " << std::endl;
}

bool GameManager::run()
{
	bool gameEnded = false;
	std::string move;

	std::vector<PieceInfo> whitePieces = whiteSide.getPiecePositions();
	std::vector<PieceInfo> blackPieces = blackSide.getPiecePositions();

	board.updateBoard(whitePieces, blackPieces);
	displayBoard();

	//std::cout << sideToMove << std::endl;
	if(sideToMove == WHITE)
	{
		move = whiteSide.performMove();
		sideToMove = BLACK;
	}
	else
	{
		move = blackSide.performMove();
		sideToMove = WHITE;
	}

	//move pieces, return value
		//checkmate, clear for next move
	
	return gameEnded;
}
