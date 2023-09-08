#pragma once

class Piece
{
public:
	Piece();

protected:
	bool side; //white = true, black = false
	int position[2]; //position on the board. 0-63
};