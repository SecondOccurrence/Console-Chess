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

std::vector<std::vector<coordinate>> King::fetchMoves(coordinate startingPos)
{
	return std::vector<std::vector<coordinate>>{};
}
