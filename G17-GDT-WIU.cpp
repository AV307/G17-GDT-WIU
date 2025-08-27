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
    game.printStartMenu();
    char proceed = _getch();

    if (proceed == '0') {
        game.printBriefingMenu();
        char proceed2 = _getch();
        if (proceed2 == '0')
            while (true) {
                game.doTurn(CombatSystem);
            }
    }

    return 0;
};