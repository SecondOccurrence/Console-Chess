#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(boardSide val, int posX, int posY);

	std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos) override;
};
