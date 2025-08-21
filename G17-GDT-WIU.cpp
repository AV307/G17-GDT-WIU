#include "Game.h"
#include "CombatSystem.h"

#include <Windows.h>
#include <iostream>

int main()
{
    // Get the input handle
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prev_mode;
    GetConsoleMode(hInput, &prev_mode);

    // Turn off Quick Edit and insert mode
    DWORD new_mode = prev_mode;
    new_mode &= ~ENABLE_QUICK_EDIT_MODE;
    new_mode &= ~ENABLE_INSERT_MODE;

    SetConsoleMode(hInput, new_mode);

    Game game;
    CombatSystem CombatSystem;


    //CombatSystem.printCombatScreen();
    while (true) {
        game.doTurn();
    }

    return 0;
};