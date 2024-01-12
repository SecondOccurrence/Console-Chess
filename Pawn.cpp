#include "Pawn.h"

Pawn::Pawn(boardSide val, int posX, int posY)
{
	info.side = val;
	info.coords.x = posX;
	info.coords.y = posY;

	if(val == WHITE)
	{
		info.piece = w_PAWN;
	}
	else
	{
		info.piece = b_PAWN;
	}
}

bool Pawn::validateMove(coordinate oldCoord, coordinate newCoord)
{
	// NOTE: there is a separate function for treating with piece captures.

	bool valid = true;
	int increment[2]; // [0] is for pieces already moved, [1] is for those not yet moved.
	int initialXPos;

	if(info.side == WHITE)
	{
		increment[0] = 1;
		increment[1] = 2;
		initialXPos = 2;
	}
	else
	{
		increment[0] = -1;
		increment[1] = -2;
		initialXPos = 7;
	}

	if(oldCoord.x != newCoord.x) // pawn can only move on the y axis
	{
		valid = false;
	}
	
	if(info.coords.y == initialXPos) // pawn has not been moved yet. can move 2 squares
	{
		if(oldCoord.y != newCoord.y - increment[0] && oldCoord.y != newCoord.y - increment[1])
		{
			valid = false;
		}
	}
	else
	{
		if(oldCoord.y != newCoord.y - increment[0]) // pawn has been moved, can only move 1 square
		{
			valid = false;
		}
	}

	return valid;
}
