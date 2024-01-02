#include "Player.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

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
		pawnPosY = 1;
		pieces.push_back(Knight(chosenSide, 1, 0));
		pieces.push_back(Knight(chosenSide, 6, 0));

		pieces.push_back(Bishop(chosenSide, 2, 0));
		pieces.push_back(Bishop(chosenSide, 5, 0));

		pieces.push_back(Rook(chosenSide, 0, 0));
		pieces.push_back(Rook(chosenSide, 7, 0));

		pieces.push_back(Queen(chosenSide, 3, 0));
		
		pieces.push_back(King(chosenSide, 4, 0));

		for (int i = 0; i < 8; i++)
		{
			pieces.push_back(Pawn(chosenSide, i, pawnPosY));
		}
	}	
	else
	{
		pawnPosY = 6;
		pieces.push_back(Knight(chosenSide, 1, 7));
		pieces.push_back(Knight(chosenSide, 6, 7));

		pieces.push_back(Bishop(chosenSide, 2, 7));
		pieces.push_back(Bishop(chosenSide, 5, 7));

		pieces.push_back(Rook(chosenSide, 0, 7));
		pieces.push_back(Rook(chosenSide, 7, 7));

		pieces.push_back(Queen(chosenSide, 3, 7));

		pieces.push_back(King(chosenSide, 4, 7));

		for (int i = 0; i < 8; i++)
		{
			pieces.push_back(Pawn(chosenSide, i, pawnPosY));
		}
	}
}

std::string Player::performMove()
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
	
	// get the piece at the chosen position
	

	return move;
}

bool Player::validateMove(std::string playerMove)
{
	if (playerMove.length() != 4)
		return false;

	bool valid = true;
	int xcoord;
	int ycoord;

	// check if move is on board
	for (int i = 0; i < 4; i += 2) 
	{
		xcoord = (int)playerMove[i] - 96; // converts char to its position on the board grid (1-8)
		ycoord = (int)playerMove[i + 1] - 48; // convert char number to ascii number equivalent

		if ((xcoord > 8 || xcoord < 1) || (ycoord > 8 || ycoord < 1))
		{
			valid = false;
			break;
		}
	}

	// check if move is being performed on one of player's pieces
	bool isPlayerPiece = true;
	xcoord = (int)playerMove[0] - 96;
	ycoord = (int)playerMove[1] - 48;
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
	int xCoord = move[0] - 64;
	int yCoord = (int)move[1];

	int piecesSize = piecePosArr.size();
	for(int i=0; i<piecesSize; i++)
	{
		if(piecePosArr[i].posX == xCoord && piecePosArr[i].posY == yCoord)
		{
			foundPiece = piecePosArr[i];
		}
	}

	
}
