#pragma once

#include "BoardSideEnum.h"
#include "Coordinate.h"
#include "Piece.h"

#include <vector>

typedef std::vector<coordinate> CoordinateVec1D;
typedef std::vector<std::vector<coordinate>> CoordinateVec2D;

class Queen : public Piece
{
public:
	Queen(boardSide val, int posX, int posY);

	CoordinateVec2D fetchMoves(coordinate startingPos) override;	
};
