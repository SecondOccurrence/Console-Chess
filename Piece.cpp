#include "Piece.h"

Piece::Piece()
{
	info.side = true; //white
	info.piece = PAWN;
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
