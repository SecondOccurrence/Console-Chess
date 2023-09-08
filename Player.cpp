#include "Player.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

Player::Player()
{
	whiteSide = false;
}

Player::Player(bool isWhite)
{
	whiteSide = isWhite;

	int pawnPosY;
	//back pieces
	if (whiteSide == true)
	{
		pawnPosY = 1;
		pieces.push_back(Knight(whiteSide, 1, 0));
		pieces.push_back(Knight(whiteSide, 6, 0));

		pieces.push_back(Bishop(whiteSide, 2, 0));
		pieces.push_back(Bishop(whiteSide, 5, 0));

		pieces.push_back(Rook(whiteSide, 0, 0));
		pieces.push_back(Rook(whiteSide, 7, 0));

		pieces.push_back(Queen(whiteSide, 3, 0));
		
		pieces.push_back(King(whiteSide, 4, 0));
	}	
	else
	{
		pawnPosY = 7;
		pieces.push_back(Knight(whiteSide, 1, 7));
		pieces.push_back(Knight(whiteSide, 6, 7));

		pieces.push_back(Bishop(whiteSide, 2, 7));
		pieces.push_back(Bishop(whiteSide, 5, 7));

		pieces.push_back(Rook(whiteSide, 0, 7));
		pieces.push_back(Rook(whiteSide, 7, 7));

		pieces.push_back(Queen(whiteSide, 3, 7));

		pieces.push_back(King(whiteSide, 4, 7));
	}
			
	//pawns
	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(Pawn(whiteSide, i, pawnPosY));
		pawnPosY++;
	}
}

std::string Player::getMove()
{
	std::string move;

	bool validMove = false;
	while (!validMove)
	{
		if (whiteSide)
			std::cout << "White move:" << std::endl;
		else
			std::cout << "Black move:" << std::endl;

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
	std::cout << "SIZE: " << pieceAmount << std::endl;
	for (int i = 0; i < pieceAmount; i++)
	{
		piecePosArr.push_back(pieces[i].getPieceInfo());
	}
	return piecePosArr;
}
