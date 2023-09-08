#include "Queen.h"

Queen::Queen(bool val, int posX, int posY)
{
	side = val; //assigns t/f. t=white, f=black
	position[0] = posX;
	position[1] = posY;
}
