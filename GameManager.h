#pragma once

#include "Player.h"
#include "Board.h"
#include "BoardSideEnum.h"

class GameManager
{
public:
	GameManager();

	bool run();
	void displayBoard();

	void readFENBoard();
private:
	Board board;
	boardSide sideToMove;
	Player whiteSide;
	Player blackSide;

	std::string getFENString();
	void performMove(boardSide moveSide, std::string move);
};
