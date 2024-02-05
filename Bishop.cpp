#include "Bishop.h"

Bishop::Bishop(boardSide val, int posX, int posY)
{
	info.side = val;
	info.coords.x = posX;
	info.coords.y = posY;
	
	if(val == WHITE)
	{
		info.piece = w_BISHOP;
	}
	else
	{
		info.piece = b_BISHOP;
	}
}

// change to return pointer
std::vector<std::vector<coordinate>> Bishop::fetchMoves(coordinate startingPos)
{
	std::vector<std::vector<coordinate>> possibleMoves;

	int maxLeft = startingPos.x - 1;
	int maxRight = 8 - startingPos.x;
	int maxUp = 8 - startingPos.y;
	int maxDown = startingPos.y - 1;

	std::vector<coordinate> movePath;
	
	// right up diagonal path
	movePath = addMoves(startingPos, 1, 1, maxRight, maxUp);
	possibleMoves.push_back(movePath);

	// left up diagonal path
	movePath = addMoves(startingPos, -1, 1, maxLeft, maxUp);
	possibleMoves.push_back(movePath);
	
	// left down diagonal path
	movePath = addMoves(startingPos, -1, -1, maxLeft, maxDown);
	possibleMoves.push_back(movePath);
	
	// right down diagonal path
	movePath = addMoves(startingPos, 1, -1, maxRight, maxDown);
	possibleMoves.push_back(movePath);

	return possibleMoves;
}

std::vector<coordinate> Bishop::addMoves(coordinate coords, int xInc, int yInc, int lim1, int lim2)
{
	std::vector<coordinate> newMovePath;

	int minLimit;
	if(lim1 < lim2)
	{
		minLimit = lim1;
	}
	else
	{
		minLimit = lim2;
	}

	for(int i = 0; i < minLimit; i++)
	{
		coords.x = coords.x + xInc;
		coords.y = coords.y + yInc;

		newMovePath.push_back(coords);
	}

	return newMovePath;
}
