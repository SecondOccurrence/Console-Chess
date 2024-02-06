#pragma once

#include "BoardSideEnum.h"
#include "Coordinate.h"
#include "Piece.h"

#include <vector>

typedef std::vector<coordinate> CoordinateVec1D;
typedef std::vector<std::vector<coordinate>> CoordinateVec2D;

class Bishop : public Piece
{
public:
	Bishop(boardSide val, int posX, int posY);

	CoordinateVec2D fetchMoves(coordinate startingPos) override;

private:
	CoordinateVec1D addMoves(coordinate coords, int lim1, int lim1Inc, int lim2, int lim2Inc);

};
