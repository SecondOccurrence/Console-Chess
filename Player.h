#pragma once
#include "Piece.h"
#include "PieceInfo.h"

#include <vector>
#include <iostream>

class Player
{
public:
	Player();
	Player(bool isWhite);

	std::string getMove();
	bool validateMove(std::string playerMove);
	std::vector<PieceInfo> getPiecePositions();

private:
	bool whiteSide;
	std::vector<Piece> pieces;
};
