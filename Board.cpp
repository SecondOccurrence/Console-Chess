#include "Board.h"
#include <iostream>

Board::Board()
{
	std::vector<std::vector<int>> arr(8, std::vector<int>(8, 12));
	boardCells = arr;
}

void Board::updateBoard(std::unordered_map<coordinate, Piece*>* piecesA, std::unordered_map<coordinate, Piece*>* piecesB)
{
	resetBoard(); // clear the board so only the most recent piece postitions are displayed

	coordinate currentCoord;
	PieceInfo currentPiece;	

	std::unordered_map<coordinate, Piece*>::iterator itA = piecesA->begin();
	while(itA != piecesA->end())
	{
		currentCoord = itA->first;
		currentPiece = itA->second->getPieceInfo();
		
		// subtracting 1 as coords range 1-8 whilst array is 0-7
		boardCells[currentCoord.y - 1][currentCoord.x - 1] = currentPiece.piece;
		
		itA++;
	}

	std::unordered_map<coordinate, Piece*>::iterator itB = piecesB->begin();
	while(itB != piecesB->end())
	{
		currentCoord = itB->first;
		currentPiece = itB->second->getPieceInfo();

		// subtracting 1 as coords range 1-8 whilst array is 0-7
		boardCells[currentCoord.y - 1][currentCoord.x - 1] = currentPiece.piece;

		itB++;
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
