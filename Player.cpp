#include "Player.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

Player::Player()
{
	playerSide = WHITE;
}

Player::~Player()
{
	for(std::unordered_map<coordinate, Piece*>::iterator it = pieces.begin(); it != pieces.end(); )
	{
		delete it->second;
		it = pieces.erase(it);
	}
}

Player::Player(boardSide chosenSide)
{
	playerSide = chosenSide;

	int pawnPosY;
	//back pieces
	if (playerSide == WHITE)
	{
		pawnPosY = 2;
		pieces[coordinate(2, 1)] = new Knight(chosenSide, 2, 1);
		pieces[coordinate(7, 1)] = new Knight(chosenSide, 7, 1);

		pieces[coordinate(3, 1)] = new Bishop(chosenSide, 3, 1);
		pieces[coordinate(6, 1)] = new Bishop(chosenSide, 6, 1);

		pieces[coordinate(1, 1)] = new Rook(chosenSide, 1, 1);
		pieces[coordinate(8, 1)] = new Rook(chosenSide, 8, 1);

		pieces[coordinate(4, 1)] = new Queen(chosenSide, 4, 1);
		
		pieces[coordinate(5, 1)] = new King(chosenSide, 5, 1);

		for (int i = 1; i < 9; i++)
		{
			pieces[coordinate(i, pawnPosY)] = new Pawn(chosenSide, i, pawnPosY);
		}
	}	
	else
	{
		pawnPosY = 7;
		pieces[coordinate(2, 8)] = new Knight(chosenSide, 2, 8);
		pieces[coordinate(7, 8)] = new Knight(chosenSide, 7, 8);

		pieces[coordinate(3, 8)] = new Bishop(chosenSide, 3, 8);
		pieces[coordinate(6, 8)] = new Bishop(chosenSide, 6, 8);

		pieces[coordinate(1, 8)] = new Rook(chosenSide, 1, 8);
		pieces[coordinate(8, 8)] = new Rook(chosenSide, 8, 8);

		pieces[coordinate(4, 8)] = new Queen(chosenSide, 4, 8);

		pieces[coordinate(5, 8)] = new King(chosenSide, 5, 8);

		for (int i = 1; i < 9; i++)
		{
			pieces[coordinate(i, pawnPosY)] = new Pawn(chosenSide, i, pawnPosY);
		}
	}
}

void Player::clearPieces()
{
	pieces.clear();
}

void Player::importPiece(char piece, boardSide side, int x, int y)
{
	switch(piece)
	{
	case 'p':
	case 'P':
		pieces[coordinate(x, y)] = new Pawn(side, x, y);	
		break;
		
	case 'n':
	case 'N':
		pieces[coordinate(x, y)] = new Knight(side, x, y);
		break;

	case 'b':
	case 'B':
		pieces[coordinate(x, y)] = new Bishop(side, x, y);
		break;

	case 'r':
	case 'R':
		pieces[coordinate(x, y)] = new Rook(side, x, y);
		break;

	case 'q':
	case 'Q':
		pieces[coordinate(x, y)] = new Queen(side, x, y);
		break;

	case 'k':
	case 'K':
		pieces[coordinate(x, y)] = new King(side, x, y);
		break;
		
	default:
		std::cout << "unidentifiable piece" << std::endl;
		break;
	}
}

std::string Player::getMove()
{
	std::string move;

	bool validMove = false;
	while (!validMove)
	{
		if (playerSide == WHITE)
		{
			std::cout << "White move:" << std::endl;
		}
		else
		{
			std::cout << "Black move:" << std::endl;
		}

		std::cin >> move;

		if(move == "skip")
			return move; // testing purposes

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
	coordinate coord;

	// check if move is on board
	for (int i = 0; i < 4; i += 2) 
	{
		coord.x = (int)playerMove[i] - 96; // converts char to its position on the board grid (1-8)
		coord.y = (int)playerMove[i + 1] - 48; // convert char number to ascii number equivalent

		if ((coord.x > 8 || coord.x < 1) || (coord.y > 8 || coord.y < 1))
		{
			valid = false;
			break;
		}
	}

	// check if move is being performed on one of player's pieces
	coordinate originalCoord{(int)playerMove[0] - 96, (int)playerMove[1] - 48};
	coordinate targetCoord{(int)playerMove[2] - 96, (int)playerMove[3] - 48};

	try
	{
		possibleMoves = pieces.at(originalCoord)->fetchMoves(originalCoord);
	}
	catch(std::out_of_range& e)
	{
		valid = false;
		std::cout << "not on player piece" << std::endl;
	}

	// TODO: use the generated moves in player move validation
	// 	loop through coordinates see if a piece exists there

	// call the validate move function for the specific piece behaviour
	//   e.g. check if pawn move is valid

	if(valid) // move is being called on player piece. now the specific piece
			  //   move behaviour needs to be checked
	{
		valid = pieces.at(originalCoord)->validateMove(originalCoord, targetCoord, &possibleMoves);
	}

	return valid;
}

const std::vector<std::vector<coordinate>>* Player::getPossibleMoves()
{
	return &possibleMoves;	
}

std::unordered_map<coordinate, Piece*>* Player::getPieces()
{
	return &pieces;
}

void Player::assignNewPosition(coordinate oldCoords, coordinate newCoords)
{
	auto node = pieces.extract(oldCoords);
	node.key() = newCoords;
	pieces.insert(std::move(node));
}


