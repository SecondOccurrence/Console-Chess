#pragma once
#include "Piece.h"

#include <vector>
#include <iostream>

class Player
{
public:
	Player();
	Player(bool isWhite);
	~Player();

	std::string getMove();
	bool validateMove(std::string playerMove);

private:
	bool whiteSide;
	std::vector<Piece*> pieces;
};
