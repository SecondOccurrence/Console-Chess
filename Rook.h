#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(boardSide val, int posX, int posY);

	std::vector<coordinate> fetchMoves(coordinate startingPos) override;
	bool validateMove(coordinate oldCoord, coordinate newCoord);
};
