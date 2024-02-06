#include "Piece.h"

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

CoordinateVec2D Piece::fetchMoves(coordinate startingPos)
{
	return {};
}

bool Piece::validateMove(coordinate targetCoord, CoordinateVec2D& movePaths)
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
				valid = true;
				break;
			}
		}

		if(valid == true)
			break;
	}

	return valid;
}

