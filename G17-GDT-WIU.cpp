#include "Game.h"
#include <iostream>
#include "CombatSystem.h"

int main()
{
    Game game;
    CombatSystem CombatSystem;


    //CombatSystem.printCombatScreen();
    while (true) {
        game.doTurn();
    }

    return 0;
};