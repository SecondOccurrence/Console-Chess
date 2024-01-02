#include "King.h"

King::King(boardSide val, int posX, int posY)
{
	info.side = val;
	info.posX = posX;
	info.posY = posY;

	if(val == WHITE)
	{
		info.piece = w_KING;
	}
	else
	{
		info.piece = b_KING;
	}
}
