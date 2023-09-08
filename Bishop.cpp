#include "Bishop.h"

Bishop::Bishop(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.piece = BISHOP;
	info.posX = posX;
	info.posY = posY;
}
