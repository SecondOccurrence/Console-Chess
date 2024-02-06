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

CoordinateVec2D Queen::fetchMoves(coordinate startingPos)
{
	return CoordinateVec2D{};
}


