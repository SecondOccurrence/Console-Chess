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
	
	int pawnPos;
	//back pieces
	if (whiteSide == true)
	{
		pawnPos = 8;
		pieces.push_back(new Knight(whiteSide, 1));
		pieces.push_back(new Knight(whiteSide, 6));

		pieces.push_back(new Bishop(whiteSide, 2));
		pieces.push_back(new Bishop(whiteSide, 5));

		pieces.push_back(new Rook(whiteSide, 0));
		pieces.push_back(new Rook(whiteSide, 7));

		pieces.push_back(new Queen(whiteSide, 3));
		
		pieces.push_back(new King(whiteSide, 4));
	}	
	else
	{
		pawnPos = 48;
		pieces.push_back(new Knight(whiteSide, 57));
		pieces.push_back(new Knight(whiteSide, 62));

		pieces.push_back(new Bishop(whiteSide, 58));
		pieces.push_back(new Bishop(whiteSide, 61));

		pieces.push_back(new Rook(whiteSide, 56));
		pieces.push_back(new Rook(whiteSide, 63));

		pieces.push_back(new Queen(whiteSide, 59));

		pieces.push_back(new King(whiteSide, 60));
	}
			
	//pawns
	for (int i = 0; i < 8; i++)
	{
		pieces[i] = new Pawn(true, pawnPos);
		pawnPos++;
	}
}

Player::~Player()
{
	for (auto piece : pieces)
	{
		delete piece;
	}
}

void Player::toMove()
{

}
