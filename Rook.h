#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(boardSide val, int posX, int posY);

	bool validateMove(coordinate oldCoord, coordinate newCoord);
};
