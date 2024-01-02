#include "Piece.h"

#include <iostream>

Piece::Piece()
{
	info.side = WHITE;
	info.piece = w_PAWN;
	info.posX = 0;
	info.posY = 0;
}

int Piece::getX() const
{
	return info.posX;
}

int Piece::getY() const
{
	return info.posY;
}

PieceInfo Piece::getPieceInfo()
{
	return info;
}
