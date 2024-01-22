#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(boardSide val, int posX, int posY);

	std::vector<coordinate> fetchMoves(coordinate startingPos) override;
	bool validateMove(coordinate oldCoord, coordinate newCoord) override;	
};
