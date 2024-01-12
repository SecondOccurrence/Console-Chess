#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(boardSide val, int posX, int posY);

	bool validateMove(coordinate oldCoord, coordinate newCoord);
};
