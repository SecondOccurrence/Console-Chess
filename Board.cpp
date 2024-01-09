#include "Board.h"
#include <iostream>

Board::Board()
{
	std::vector<std::vector<int>> arr(8, std::vector<int>(8, 12));
	boardCells = arr;
}

void Board::updateBoard(std::vector<PieceInfo>& piecesA, std::vector<PieceInfo>& piecesB)
{
	resetBoard(); // clear the board so only the most recent piece postitions are displayed

	int xCoord, yCoord;

	int SIZE = piecesA.size(); //piecesB size is the same as piecesA
	for (int i = 0; i < SIZE; i++)
	{
		xCoord = piecesA[i].coords.x;
		yCoord = piecesA[i].coords.y;
		boardCells[yCoord - 1][xCoord - 1] = piecesA[i].piece; // subtracting one as coords range 1-8
															   //   whilst array is 0-7

		xCoord = piecesB[i].coords.x;
		yCoord = piecesB[i].coords.y;
		boardCells[yCoord - 1][xCoord - 1] = piecesB[i].piece; // subtracting one as coords range 1-8
															   //   whilst array is 0-7
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

void Board::resetBoard()
{
	int xSize = boardCells.size();
	int ySize = boardCells[0].size(); // all 2nd dimension arrays are equal in size
	for(int i = 0; i < xSize; i++)
	{
		for(int j = 0; j < ySize; j++)
		{
			boardCells[i][j] = 12; // 12 represents '.', an empty cell.
		}
	}
}
