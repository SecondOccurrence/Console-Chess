#include "Board.h"
#include <iostream>

Board::Board()
{
	std::vector<std::vector<int>> arr(8, std::vector<int>(8, 6));
	boardCells = arr;
}

void Board::updateBoard(std::vector<PieceInfo>& piecesA, std::vector<PieceInfo>& piecesB)
{
	int xCoord, yCoord;

	int SIZE = piecesA.size(); //piecesB size is the same as piecesA
	for (int i = 0; i < SIZE; i++)
	{
		xCoord = piecesA[i].posX;
		yCoord = piecesA[i].posY;
		boardCells[yCoord][xCoord] = piecesA[i].piece;

		xCoord = piecesB[i].posX;
		yCoord = piecesB[i].posY;
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