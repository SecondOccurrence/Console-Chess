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
	// TODO: prune move vector in this function.
	//   saves time when looping in the future.
	//     validateMove function would only need to see if the move exists in the 2d vector


	/*
	std::vector<std::vector<coordinate>> allMoveCoordinates;

	allMoveCoordinates.push_back(std::vector<coordinate>{}); // first vector, regular moves
	allMoveCoordinates.push_back(std::vector<coordinate>{}); // second vector, capture moves

	int increment;
	int initialYPos; // the initial position of a pawn before being moved by the player
	if(info.side == WHITE)
	{
		increment = 1; // moving up the board
		initialYPos = 2;
	}
	else
	{
		increment = -1; // moving down the board
		initialYPos = 7;
	}

	if(startingPos.y <= 7)
	{
		allMoveCoordinates[1].push_back(coordinate{startingPos.x, startingPos.y + increment});

		if(startingPos.y == initialYPos) // the pawn can move 2 spaces, although never again
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
	*/
	return {};
}

bool Pawn::validateMove(coordinate oldCoord, coordinate targetCoord, std::vector<std::vector<coordinate>>* movePaths)
{
	bool valid = true;

	return valid;
}
