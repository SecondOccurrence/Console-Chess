#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(boardSide val, int posX, int posY);

	std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos) override;
	bool validateMove(coordinate targetCoord, std::vector<coordinate>* movePaths) override;

};
