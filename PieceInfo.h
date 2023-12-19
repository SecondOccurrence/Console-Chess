#pragma once

typedef enum { w_PAWN, w_KNIGHT, w_BISHOP, w_ROOK, w_QUEEN, w_KING, b_PAWN, b_KNIGHT, b_BISHOP, b_ROOK, b_QUEEN, b_KING } pieceName; // w_... for white side, b_... for black side. Needed to be able to distinguish which type of piece to print on board

struct PieceInfo
{
	bool side;
	pieceName piece;
	int posX;
	int posY;
};
