#include "Knight.h"

Knight::Knight(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.posX = posX;
	info.posY = posY;

	if(val) // white side
	{
		info.piece = w_KNIGHT;
	}
	else
	{
		info.piece = b_KNIGHT;
	}
}
