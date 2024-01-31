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

std::vector<std::vector<coordinate>> Queen::fetchMoves(coordinate startingPos)
{
	return std::vector<std::vector<coordinate>>{};
}

bool Queen::validateMove(coordinate targetCoord, std::vector<coordinate>* movePaths)
{
	return false;
}


