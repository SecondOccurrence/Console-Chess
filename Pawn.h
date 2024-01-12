#pragma once
#include "Piece.h"
#include "Coordinate.h"

class Pawn : public Piece
{
public:
	Pawn(boardSide side, int posX, int posY);

	bool validateMove(coordinate oldCoord, coordinate newCoord) override;
};
