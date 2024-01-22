#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(boardSide val, int posX, int posY);

	std::vector<coordinate> fetchMoves(coordinate startingPos) override;
	bool validateMove(coordinate oldCoord, coordinate newCoord);
	
};
