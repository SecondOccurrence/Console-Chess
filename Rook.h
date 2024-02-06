#pragma once

#include "BoardSideEnum.h"
#include "Coordinate.h"
#include "Piece.h"

#include <vector>

class Rook : public Piece
{
public:
	Rook(boardSide val, int posX, int posY);

	std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos) override;
};
