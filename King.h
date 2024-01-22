#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(boardSide val, int posX, int posY);

	std::vector<coordinate> fetchMoves(coordinate startingPos) override;
	bool validateMove(coordinate oldCoord, coordinate newCoord) override;	
};
