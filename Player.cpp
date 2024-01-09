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
		pieces.push_back(Knight(chosenSide, 2, 1));
		pieces.push_back(Knight(chosenSide, 7, 1));

		pieces.push_back(Bishop(chosenSide, 3, 1));
		pieces.push_back(Bishop(chosenSide, 6, 1));

		pieces.push_back(Rook(chosenSide, 1, 1));
		pieces.push_back(Rook(chosenSide, 8, 1));

		pieces.push_back(Queen(chosenSide, 4, 1));
		
		pieces.push_back(King(chosenSide, 5, 1));

		for (int i = 1; i < 9; i++)
		{
			pieces.push_back(Pawn(chosenSide, i, pawnPosY));
		}
	}	
	else
	{
		pawnPosY = 7;
		pieces.push_back(Knight(chosenSide, 2, 8));
		pieces.push_back(Knight(chosenSide, 7, 8));

		pieces.push_back(Bishop(chosenSide, 3, 8));
		pieces.push_back(Bishop(chosenSide, 6, 8));

		pieces.push_back(Rook(chosenSide, 1, 8));
		pieces.push_back(Rook(chosenSide, 8, 8));

		pieces.push_back(Queen(chosenSide, 4, 8));

		pieces.push_back(King(chosenSide, 5, 8));

		for (int i = 1; i < 9; i++)
		{
			pieces.push_back(Pawn(chosenSide, i, pawnPosY));
		}
	}
}

std::string Player::performMove()
{
	std::string move = getMove();

	coordinate initialCoords;
	initialCoords.x = (int)move[0] - 96; // converts char to its position on the board grid (1-8)
	initialCoords.y = (int)move[1] - 48; // convert char number to ascii number equivalent
	
	coordinate moveCoords;
	moveCoords.x = (int)move[2] - 96;
	moveCoords.y = (int)move[3] - 48;

	bool test = false;

	int SIZE = pieces.size();
	std::cout << SIZE << std::endl;
	for(int i = 0; i < SIZE; i++)
	{
		if(pieces[i].getX() == initialCoords.x && pieces[i].getY() == initialCoords.y)
		{
			//change its position
			pieces[i].setX(moveCoords.x);
			pieces[i].setY(moveCoords.y);
			test = true;
		}
	}

	if(!test)
	{
		std::cout << "nothing found" << std::endl;
	}

	return move;
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
	bool isPlayerPiece = true;
	coord.x = (int)playerMove[0] - 96;
	coord.y = (int)playerMove[1] - 48;
	//if()


	return valid;
}

std::vector<PieceInfo> Player::getPiecePositions()
{
	std::vector<PieceInfo> piecePosArr;

	int pieceAmount = pieces.size();
	for (int i = 0; i < pieceAmount; i++)
	{
		// TODO: rather than have PieceInfo, change to ONLY x and y values
		// 	through Piece::getX(), Piece::getY()
		// 	nothing except the Piece class should have access to PieceInfo.
		piecePosArr.push_back(pieces[i].getPieceInfo());
	}
	return piecePosArr;
}

PieceInfo Player::getPieceAtPos(std::string move)
{
	std::vector<PieceInfo> piecePosArr = getPiecePositions();
	PieceInfo foundPiece;

	// convert initial position to integer coordinates
	coordinate coord = {move[0] - 64, (int)move[1]};

	int piecesSize = piecePosArr.size();
	for(int i=0; i<piecesSize; i++)
	{
		if(piecePosArr[i].coords.x == coord.x && piecePosArr[i].coords.y == coord.y)
		{
			foundPiece = piecePosArr[i];
		}
	}

	
}
