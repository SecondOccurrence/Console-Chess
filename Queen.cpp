#include "Queen.h"

Queen::Queen(boardSide val, int posX, int posY)
{
	info.side = val;	
	info.coords.x = posX;
	info.coords.y = posY;

	if(val == WHITE)
	{
		info.piece = w_QUEEN;
	}
	else
	{
		info.piece = b_QUEEN;
	}
}

bool Queen::validateMove(coordinate oldCoords, coordinate newCoords)
{
	std::cout << "queen" << std::endl;
	return false;
}
