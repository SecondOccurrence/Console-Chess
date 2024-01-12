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

bool Knight::validateMove(coordinate oldCoords, coordinate newCoords)
{
	std::cout << "knight" << std::endl;
	return false;
}
