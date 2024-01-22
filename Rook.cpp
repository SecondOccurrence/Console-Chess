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

std::vector<coordinate> Rook::fetchMoves(coordinate startingPos)
{
	return std::vector<coordinate>{};
}

bool Rook::validateMove(coordinate oldCoords, coordinate newCoords)
{
	return false;
}
