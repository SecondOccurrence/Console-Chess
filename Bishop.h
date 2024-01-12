#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(boardSide val, int posX, int posY);

	bool validateMove(coordinate oldCoord, coordinate newCoord);
};
