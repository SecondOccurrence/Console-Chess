#pragma once

#include "Player.h"
#include "Board.h"
#include "BoardSideEnum.h"
#include "Coordinate.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	bool run();
	void displayBoard();

	void readFENBoard();
private:
	Board board;
	boardSide sideToMove;
	Player* whiteSide;
	Player* blackSide;

	std::string getFENString();
	void performMove(boardSide moveSide, std::string move);
	bool isValidMove(std::string move);

	bool checkForCapture(coordinate targetCoord, std::unordered_map<coordinate, Piece*>* allyPieces, std::unordered_map<coordinate, Piece*>* opponentPieces);
};
