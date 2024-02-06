#pragma once

#include "BoardSideEnum.h"
#include "Coordinate.h"
#include "Piece.h"
#include "PieceInfo.h"

#include <iostream>
#include <unordered_map>
#include <vector>

typedef std::vector<std::vector<coordinate>> CoordinateVec2D;
typedef std::unordered_map<coordinate, Piece*> PieceMap;

class Player
{
public:
	Player();
	~Player();
	Player(boardSide chosenSide);

	void clearPieces(); // used for importing a game
	void importPiece(char piece, boardSide side, int x, int y);

	std::string getMove();
	bool validateMove(std::string playerMove);
	const CoordinateVec2D* getPossibleMoves();

	PieceMap* getPieces();
	void assignNewPosition(coordinate oldCoords, coordinate newCoords);

	void pruneMovePathsInt();
	void pruneMovePathsExt(PieceMap* pieceMap);
	

	bool isValidPieceMove(coordinate originalCoord, coordinate targetCoord);

	void removePiece(coordinate pieceToRemove);

private:
	boardSide playerSide;
	PieceMap pieces;
	// current piece to move's possible positions
	//   each sub-vector corresponds to each move path
	CoordinateVec2D possibleMoves;
};
