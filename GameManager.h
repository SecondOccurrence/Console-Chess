#pragma once

#include "Player.h"
#include "Board.h"
#include "BoardSideEnum.h"

class GameManager
{
public:
	GameManager();

	void displayBoard();
	bool run();
private:
	Board board;
	boardSide sideToMove;
	Player whiteSide;
	Player blackSide;
};
