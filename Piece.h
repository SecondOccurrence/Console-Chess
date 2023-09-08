#pragma once
#include "PieceInfo.h"

class Piece
{
public:
	Piece();
	int getX() const;
	int getY() const;

protected:
	PieceInfo info;
};