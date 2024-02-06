#pragma once

#include "BoardSideEnum.h"
#include "Coordinate.h"
#include "Piece.h"

#include <vector>

class Pawn : public Piece
{
public:
	Pawn(boardSide side, int posX, int posY);

	std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos) override;
};
