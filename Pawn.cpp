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

std::vector<std::vector<coordinate>> Pawn::fetchMoves(coordinate startingPos)
{
	std::vector<std::vector<coordinate>> allMoveCoordinates;

	allMoveCoordinates.push_back(std::vector<coordinate>{}); // first vector, regular moves
	allMoveCoordinates.push_back(std::vector<coordinate>{}); // second vector, capture moves

	int increment;
	if(info.side == WHITE)
	{
		increment = 1; // moving up the board
	}
	else
	{
		increment = -1; // moving down the board
	}

	if(startingPos.y <= 7)
	{
		allMoveCoordinates[1].push_back(coordinate{startingPos.x, startingPos.y + increment});

		if(startingPos.y <= 6)
		{
			allMoveCoordinates[1].push_back(coordinate{startingPos.x, startingPos.y + (increment + increment)});
		}

		// capture moves
		if(startingPos.x >= 2)
		{
			allMoveCoordinates[0].push_back(coordinate{startingPos.x - 1, startingPos.y + increment});

			if(startingPos.x <= 7)
			{
				allMoveCoordinates[0].push_back(coordinate{startingPos.x + 1, startingPos.y + increment});
			}
		}
	}
	
	return allMoveCoordinates;
}

bool Pawn::validateMove(coordinate targetCoord, std::vector<coordinate>* movePaths)
{
	// NOTE: there is a separate function for treating with piece captures.

	bool valid = true;
	int increment[2]; // [0] is for pieces already moved, [1] is for those not yet moved.
	int initialYPos;

	if(info.side == WHITE)
	{
		increment[0] = 1;
		increment[1] = 2;
		initialYPos = 2;
	}
	else
	{
		increment[0] = -1;
		increment[1] = -2;
		initialYPos = 7;
	}

	if(oldCoord.x != newCoord.x) // pawn can only move on the y axis
	{
		valid = false;
	}
	
	if(info.coords.y == initialYPos) // pawn has not been moved yet. can move 2 squares
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
