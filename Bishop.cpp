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
	// x,y 
	// +1,+1 until maxRight maxUp
	// -1,-1 until maxLeft  maxDown
	// +1,-1 until maxRight maxDown
	// -1,+1 until maxLeft  maxUp
	//
	// get lowest of values run for loop to that
	std::vector<std::vector<coordinate>> possibleMoves;

	int maxLeft = startingPos.x;
	int maxRight = 8 - startingPos.x;
	int maxUp = 8 - startingPos.y;
	int maxDown = startingPos.y;

	std::cout << maxRight << "|" << maxUp << std::endl;

	std::vector<coordinate> movePath;
	
	// right up diagonal path
	movePath = addMoves(startingPos, maxRight, 1, maxUp, 1);
	possibleMoves.push_back(movePath);

	// left up diagonal path
	movePath = addMoves(startingPos, maxLeft, -1, maxUp, 1);
	possibleMoves.push_back(movePath);
	
	// left down diagonal path
	movePath = addMoves(startingPos, maxLeft, -1, maxDown, -1);
	possibleMoves.push_back(movePath);
	
	// right down diagonal path
	movePath = addMoves(startingPos, maxRight, -1, maxDown, -1);
	possibleMoves.push_back(movePath);

	return possibleMoves;
}

bool Bishop::validateMove(coordinate oldCoord, coordinate targetCoord, std::vector<std::vector<coordinate>>* movePaths)
{
	return false;
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
		newMovePath.push_back(coords);

		coords.x = coords.x + xInc;
		coords.y = coords.y + yInc;
	}

	return newMovePath;
}
