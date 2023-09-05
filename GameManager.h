#pragma once
#include "Piece.h"

class GameManager
{
public:
	GameManager();

	void DisplayBoard();
	bool Run();
private:
	Piece *pieces[];
};
