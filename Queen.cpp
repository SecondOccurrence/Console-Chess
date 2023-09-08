#include "Queen.h"

Queen::Queen(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.piece = QUEEN;
	info.posX = posX;
	info.posY = posY;
}
