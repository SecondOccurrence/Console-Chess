#include "Piece.h"

#include <iostream>

Piece::Piece()
{
	info.side = WHITE;
	info.piece = w_PAWN;
	info.coords.x = 0;
	info.coords.y = 0;
}

int Piece::getX() const
{
	return info.coords.x;
}

int Piece::getY() const
{
	return info.coords.y;
}

PieceInfo Piece::getPieceInfo()
{
	return info;
}
