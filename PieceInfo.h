#pragma once
#include <string>

typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } pieceName;

struct PieceInfo
{
	bool side;
	pieceName piece;
	int posX;
	int posY;
};
