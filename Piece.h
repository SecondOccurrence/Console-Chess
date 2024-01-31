#pragma once

#include "PieceInfo.h"
#include "Coordinate.h"

#include <iostream>
#include <vector>

class Piece
{
public:
	Piece();
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	PieceInfo getPieceInfo();

	virtual bool validateMove(coordinate targetCoord, std::vector<coordinate>* movePaths);
	virtual std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos);

protected:
	PieceInfo info;
};

// TODO:
//
// change piece w_... b_... to just ... as every piece object has a side attribute.
// can compare using PieceInfo.side
