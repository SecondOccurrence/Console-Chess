#include "Piece.h"

#include <iostream>

Piece::Piece()
{
	info.side = WHITE;
	info.piece = w_PAWN;
	info.coords.x = 0;
	info.coords.y = 0;
}

int Piece::getX() const
{
	return info.coords.x;
}

int Piece::getY() const
{
	return info.coords.y;
}

void Piece::setX(int x)
{
	info.coords.x = x;
}

void Piece::setY(int y)
{
	info.coords.y = y;
}

PieceInfo Piece::getPieceInfo()
{
	return info;
}

std::vector<std::vector<coordinate>> Piece::fetchMoves(coordinate startingPos)
{
	std::cout << "hwef" << std::endl;
	return {};
}

bool Piece::validateMove(coordinate targetCoord, std::vector<std::vector<coordinate>>& movePaths)
{
	bool valid = false;
	int pathSize1D = movePaths.size();
	int pathSize2D;
	for(int i = 0; i < pathSize1D; i++)
	{
		pathSize2D = movePaths[i].size();
		for(int j = 0; j < pathSize2D; j++)
		{
			if(movePaths[i][j] == targetCoord)
			{
				std::cout << "this is a valid move" << std::endl;
				valid = true;
				break;
			}
		}

		if(valid == true)
			break;
	}

	return valid;
}

