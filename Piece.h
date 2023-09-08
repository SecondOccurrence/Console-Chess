#pragma once
#include "PieceInfo.h"

class Piece
{
public:
	Piece();
	int getX() const;
	int getY() const;
	PieceInfo getPieceInfo();

protected:
	PieceInfo info;
};