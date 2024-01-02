#include "Queen.h"

Queen::Queen(boardSide val, int posX, int posY)
{
	info.side = val;	
	info.posX = posX;
	info.posY = posY;

	if(val == WHITE)
	{
		info.piece = w_QUEEN;
	}
	else
	{
		info.piece = b_QUEEN;
	}
}
