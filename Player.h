#pragma once
#include "Piece.h"
#include "PieceInfo.h"
#include "Coordinate.h"
#include "BoardSideEnum.h"
#include "PieceMapHash.h"

#include <vector>
#include <iostream>
#include <unordered_map>

class Player
{
public:
	Player();
	Player(boardSide chosenSide);

	void clearPieces(); // used for importing a game
	void importPiece(char piece, boardSide side, int x, int y);

	std::string getMove();
	bool validateMove(std::string playerMove);
	const std::vector<coordinate>* getPossibleMoves();
	std::vector<PieceInfo> getPiecePositions();
	void assignNewPosition(coordinate oldCoords, coordinate newCoords);

private:
	boardSide playerSide;
	std::vector<Piece*> pieces;
	std::unordered_map<coordinate, PieceInfo> testpieces;
	std::vector<coordinate> possibleMoves; // current piece to move's possible positions

	bool findCoordMatch(coordinate coord, int* index);
	void generatePossibleMoves(int foundIndex, coordinate startingCoord);
};
