#pragma once

#include "Coordinate.h"
#include "Piece.h"

#include <unordered_map>
#include <vector>

typedef std::unordered_map<coordinate, Piece*> PieceMap;
typedef std::vector<std::vector<int>> IntVec2D;

class Board
{
public:
	Board();

	void updateBoard(PieceMap* piecesA, PieceMap* piecesB);
	const IntVec2D& getBoard() const;
	int getPieceAtPos(int xPos, int yPos) const;

	void resetBoard(); // public as GameManager will use this when importing game state
	
private:
	const int xySize = 8;
	IntVec2D boardCells;
};
