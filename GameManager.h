#pragma once

#include "Board.h"
#include "BoardSideEnum.h"
#include "Coordinate.h"
#include "Player.h"

#include <unordered_map>

typedef std::unordered_map<coordinate, Piece*> PieceMap;

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
	bool isValidMove(std::string move, Player* allySide, Player* opponentSide);

	bool checkForCapture(coordinate targetCoord, PieceMap* allyPieces, PieceMap* opponentPieces);
};
