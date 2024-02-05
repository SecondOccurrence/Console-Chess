#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(boardSide val, int posX, int posY);

	std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos) override;	
};
