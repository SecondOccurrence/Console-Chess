#pragma once

#include "Coordinate.h"
#include "PieceInfo.h"

#include <vector>

typedef std::vector<std::vector<coordinate>> CoordinateVec2D;

class Piece
{
public:
	Piece();

	//do these functions need to exist?
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);

	PieceInfo getPieceInfo();

	bool validateMove(coordinate targetCoord, CoordinateVec2D& movePaths);
	virtual CoordinateVec2D fetchMoves(coordinate startingPos);

protected:
	PieceInfo info;
};

// TODO:
//
// change piece w_... b_... to just ... as every piece object has a side attribute.
// can compare using PieceInfo.side
