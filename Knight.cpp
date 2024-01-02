#include "Knight.h"

Knight::Knight(boardSide val, int posX, int posY)
{
	info.side = val;
	info.posX = posX;
	info.posY = posY;

	if(val == WHITE)
	{
		info.piece = w_KNIGHT;
	}
	else
	{
		info.piece = b_KNIGHT;
	}
}
