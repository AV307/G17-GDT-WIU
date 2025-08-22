#include "Game.h"
#include "Item.h"
#include "CombatSystem.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Ang Zhi En 252317H
//Constructor for Game, creates a stage for the game
//Incomplete
Game::Game() 
{
    //set to 3 or 5 to test the boss rooms
    currentStage = 1;
    plr = new Player;
    stage = new Stage(this, plr);
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
void Game::doTurn(CombatSystem combatsystem)
{
    stage->updateStageArray(plr);

    system("cls");

    bool inventoryOpen = plr->checkInventoryOpen();
    bool hasKey = plr->checkKey();

    int menuIndex = plr->getMenuIndex();
    int inventoryIndex = plr->getInventoryIndex();

    Item** inventoryMenuArray = nullptr;

    if (inventoryOpen == true) {
        std::cout << "+------------------------------------------------------+" << '\n';
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
            std::cout << "|" << '\n';
        }

        // Inventory Menus

        std::cout << "+------------------------------------------------------+" << '\n';
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

    // Entering Combat System Check and Trigger

    if (plr->getIsInCombat()) {                                                                        // If the player enters combat
        combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());                                 // Print the starting screen where all values are at base
        while (plr->getIsInCombat()) {                                                                 // While the player remains in combat
            char combatKeyPress = _getch();                                                            // To receive player's input during battle
            switch (combatKeyPress) {
            case 'f':
                combatsystem.fightPVE(*plr, *plr->getCurrentEnemy());                                  // Activate Fight Function if player presses F
                break;
            case 'i':
                combatsystem.itemPVE(*plr, *plr->getCurrentEnemy());                                   // Activate Item Function if player presses I
                break;
            case 'r':
                combatsystem.runPVE(*plr, *plr->getCurrentEnemy());                                    // Activate Run Function if player presses R
                break;
            default:
                combatsystem.setTextDialogue("Invalid input!");
                break;
            }
            
            combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());                             // Update combat screen

            if (combatsystem.winLoseCondition(*plr, *plr->getCurrentEnemy()) == true) {                // If Player dies or both Player and Enemy die
                exit(0);                                                                               // Else, do not end the program
            }

            if (plr->getCombatIsWon()) {                                                               // Once a player has won, then end the combat system
                plr->setIsInCombat(false);
                plr->setCombatIsWon(false);
                plr->setJustLeftCombat(true);
            }
                                                                                                       // If none of these conditions are met, continue combat system until one happens
        }
    }
    
    // Exiting Combat (Win/Lose Condition)

    
}


