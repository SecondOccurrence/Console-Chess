#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(boardSide val, int posX, int posY);

	bool validateMove(coordinate oldCoord, coordinate newCoord);
};
