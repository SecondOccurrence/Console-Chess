#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(boardSide val, int posX, int posY);

	std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos) override;
	bool validateMove(coordinate targetCoord, std::vector<coordinate>* movePaths) override;
	
};
