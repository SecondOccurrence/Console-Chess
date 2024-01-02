#pragma once

#include "BoardSideEnum.h"

typedef enum { w_PAWN, w_KNIGHT, w_BISHOP, w_ROOK, w_QUEEN, w_KING, b_PAWN, b_KNIGHT, b_BISHOP, b_ROOK, b_QUEEN, b_KING } pieceName; // w_... for white side, b_... for black side. Needed to be able to distinguish which type of piece to print on board

struct PieceInfo
{
	boardSide side;
	pieceName piece;
	int posX;
	int posY;

	// side and piece are arbitrary values.
	// posX and posY are important here. We can use this to see if say a function returning PieceInfo
	// 	has actually found a piece through the search. (-1,-1) will not ever be assigned
	// 	to an existing piece on the board.
	PieceInfo(): side(WHITE), piece(w_PAWN), posX(-1), posY(-1) {};
};
