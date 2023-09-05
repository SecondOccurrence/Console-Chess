#include "GameManager.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

GameManager::GameManager()
{
	*pieces = new Piece[32];

	int whitePawnStart = 8;
	int blackPawnStart = 48;
	for(int i=0; i<16; i+=2)
	{
		pieces[i] = new Pawn(true, whitePawnStart);
		pieces[i+1] = new Pawn(false, blackPawnStart);

		whitePawnStart++;
		blackPawnStart++;
	}

	pieces[16] = new Knight(true, 1);
	pieces[17] = new Knight(true, 6);
	pieces[18] = new Knight(false, 57);
	pieces[19] = new Knight(false, 62);

	pieces[20] = new Bishop(true, 2);
	pieces[21] = new Bishop(true, 5);
	pieces[22] = new Bishop(false, 58);
	pieces[23] = new Bishop(false, 61);

	pieces[24] = new Rook(true, 0);
	pieces[25] = new Rook(true, 7);
	pieces[26] = new Rook(false, 56);
	pieces[27] = new Rook(false, 63);

	pieces[28] = new Queen(true, 3);
	pieces[29] = new Queen(false, 59);

	pieces[30] = new King(true, 4);
	pieces[31] = new King(false, 60);
}

void GameManager::DisplayBoard()
{
	//loop through each piece
		//note their position
	//display

	//perhaps tie each object type with numeric value
}

bool GameManager::Run()
{
	//move pieces
	//check if checkmate
	//return result
}