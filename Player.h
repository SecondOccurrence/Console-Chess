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

	std::string performMove();
	bool validateMove(std::string playerMove);
	std::vector<PieceInfo> getPiecePositions();
	PieceInfo getPieceAtPos(std::string move);

private:
	boardSide playerSide;
	std::vector<Piece> pieces;

	std::string getMove();
};
