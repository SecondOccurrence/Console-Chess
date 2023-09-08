#include "Pawn.h"

Pawn::Pawn(bool val, int posX, int posY)
{
	info.side = val; //assigns t/f. t=white, f=black
	info.piece = PAWN;
	info.posX = posX;
	info.posY = posY;
}
