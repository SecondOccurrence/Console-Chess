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
		std::cout << "  " << yAxis << " "; // print out y-axis grid number
		yAxis--;

		int boardColumns = 9;		
		for(int j = 0; j <= boardColumns; j++)
		{
			if(j == 0 || j == boardColumns)
			{
				std::cout << "| ";
				continue;
			}
			std::cout << pieces[board.getPieceAtPos(j - 1, i)] << " ";
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
		move = whiteSide.getMove();
		performMove(sideToMove, move);
		sideToMove = BLACK;
	}
	else
	{
		move = blackSide.getMove();
		performMove(sideToMove, move);
		sideToMove = WHITE;
	}

	//move pieces, return value
		//checkmate, clear for next move
	
	return gameEnded;
}

void GameManager::performMove(boardSide moveSide, std::string move)
{
	coordinate initialCoords;
	initialCoords.x = (int)move[0] - 96; // converts char to its position on the board grid (1-8)
	initialCoords.y = (int)move[1] - 48; // convert char number to ascii number equivalent
	
	coordinate moveCoords;
	moveCoords.x = (int)move[2] - 96;
	moveCoords.y = (int)move[3] - 48;

	if(moveSide == WHITE)
	{
		whiteSide.assignNewPosition(initialCoords, moveCoords);
	}
	else
	{
		blackSide.assignNewPosition(initialCoords, moveCoords);
	}
}
