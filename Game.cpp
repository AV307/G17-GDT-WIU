#include "Game.h"
#include <iostream>
#include <string>
#include <windows.h>

#include <sstream>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Game::Game() 
{
    currentStage = 0;
    stage = new Stage(this);
    stage->printStage();
}

Game::~Game() {
    delete stage;
}

int Game::getCurrentStage()
{
    return currentStage;
}

void Game::doTurn()
{
    plr.doAction();

    system("cls");

    bool inventoryOpen = plr.checkInventoryOpen();
    int menuIndex = plr.getMenuIndex();
    int inventoryIndex = plr.getInventoryIndex();

    Item** weapons = plr.getWeapons();
    Item** armours = plr.getArmours();
    Item** consumables = plr.getConsumables();

    if (inventoryOpen == true) {
        std::cout << "+----------------------------------------+" << std::endl;
        switch (menuIndex) {
        case 1:
            for (int i = 0; i < 10; i++) {
                std::cout << "|";
                std::cout << i + 1 << ". ";
                if (weapons[i]->isOwned() == true) {
                    SetConsoleTextAttribute(hConsole, (inventoryIndex == i) ? 14 : 7);
                    std::cout << weapons[i]->getName();
                    std::cout << " (";
                    std::cout << weapons[i]->getAttackVal();
                    std::cout << " Attack)";
                    if (weapons[i]->isEquipped() == true) {
                        std::cout << " [Equipped]";
                    }
                    SetConsoleTextAttribute(hConsole, 7);

                    int nameLength = weapons[i]->getName().length();
                    int numLength = std::to_string(i + 1).length();
                    int attackLength = std::to_string(weapons[i]->getAttackVal()).length();
                    int equipLength = 0;
                    (weapons[i]->isEquipped() == true) ? equipLength = 10 : equipLength = 0;

                    int remainingSpaces = 40 - (nameLength + numLength + attackLength + equipLength + 13);
                    for (int j = 0; j < remainingSpaces; j++) {
                        std::cout << " ";
                    }
                }
                else {
                    int numLength = std::to_string(i + 1).length();

                    for (int j = 0; j < (39 - numLength); j++) {
                        std::cout << " ";
                    }
                }

                std::cout << "|" << std::endl;
            }
            break;
        case 2:
            for (int i = 0; i < 10; i++) {
                std::cout << "|";
                std::cout << i + 1 << ". ";
                if (armours[i]->isOwned()) {
                    SetConsoleTextAttribute(hConsole, (inventoryIndex == i) ? 14 : 7);
                    std::cout << armours[i]->getName();
                    std::cout << " (";
                    std::cout << armours[i]->getDefenseVal();
                    std::cout << " Attack)";
                    if (armours[i]->isEquipped() == true) {
                        std::cout << " [Equipped]";
                    }
                    SetConsoleTextAttribute(hConsole, 7);

                    int nameLength = armours[i]->getName().length();
                    int numLength = std::to_string(i + 1).length();
                    int defenseLength = std::to_string(armours[i]->getDefenseVal()).length();
                    int equipLength = 0;
                    (armours[i]->isEquipped() == true) ? equipLength = 10 : equipLength = 0;

                    int remainingSpaces = 39 - (nameLength + numLength + defenseLength + equipLength + 13);
                    for (int j = 0; j < remainingSpaces; j++) {
                        std::cout << " ";
                    }
                }
                else {
                    int numLength = std::to_string(i + 1).length();

                    for (int j = 0; j < (39 - numLength); j++) {
                        std::cout << " ";
                    }
                }

                std::cout << "|" << std::endl;
            }
            break;
        case 3:
            for (int i = 0; i < 10; i++) {
                std::cout << "|";
                std::cout << i + 1 << ". ";
                if (consumables[i]->isOwned()) {
                    SetConsoleTextAttribute(hConsole, (inventoryIndex == i) ? 14 : 7);
                    std::cout << consumables[i]->getName();
                    std::cout << " (";
                    std::cout << consumables[i]->getDefenseVal();
                    std::cout << " Defense)";
                    SetConsoleTextAttribute(hConsole, 7);
                    int nameLength = consumables[i]->getName().length();
                    int numLength = std::to_string(i + 1).length();
                    int defenseLength = std::to_string(consumables[i]->getDefenseVal()).length();

                    int remainingSpaces = 39 - (nameLength + numLength + defenseLength + 12);
                    for (int j = 0; j < remainingSpaces; j++) {
                        std::cout << " ";
                    }
                }
                else {
                    int numLength = std::to_string(i + 1).length();

                    for (int j = 0; j < (39 - numLength); j++) {
                        std::cout << " ";
                    }
                }

                std::cout << "|" << std::endl;
            }
            break;
        default:
            break;
        }

        std::cout << "+----------------------------------------+" << std::endl;
        std::cout << "+------------+" << "+------------+" << "+------------+" << std::endl;
        std::cout << "+";
        SetConsoleTextAttribute(hConsole, (menuIndex == 1) ? 14 : 7);
        std::cout << "   Weapons  ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "++";
        SetConsoleTextAttribute(hConsole, (menuIndex == 2) ? 14 : 7);
        std::cout << "   Armour   ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "++";
        SetConsoleTextAttribute(hConsole, (menuIndex == 3) ? 14 : 7);
        std::cout << "   Potions  ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "+" << std::endl;
        std::cout << "+------------+" << "+------------+" << "+------------+" << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
    }

    SetConsoleTextAttribute(hConsole, 7);

    //plr.setAttack()
}
