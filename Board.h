#pragma once

#include "PieceInfo.h"

#include <vector>

class Board
{
public:
	Board();

	void updateBoard(std::vector<PieceInfo> &piecesA, std::vector<PieceInfo> &piecesB);
	const std::vector<std::vector<int>>& getBoard() const;
	int getPieceAtPos(int xPos, int yPos) const;
	
private:
	const int xySize = 8;
	std::vector<std::vector<int>> boardCells;

	void resetBoard();
};
