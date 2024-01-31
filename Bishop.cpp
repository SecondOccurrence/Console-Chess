#include "Bishop.h"

Bishop::Bishop(boardSide val, int posX, int posY)
{
	info.side = val;
	info.coords.x = posX;
	info.coords.y = posY;
	
	if(val == WHITE)
	{
		info.piece = w_BISHOP;
	}
	else
	{
		info.piece = b_BISHOP;
	}
}

std::vector<std::vector<coordinate>> Bishop::fetchMoves(coordinate startingPos)
{
	return {};
}

bool Bishop::validateMove(coordinate targetCoord, std::vector<coordinate>* movePaths)
{
	return false;
}
