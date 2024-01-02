#include "Rook.h"

Rook::Rook(boardSide val, int posX, int posY)
{
	info.side = val;
	info.posX = posX;
	info.posY = posY;

	if(val == WHITE)
	{
		info.piece = w_ROOK;
	}
	else
	{
		info.piece = b_ROOK;
	}
}
