#include "Game.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Ang Zhi En 252317H
//Constructor for Game, creates a stage for the game
//Incomplete
Game::Game() 
{
    //set to 3 or 5 to test the boss rooms
    currentStage = 1;
    stage = new Stage(this);
    stage->printStage(); //debugging code
}

//Ang Zhi En 252317H
//Destructor for Game, delete pointers
//Incomplete
Game::~Game() {
    delete stage;
}

//Ang Zhi En 252317H
//Getter for currentStage
int Game::getCurrentStage()
{
    return currentStage;
}


//Jayren 250920U
//Does a turn. if inventory is open, gameplay pauses, player movement keys control the inventory menu
void Game::doTurn()
{
    plr.doAction();

    system("cls");

    bool inventoryOpen = plr.checkInventoryOpen();
    bool hasKey = plr.checkKey();

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
                    (weapons[i]->isEquipped() == true) ? equipLength = 11 : equipLength = 0;

                    int remainingSpaces = 40 - (nameLength + numLength + attackLength + equipLength + 12);
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
                    std::cout << " Defense)";
                    if (armours[i]->isEquipped() == true) {
                        std::cout << " [Equipped]";
                    }
                    SetConsoleTextAttribute(hConsole, 7);

                    int nameLength = armours[i]->getName().length();
                    int numLength = std::to_string(i + 1).length();
                    int defenseLength = std::to_string(armours[i]->getDefenseVal()).length();
                    int equipLength = 0;
                    (armours[i]->isEquipped() == true) ? equipLength = 11 : equipLength = 0;

                    int remainingSpaces = 39 - (nameLength + numLength + defenseLength + equipLength + 12);
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
                if (consumables[i] != nullptr) {
                    SetConsoleTextAttribute(hConsole, (inventoryIndex == i) ? 14 : 7);
                    std::cout << consumables[i]->getName();
                    SetConsoleTextAttribute(hConsole, 7);
                    int nameLength = consumables[i]->getName().length();
                    int numLength = std::to_string(i + 1).length();

                    int remainingSpaces = 39 - (nameLength + numLength + 1);
                    for (int j = 0; j < remainingSpaces; j++) {
                        std::cout << " ";
                    }
                }
                else {
                    int numLength = std::to_string(i + 1).length();

                    for (int j = 0; j < (38 - numLength); j++) {
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
        std::cout << "| ";
        if (hasKey == true) {
            std::cout << "            Player Has Key" << "            |";
        }
        else {
            std::cout << "       Player does not have Key" << "        |";
        }
        std::cout << std::endl;
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

    plr.updateStats();
}


