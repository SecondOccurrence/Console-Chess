#pragma once

#include "Coordinate.h"
#include "Piece.h"

#include <unordered_map>

class Board
{
public:
	Board();

	void updateBoard(std::unordered_map<coordinate, Piece*>* piecesA, std::unordered_map<coordinate, Piece*>* piecesB);
	const std::vector<std::vector<int>>& getBoard() const;
	int getPieceAtPos(int xPos, int yPos) const;

	void resetBoard(); // public as GameManager will use this when importing game state
	
private:
	const int xySize = 8;
	std::vector<std::vector<int>> boardCells;
};
