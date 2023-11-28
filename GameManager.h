#pragma once
#include "Player.h"
#include "Board.h"

class GameManager
{
public:
	GameManager();

	void displayBoard();
	bool run();
private:
	Board board;
	Player whiteSide;
	Player blackSide;
};
