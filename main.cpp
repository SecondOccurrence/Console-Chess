#include "GameManager.h"

#include <iostream>

int main()
{
    GameManager gm;

    bool quit = false;
	char importChoice;
    while(!quit)
    {
		std::cout << "Would you like to import a current game state using a FEN string? y/n" << std::endl;
		std::cin >> importChoice;
		if(importChoice == 'y' || importChoice == 'Y')
		{
			gm.readFENBoard();
		}
        quit = gm.run();
    }
    std::cout << "Game Ended" << std::endl;
}
