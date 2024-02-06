#pragma once

#include "Coordinate.h"
#include "PieceInfo.h"

#include <vector>

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

	bool validateMove(coordinate targetCoord, std::vector<std::vector<coordinate>>& movePaths);
	virtual std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos);

protected:
	PieceInfo info;
};

// TODO:
//
// change piece w_... b_... to just ... as every piece object has a side attribute.
// can compare using PieceInfo.side
