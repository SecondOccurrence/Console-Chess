#pragma once

#include "BoardSideEnum.h"
#include "Coordinate.h"
#include "Piece.h"
#include "PieceInfo.h"

#include <iostream>
#include <unordered_map>
#include <vector>

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
	const std::vector<std::vector<coordinate>>* getPossibleMoves();

	std::unordered_map<coordinate, Piece*>* getPieces();
	void assignNewPosition(coordinate oldCoords, coordinate newCoords);

	void pruneMovePathsInt();
	void pruneMovePathsExt(std::unordered_map<coordinate, Piece*>* pieceMap);
	

	bool isValidPieceMove(coordinate originalCoord, coordinate targetCoord);

	void removePiece(coordinate pieceToRemove);

private:
	boardSide playerSide;
	std::unordered_map<coordinate, Piece*> pieces;
	// current piece to move's possible positions
	//   each sub-vector corresponds to each move path
	std::vector<std::vector<coordinate>> possibleMoves;
};
