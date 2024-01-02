#include "Pawn.h"

Pawn::Pawn(boardSide val, int posX, int posY)
{
	info.side = val;
	info.posX = posX;
	info.posY = posY;

	if(val == WHITE)
	{
		info.piece = w_PAWN;
	}
	else
	{
		info.piece = b_PAWN;
	}
}
