#include "Game.h"
#include "CombatSystem.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Game game;
    CombatSystem CombatSystem;
    Player player;
    
    while (true) {
        game.doTurn(CombatSystem);
    }

    return 0;
};