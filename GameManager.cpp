#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "GameManager.h"
#include "Piece.h"

GameManager::GameManager()
{
	whiteSide = Player(WHITE);
	blackSide = Player(BLACK);
	sideToMove = WHITE;
}

bool GameManager::run()
{
	bool gameEnded = false;
	std::string move;

	std::unordered_map<coordinate, Piece*>* whitePieces = whiteSide.getPieces();
	std::unordered_map<coordinate, Piece*>* blackPieces = blackSide.getPieces();

	board.updateBoard(whitePieces, blackPieces);
	displayBoard();

	if(sideToMove == WHITE)
	{
		move = whiteSide.getMove();
		// game needs to check if move goes past or lands on an existing opponent piece

		// have player return every possible move
		//   player validates, breaks out if player piece interrupt
		//   game validates, breaks out if opponent piece interrupt
		//   move proceeds..
		performMove(sideToMove, move);
		sideToMove = BLACK;
	}
	else
	{
		move = blackSide.getMove();
		if(move == "skip")
		{
			sideToMove = WHITE;
			return gameEnded; // testing purposes
		}

		performMove(sideToMove, move);
		sideToMove = WHITE;
	}

	//move pieces, return value
		//checkmate, clear for next move
	
	return gameEnded;
}
void GameManager::displayBoard()
{
	const char pieces[13] = {'P', 'N', 'B', 'R', 'Q', 'K', 'p', 'n', 'b', 'r', 'q', 'k', '.'};

	int yAxis = 8;
	std::cout << std::endl; //formatting
	
	std::cout << "           BLACK       " << std::endl;
	std::cout << "    +-----------------+" << std::endl;
	for (int i = 7; i >= 0; i--)
	{
		std::cout << "  " << yAxis << " "; // print out y-axis grid number
		yAxis--;

		int boardColumns = 9;		
		for(int j = 0; j <= boardColumns; j++)
		{
			if(j == 0 || j == boardColumns)
			{
				std::cout << "| ";
				continue;
			}
			std::cout << pieces[board.getPieceAtPos(j - 1, i)] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "    +-----------------+" << std::endl;
	std::cout << "      a b c d e f g h" << std::endl;
	std::cout << "           WHITE      " << std::endl;
}


void GameManager::readFENBoard()
{
	// remove all existing pieces from the board
	board.resetBoard();
	whiteSide.clearPieces();
	blackSide.clearPieces();

	std::string FENString = getFENString();
	std::stringstream FENStringstream;
	std::string row;

	//start 1,1 -> end 8,8
	int xCoord = 1;
	int yCoord = 8;

	int rowSize;
	FENStringstream << FENString;
	while(std::getline(FENStringstream, row, '/'))
	{
		rowSize = row.length();
		int blankCells;
		for(int i = 0; i < rowSize; i++)
		{ 
			blankCells = std::atoi(&row[i]);
			if(blankCells == 0) // there is a piece on this cell
			{
				if(row[i] >= 'A' && row[i] <= 'Z') // is a capital letter -> white piece
				{
					whiteSide.importPiece(row[i], WHITE, xCoord, yCoord);
					// switch case piece -> object -> push back(new Pawn(white, x, y)
				}
				else if(row[i] >= 'a' && row[i] <= 'z')
				{
					blackSide.importPiece(row[i], BLACK, xCoord, yCoord);
					// switch case piece -> object -> push back(new Pawn(black, x, y)
				}
				xCoord += 1;
			}
			else
			{
				xCoord += blankCells;
			}

			if(xCoord > 8)
			{
				xCoord = 1; // end of row. start next row
			}
		}
		yCoord -= 1;
	}
}

std::string GameManager::getFENString()
{
	std::string fileName;
	std::fstream FENFile;
	std::stringstream fileContents;

	std::cout << "Enter the text file name (excluding .txt) containing the FEN string: ";
	std::cin >> fileName;

	FENFile.open("Test-Boards/" + fileName + ".txt", std::fstream::in);
	fileContents << FENFile.rdbuf();
	FENFile.close();

	return fileContents.str();
}

void GameManager::performMove(boardSide moveSide, std::string move)
{
	coordinate initialCoords;
	initialCoords.x = (int)move[0] - 96; // converts char to its position on the board grid (1-8)
	initialCoords.y = (int)move[1] - 48; // convert char number to ascii number equivalent
	
	coordinate moveCoords;
	moveCoords.x = (int)move[2] - 96;
	moveCoords.y = (int)move[3] - 48;

	if(moveSide == WHITE)
	{
		whiteSide.assignNewPosition(initialCoords, moveCoords);
	}
	else
	{
		blackSide.assignNewPosition(initialCoords, moveCoords);
	}
}
