#include "Pawn.h"

Pawn::Pawn(boardSide val, int posX, int posY)
{
	info.side = val;
	info.coords.x = posX;
	info.coords.y = posY;

	if(val == WHITE)
	{
		info.piece = w_PAWN;
	}
	else
	{
		info.piece = b_PAWN;
	}
}

bool Pawn::validateMove(coordinate oldCoord, coordinate newCoord)
{
	std::cout << "pawn" << std::endl;
	return true;
}
