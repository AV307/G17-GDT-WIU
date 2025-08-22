#include "Game.h"
#include "CombatSystem.h"
#include <cstdlib>
#include <iostream>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Game game;
    CombatSystem CombatSystem;


    
    while (true) {
        game.doTurn(CombatSystem);
    }

    return 0;
};