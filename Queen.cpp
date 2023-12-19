#include "Queen.h"

Queen::Queen(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black	
	info.posX = posX;
	info.posY = posY;

	if(val) // white side
	{
		info.piece = w_QUEEN;
	}
	else
	{
		info.piece = b_QUEEN;
	}
}
