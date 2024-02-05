#pragma once
#include "Piece.h"
#include "Coordinate.h"

class Bishop : public Piece
{
public:
	Bishop(boardSide val, int posX, int posY);

	std::vector<std::vector<coordinate>> fetchMoves(coordinate startingPos) override;

private:
	std::vector<coordinate> addMoves(coordinate coords, int lim1, int lim1Inc, int lim2, int lim2Inc);

};
