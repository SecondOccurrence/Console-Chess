#pragma once
#include "Piece.h"
#include "PieceInfo.h"
#include "Coordinate.h"
#include "BoardSideEnum.h"

#include <vector>
#include <iostream>

class Player
{
public:
	Player();
	Player(boardSide chosenSide);

	std::string getMove();
	int getPieceSize();
	bool validateMove(std::string playerMove);
	std::vector<PieceInfo> getPiecePositions();

	void assignNewPosition(coordinate oldCoords, coordinate newCoords);

private:
	boardSide playerSide;
	std::vector<Piece> pieces;

	bool findCoordMatch(coordinate coord);
};
