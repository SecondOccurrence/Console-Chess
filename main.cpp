#include "GameManager.h"

#include <iostream>

int main()
{
    GameManager gm;

    bool quit = false;
    while(!quit)
    {
        quit = gm.Run();
    }

    std::cout << "Game Ended" << std::endl;
}