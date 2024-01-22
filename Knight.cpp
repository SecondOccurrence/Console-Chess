#include "Knight.h"

Knight::Knight(boardSide val, int posX, int posY)
{
	info.side = val;
	info.coords.x = posX;
	info.coords.y = posY;

	if(val == WHITE)
	{
		info.piece = w_KNIGHT;
	}
	else
	{
		info.piece = b_KNIGHT;
	}
}

std::vector<coordinate> Knight::fetchMoves(coordinate startingPos)
{
	return std::vector<coordinate>{};
}

bool Knight::validateMove(coordinate oldCoords, coordinate newCoords)
{
	return false;
}
