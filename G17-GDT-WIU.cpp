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
        do {
            game.printBriefingMenu();
        } while (proceed != '0');

        while (game.getEndGame() == false) {
            game.doTurn(CombatSystem);
        };
    }

    return 0;
};