#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(boardSide val, int posX, int posY);

	std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos) override;
	bool validateMove(coordinate targetCoord, std::vector<coordinate>* movePaths) override;

};
