#include "Rook.h"

Rook::Rook(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.posX = posX;
	info.posY = posY;

	if(val) // white side
	{
		info.piece = w_ROOK;
	}
	else
	{
		info.piece = b_ROOK;
	}
}
