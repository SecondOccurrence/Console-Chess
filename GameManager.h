#pragma once
#include "Player.h"

class GameManager
{
public:
	GameManager();

	void displayBoard();
	bool run();
private:

	Player blackSide;
};
