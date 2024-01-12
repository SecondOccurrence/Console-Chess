#include "King.h"

King::King(boardSide val, int posX, int posY)
{
	info.side = val;
	info.coords.x = posX;
	info.coords.y = posY;

	if(val == WHITE)
	{
		info.piece = w_KING;
	}
	else
	{
		info.piece = b_KING;
	}
}

bool King::validateMove(coordinate oldCoords, coordinate newCoords)
{
	std::cout << "king" << std::endl;
	return false;
}
