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

// TODO:
//
// change piece w_... b_... to just ... as every piece object has a side attribute.
// can compare using PieceInfo.side
