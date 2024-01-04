#include "Board.h"
#include <iostream>

Board::Board()
{
	std::vector<std::vector<int>> arr(8, std::vector<int>(8, 12));
	boardCells = arr;
}

void Board::updateBoard(std::vector<PieceInfo>& piecesA, std::vector<PieceInfo>& piecesB)
{
	int xCoord, yCoord;

	int SIZE = piecesA.size(); //piecesB size is the same as piecesA
	for (int i = 0; i < SIZE; i++)
	{
		xCoord = piecesA[i].coords.x;
		yCoord = piecesA[i].coords.y;
		boardCells[yCoord][xCoord] = piecesA[i].piece;

		xCoord = piecesB[i].coords.x;
		yCoord = piecesB[i].coords.y;
		boardCells[yCoord][xCoord] = piecesB[i].piece;
	}
}

const std::vector<std::vector<int>>& Board::getBoard() const
{
	return boardCells;
}

int Board::getPieceAtPos(int xPos, int yPos) const
{
	return boardCells[yPos][xPos];
}
