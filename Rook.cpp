#include "Rook.h"

Rook::Rook(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.piece = ROOK;
	info.posX = posX;
	info.posY = posY;
}
