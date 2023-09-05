#pragma once

class Piece
{
public:
	Piece();


protected:
	bool side; //white = true, black = false
	int position;
	int posMax = 63, posMin = 0;
};

//array of pieces
	//x,y
//board limits
//input class store moves file backlog
