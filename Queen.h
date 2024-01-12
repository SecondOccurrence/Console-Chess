#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(boardSide val, int posX, int posY);

	bool validateMove(coordinate oldCoord, coordinate newCoord);
};
