#include "King.h"

King::King(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.piece = KING;
	info.posX = posX;
	info.posY = posY;
}
