#include "Player.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

#include "Coordinate.h"

Player::Player()
{
	playerSide = WHITE;
}

Player::Player(boardSide chosenSide)
{
	playerSide = chosenSide;

	int pawnPosY;
	//back pieces
	if (playerSide == WHITE)
	{
		pawnPosY = 2;
		pieces.push_back(new Knight(chosenSide, 2, 1));
		pieces.push_back(new Knight(chosenSide, 7, 1));

		pieces.push_back(new Bishop(chosenSide, 3, 1));
		pieces.push_back(new Bishop(chosenSide, 6, 1));

		pieces.push_back(new Rook(chosenSide, 1, 1));
		pieces.push_back(new Rook(chosenSide, 8, 1));

		pieces.push_back(new Queen(chosenSide, 4, 1));
		
		pieces.push_back(new King(chosenSide, 5, 1));

		for (int i = 1; i < 9; i++)
		{
			pieces.push_back(new Pawn(chosenSide, i, pawnPosY));
		}
	}	
	else
	{
		pawnPosY = 7;
		pieces.push_back(new Knight(chosenSide, 2, 8));
		pieces.push_back(new Knight(chosenSide, 7, 8));

		pieces.push_back(new Bishop(chosenSide, 3, 8));
		pieces.push_back(new Bishop(chosenSide, 6, 8));

		pieces.push_back(new Rook(chosenSide, 1, 8));
		pieces.push_back(new Rook(chosenSide, 8, 8));

		pieces.push_back(new Queen(chosenSide, 4, 8));

		pieces.push_back(new King(chosenSide, 5, 8));

		for (int i = 1; i < 9; i++)
		{
			pieces.push_back(new Pawn(chosenSide, i, pawnPosY));
		}
	}
	int SIZE = pieces.size();
	for(int i=0; i<SIZE; i++)
	{
		pieces[i]->validateMove(coordinate(), coordinate());
	}
}

void Player::clearPieces()
{
	pieces.clear();
}

void Player::importPiece(char piece, boardSide side, int x, int y)
{
	switch(piece)
	{
	case 'p':
	case 'P':
		pieces.push_back(new Pawn(side, x, y));	
		break;
		
	case 'n':
	case 'N':
		pieces.push_back(new Knight(side, x, y));
		break;

	case 'b':
	case 'B':
		pieces.push_back(new Bishop(side, x, y));
		break;

	case 'r':
	case 'R':
		pieces.push_back(new Rook(side, x, y));
		break;

	case 'q':
	case 'Q':
		pieces.push_back(new Queen(side, x, y));
		break;

	case 'k':
	case 'K':
		pieces.push_back(new King(side, x, y));
		break;
		
	default:
		std::cout << "unidentifiable piece" << std::endl;
		break;
	}
}

std::string Player::getMove()
{
	std::string move;

	bool validMove = false;
	while (!validMove)
	{
		if (playerSide == WHITE)
		{
			std::cout << "White move:" << std::endl;
		}
		else
		{
			std::cout << "Black move:" << std::endl;
		}

		std::cin >> move;

		validMove = validateMove(move);
		if (!validMove)
			std::cout << "Invalid move. Try again." << std::endl;
	}

	return move;
}

bool Player::validateMove(std::string playerMove)
{
	if (playerMove.length() != 4)
		return false;

	bool valid = true;
	coordinate coord;

	// check if move is on board
	for (int i = 0; i < 4; i += 2) 
	{
		coord.x = (int)playerMove[i] - 96; // converts char to its position on the board grid (1-8)
		coord.y = (int)playerMove[i + 1] - 48; // convert char number to ascii number equivalent

		if ((coord.x > 8 || coord.x < 1) || (coord.y > 8 || coord.y < 1))
		{
			valid = false;
			break;
		}
	}

	// check if move is being performed on one of player's pieces
	coordinate originalCoord{(int)playerMove[0] - 96, (int)playerMove[1] - 48};
	coordinate targetCoord{(int)playerMove[2] - 96, (int)playerMove[3] - 48};

	int foundPieceIndex = 0;
	bool isPlayerPiece = findCoordMatch(originalCoord, &foundPieceIndex);

	if(!isPlayerPiece)
	{
		valid = false;
	}
	else // move is being performed on players piece	
	{
		// call the validate move function for the specific piece behaviour
		//   e.g. check if pawn move is valid
		
		valid = pieces[foundPieceIndex]->validateMove(originalCoord, targetCoord);
	}

	return valid;
}

std::vector<PieceInfo> Player::getPiecePositions()
{
	std::vector<PieceInfo> piecePosArr;

	int pieceAmount = pieces.size();
	for (int i = 0; i < pieceAmount; i++)
	{
		piecePosArr.push_back(pieces[i]->getPieceInfo());
	}
	return piecePosArr;
}

void Player::assignNewPosition(coordinate oldCoords, coordinate newCoords)
{
	int SIZE = pieces.size();
	for(int i = 0; i < SIZE; i++)
	{
		if(pieces[i]->getX() == oldCoords.x && pieces[i]->getY() == oldCoords.y)
		{
			pieces[i]->setX(newCoords.x);
			pieces[i]->setY(newCoords.y);
			break;
		}
	}
}

bool Player::findCoordMatch(coordinate coord, int* index)
{
	bool found = false;

	int SIZE = pieces.size();
	for(int i = 0; i < SIZE; i++)
	{
		if(pieces[i]->getX() == coord.x && pieces[i]->getY() == coord.y)
		{
			found = true;
			*index = i;
			break;
		}
	}

	return found;
}

void Player::generatePossibleMoves(int pieceIndex, coordinate startingCoord)
{
	possibleMoves = pieces[pieceIndex]->fetchMoves(startingCoord);
}
