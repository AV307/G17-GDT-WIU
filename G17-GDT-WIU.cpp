#include "Game.h"
#include "CombatSystem.h"

#include <iostream>

int main()
{
    Game game;
    CombatSystem CombatSystem;


    //CombatSystem.printCombatScreen();
    while (true) {
        game.doTurn(CombatSystem);
    }

    return 0;
};