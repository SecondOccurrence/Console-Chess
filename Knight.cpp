#include "Knight.h"

Knight::Knight(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.piece = KNIGHT;
	info.posX = posX;
	info.posY = posY;
}
