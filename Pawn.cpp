#include "Pawn.h"

Pawn::Pawn(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.posX = posX;
	info.posY = posY;

	if(val) // white side
	{
		info.piece = w_PAWN;
	}
	else
	{
		info.piece = b_PAWN;
	}
}
