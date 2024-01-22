#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(boardSide side, int posX, int posY);

	std::vector<coordinate> fetchMoves(coordinate startingPos) override;
	bool validateMove(coordinate oldCoord, coordinate newCoord) override;
};
