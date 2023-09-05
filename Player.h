#pragma once
#include "Piece.h"
#include <vector>

class Player
{
public:
	Player();
	Player(bool isWhite);
	~Player();

	void toMove();

private:
	bool whiteSide;
	std::vector<Piece*> pieces;
};
