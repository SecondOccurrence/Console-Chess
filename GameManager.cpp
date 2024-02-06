#include "GameManager.h"
#include "Piece.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

GameManager::GameManager()
{
	whiteSide = new Player(WHITE);
	blackSide = new Player(BLACK);
	sideToMove = WHITE;
}

GameManager::~GameManager()
{
	delete whiteSide;
	delete blackSide;
}

bool GameManager::run()
{
	bool gameEnded = false;
	std::string move;

	std::unordered_map<coordinate, Piece*>* whitePieces = whiteSide->getPieces();
	std::unordered_map<coordinate, Piece*>* blackPieces = blackSide->getPieces();

	board.updateBoard(whitePieces, blackPieces);
	displayBoard();

	bool validMove;
	if(sideToMove == WHITE)
	{
		move = whiteSide->getMove();

		if(move == "skip")
		{
			sideToMove = WHITE;
			return gameEnded; // testing purposes
		}

		validMove = isValidMove(move, whiteSide, blackSide);
		if (!validMove)
		{
			std::cout << "Invalid move. Try again." << std::endl;
		}
		else
		{
			performMove(sideToMove, move);
			sideToMove = BLACK;
		}	
	}
	else
	{
		move = blackSide->getMove();

		if(move == "skip")
		{
			sideToMove = WHITE;
			return gameEnded; // testing purposes
		}

		validMove = isValidMove(move, blackSide, whiteSide);
		if(!validMove)
		{
			std::cout << "Invalid move. Try again." << std::endl;
		}
		else
		{
			performMove(sideToMove, move);
			sideToMove = BLACK;
		}
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
	whiteSide->clearPieces();
	blackSide->clearPieces();

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
					whiteSide->importPiece(row[i], WHITE, xCoord, yCoord);
					// switch case piece -> object -> push back(new Pawn(white, x, y)
				}
				else if(row[i] >= 'a' && row[i] <= 'z')
				{
					blackSide->importPiece(row[i], BLACK, xCoord, yCoord);
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
		whiteSide->assignNewPosition(initialCoords, moveCoords);
	}
	else
	{
		blackSide->assignNewPosition(initialCoords, moveCoords);
	}
}

bool GameManager::isValidMove(std::string move, Player* allySide, Player* opponentSide)
{

	bool valid = allySide->validateMove(move);
	bool isCapture;

	if(!valid)
	{
		return false;
	}

	// prune moves being blocked by players pieces
	allySide->pruneMovePathsInt();
	// now by opponent pieces
	allySide->pruneMovePathsExt(opponentSide->getPieces());

	coordinate originalCoord{(int)move[0] - 96, (int)move[1] - 48};
	coordinate targetCoord{(int)move[2] - 96, (int)move[3] - 48};
	
	valid = allySide->isValidPieceMove(originalCoord, targetCoord);

	// check if two clashing pieces, remove the other as its been captured
	isCapture = checkForCapture(targetCoord, allySide->getPieces(), opponentSide->getPieces());

	if(isCapture)
	{
		opponentSide->removePiece(targetCoord);
	}

	return valid;
}

bool GameManager::checkForCapture(coordinate targetCoord, std::unordered_map<coordinate, Piece*>* allyPieces, std::unordered_map<coordinate, Piece*>* opponentPieces)
{
	bool pieceFound = false;

	std::unordered_map<coordinate, Piece*>::iterator opponentPieceItr = opponentPieces->begin();

	Piece* currentPiece;
	while(opponentPieceItr != opponentPieces->end())
	{
		try
		{
			currentPiece = opponentPieces->at(targetCoord);
			pieceFound = true;
			delete currentPiece;
			break;
		}
		catch(std::out_of_range &e)
		{
			std::cout << "no piece found" << std::endl;
		}

		opponentPieceItr++;
	}

	return pieceFound;
}
