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
    plr = new Player;
    stage = new Stage(this);
    stage->printStage(); //debugging code
}

//Ang Zhi En 252317H
//Destructor for Game, delete pointers
//Incomplete
Game::~Game() {
    delete stage;
    delete plr;
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
    plr->doAction();

    system("cls");

    bool inventoryOpen = plr->checkInventoryOpen();
    bool hasKey = plr->checkKey();

    int menuIndex = plr->getMenuIndex();
    int inventoryIndex = plr->getInventoryIndex();

    Item** inventoryMenuArray = nullptr;

    if (inventoryOpen == true) {
        std::cout << "+------------------------------------------------------+" << std::endl;
        switch (menuIndex) {
        case 1:
            inventoryMenuArray = plr->getWeapons();
            break;
        case 2:
            inventoryMenuArray = plr->getArmours();
            break;
        case 3:
            inventoryMenuArray = plr->getConsumables();
            break;
        case 4:
            inventoryMenuArray = plr->getArtifacts();
            break;
        default:
            break;
        }

        // Inventory Items

        for (int i = 0; i < 10; i++) {
            std::cout << "|";
            std::cout << i + 1 << ". ";
            SetConsoleTextAttribute(hConsole, (inventoryIndex == i) ? 14 : 7);
            if (inventoryMenuArray[i] != nullptr) {
                std::cout << inventoryMenuArray[i]->getName();
                if (inventoryMenuArray[i]->getAttackVal() != 0) {
                    std::cout << " (";
                    std::cout << inventoryMenuArray[i]->getAttackVal();
                    std::cout << " Attack)";
                }
                if (inventoryMenuArray[i]->getDefenseVal() != 0) {
                    std::cout << " (";
                    std::cout << inventoryMenuArray[i]->getDefenseVal();
                    std::cout << " Defense)";
                }
                if (inventoryMenuArray[i]->isEquipped() == true) {
                    std::cout << " [Equipped]";
                }
                int nameLength = inventoryMenuArray[i]->getName().length();
                int numLength = std::to_string(i + 1).length();
                int attackLength = std::to_string(inventoryMenuArray[i]->getAttackVal()).length();
                int defenseLength = std::to_string(inventoryMenuArray[i]->getDefenseVal()).length();
                int equipLength = 0;
                (inventoryMenuArray[i]->isEquipped() == true) ? equipLength = 11 : equipLength = 0;
                (inventoryMenuArray[i]->getAttackVal() == 0) ? attackLength = 0 : attackLength += 10;
                (inventoryMenuArray[i]->getDefenseVal() == 0) ? defenseLength = 0 : defenseLength += 11;

                int remainingSpaces = 54 - (nameLength + numLength + equipLength + attackLength + defenseLength + 2);
                for (int j = 0; j < remainingSpaces; j++) {
                    std::cout << " ";
                }
            }
            else {
                std::cout << "Empty";
                int numLength = std::to_string(i + 1).length();

                for (int j = 0; j < (52 - numLength - 5); j++) {
                    std::cout << " ";
                }
            }

            SetConsoleTextAttribute(hConsole, 7);
            std::cout << "|" << std::endl;
        }

        // Inventory Menus

        std::cout << "+------------------------------------------------------+" << std::endl;
        std::cout << "| ";
        if (hasKey == true) {
            std::cout << "                   Player Has Key" << "                    |";
        }
        else {
            std::cout << "               Player does not have Key" << "              |";
        }
        std::cout << std::endl;
        std::cout << "+------------+" << "+------------+" << "+------------+" << "+------------+" << std::endl;
        std::cout << "+";
        SetConsoleTextAttribute(hConsole, (menuIndex == 1) ? 14 : 7);
        std::cout << "   Weapon   ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "++";
        SetConsoleTextAttribute(hConsole, (menuIndex == 2) ? 14 : 7);
        std::cout << "   Armour   ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "++";
        SetConsoleTextAttribute(hConsole, (menuIndex == 3) ? 14 : 7);
        std::cout << "   Potion   ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "++";
        SetConsoleTextAttribute(hConsole, (menuIndex == 4) ? 14 : 7);
        std::cout << "  Artifact  ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "+" << std::endl;
        std::cout << "+------------+" << "+------------+" << "+------------+" << "+------------+" << std::endl;
        std::cout << "+------------------------------------------------------+" << std::endl;
    }
    else {
        stage->printStage();
    }

    SetConsoleTextAttribute(hConsole, 7);

    plr->updateStats();
}


