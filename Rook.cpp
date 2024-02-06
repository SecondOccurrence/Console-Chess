#include "Rook.h"

Rook::Rook(boardSide val, int posX, int posY)
{
	info.side = val;
	info.coords.x = posX;
	info.coords.y = posY;

	if(val == WHITE)
	{
		info.piece = w_ROOK;
	}
	else
	{
		info.piece = b_ROOK;
	}
}

CoordinateVec2D Rook::fetchMoves(coordinate startingPos)
{
	return CoordinateVec2D{};
}
