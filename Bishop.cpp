#include "Bishop.h"

Bishop::Bishop(boardSide val, int posX, int posY)
{
	info.side = val;
	info.posX = posX;
	info.posY = posY;
	
	if(val == WHITE)
	{
		info.piece = w_BISHOP;
	}
	else
	{
		info.piece = b_BISHOP;
	}
}
