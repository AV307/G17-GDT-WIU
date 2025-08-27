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

void Game::printStartMenu() {
    system("cls");

    cout << "// +-------------------------------------------------------------------------------------------------------+ //" << endl;
    cout << "// +-------------------------------------------------------------------------------------------------------+ //" << endl;
    cout << "// +-------------------------------------------------------------------------------------------------------+ //" << endl;
    cout << "//                                                                                                           //" << endl;
    cout << "//                                        |>>>                     |>>>                                      //" << endl;
    cout << "//                                        |                        |                                         //" << endl;
    cout << "//                                    _  _|_  _                _  _|_  _                                     //" << endl;
    cout << "//                                   |;|_|;|_|;|              |;|_|;|_|;|                                    //" << endl;
    cout << R"(//                                   \\\\.  .  /              \\\\.  .  /                                    //)" << endl;
    cout << R"(//                                    \\\\:.  /                \\\\:.  /                                     //)" << endl;
    cout << "//                                     ||:   |                  ||:   |                                      //" << endl;
    cout << "//                                     ||:.  |                  ||:.  |                                      //" << endl;
    cout << "//                                     ||:  .|                  ||:  .|                                      //" << endl;
    cout << "//                                     ||:   |                  ||:   |                                      //" << endl;
    cout << "//                                     ||: , |        o         ||: , |                                      //" << endl;
    cout << "//                                    _||_   |       <|>       _||_   |                                      //" << endl;
    cout << R"(//               wWw   wWw            `---'`---'     / \       `---'`---'     wWw     wWw                    //)" << endl;
    cout << "// +_______________________________________________________________________________________________________+ //" << endl;
    cout << "// +                                                                                                       + //" << endl;
    cout << "// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+ //" << endl;
    cout << "// +wwwwwwwwwWwwwwwwWWwwwwWwwwwWwwwwwwwwwwwwwWWwwWwwwWwwwwwwwwwWwwwwwwwWWwwwwwwWwwWwwwWwwwWWwwwwwwwwWwwwwww+ //" << endl;
    cout << "// +-----------------------------------------[ Press '0' to Start ]----------------------------------------+ //" << endl;
    cout << "// +-------------------------------------------------------------------------------------------------------+ //" << endl;
}

void Game::printBriefingMenu() {
    system("cls");

    cout << "// +-----------------------------------------------------------------------------------+ //" << endl;
    cout << "// Welcome! You're a dungeon explorer about to start your conquest in this dangerous     //" << endl;
    cout << "// dungeon ahead of you.                                                                 //" << endl;
    cout << "//                                                                                       //" << endl;
    cout << "// Do beware though, you might not be alone in this journey, sneaky enemies are bound to //" << endl;
    cout << "// creep up on you somewhere along the way                                               //" << endl;
    cout << "//                                                                                       //" << endl;
    cout << "// Solve puzzles to get out of the room, there are a total of 5 different stages in this //" << endl;
    cout << "// dungeon. Legend has it, a boss is waiting for you somewhere, but a sacred treasure    //" << endl;
    cout << "// continues to pique your interest and curiousity                                       //" << endl;
    cout << "//                                                                                       //" << endl;
    cout << "// Find gear in certain rooms and treasures, or purchase them with the shopkeepers       //" << endl;
    cout << "// that are trapped in the dungeon, they'll be more than happt to assist you             //" << endl;
    cout << "//                                                                                       //" << endl;
    cout << "// Levelling up will allow you to further buff your abilities by awarding you Stat Points//" << endl;
    cout << "//                                                                                       //" << endl;
    cout << "// Are you ready to conquer the dungeon?                                                 //" << endl;
    cout << "//                                                                                       //" << endl;
    cout << "//                                [ Press '0' to continue ]                              //" << endl;
    cout << "// +-----------------------------------------------------------------------------------+ //" << endl;
}

//Jayren 250920U
//Does a turn. if inventory is open, gameplay pauses, player movement keys control the inventory menu
void Game::doTurn(CombatSystem combatsystem)
{
    stage->updateStageArray(plr, this);

    system("cls");

    bool inventoryOpen = plr->checkInventoryOpen();
    bool hasKey = plr->checkHasKey();
    bool hasHammer = plr->checkHasHammer();

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
        //Benjamin 250572M
        //opens shop menu if player is not in combat and presses 'P'
        if (!plr->getIsInCombat()) {
            char keyPress = _getch();

            switch (tolower(keyPress)) {
            case 'p': {
                // open the shop
                ShopRoom shop(currentStage, 0);
                shop.showShopMenu(plr);
                break;
            }
            case 'r':
                restartStage(currentStage);
                break;
            }
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
            std::cout << "                 Player Has Key" << "                      |";
        }
        else {
            std::cout << "              Player does not have Key" << "               |";
        }
		std::cout << '\n';
        std::cout << "| ";
        if (hasHammer == true) {
            std::cout << "                Player Has Hammer" << "                    |";
        }
        else {
            std::cout << "             Player does not have Hammer" << "             |";
        }
        std::cout << '\n';
        std::cout << "+------------+" << "+------------+" << "+------------+" << "+------------+" << '\n';
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
        std::cout << "+" << '\n';
        std::cout << "+------------+" << "+------------+" << "+------------+" << "+------------+" << '\n';
        std::cout << "+------------------------------------------------------+" << '\n';
    }
    else {
        stage->printStageWithFOV(plr, currentStage);
    }

    SetConsoleTextAttribute(hConsole, 7);

    plr->updateStats();

    // Skill Tree Function
    if (plr->checkSkillTreeOpen()) {
        int HPStat, ATKStat, DEFStat, AvailablePts;                                                          // Declare variables
        HPStat = 0;                                                                                          // Initialise
        ATKStat = 0;                                                                                         // Initialise
        DEFStat = 0;                                                                                         // Initialise
        AvailablePts = plr->getStatPoints();                                                                 // Initialise variable with how many Stat Points the player has

        while (plr->checkSkillTreeOpen() && AvailablePts > 0) {                                              // If the Skill Tree has been opened and the player has at least 1 Stat Point, then print the UI
            system("cls");

            std::cout << "// +---------------------------------------------------+ //" << std::endl;
            std::cout << "// + HP Stats: " << HPStat << std::endl;
            std::cout << "// + ATK Stats: " << ATKStat << std::endl;
            std::cout << "// + DEF Stats: " << DEFStat << std::endl;
            std::cout << "// +---------------------------------------------------+ //" << std::endl;
            std::cout << "// + Available Points: " << AvailablePts << std::endl;
            std::cout << "// +---------------------------------------------------+ //" << std::endl;

            int choice = _getch();                                                                           // Get player's input to decide where to put the Stat Point
            switch (choice) {
            case '1':
                HPStat++;
                AvailablePts--;
                plr->setStatPoints(AvailablePts);
                plr->setHealth(plr->getHealth() + 10);                                                       // Player HP + 10 for every Stat Point
                break;
            case '2':
                ATKStat++;
                AvailablePts--;
                plr->setStatPoints(AvailablePts);
                plr->setAttack(plr->getAttack() + 5);                                                        // Player ATK + 5 for every Stat Point
                break;
            case '3':
                DEFStat++;
                AvailablePts--;
                plr->setStatPoints(AvailablePts);
                plr->setDefense(plr->getDefense() + 5);                                                      // Player DEF + 5 for every Stat Point
                break;
            default:
                plr->setSkillTreeOpen(false);                                                                // Any other key, close the Skill Tree
                break;
            }
        }
    }

    // Entering Combat System Check and Trigger
    plr->checkCollision(*plr->getCurrentEnemy());
    bool playerDied = false;
    bool awaitingRunConfirm = false;

    int playerMayBeInCombat = rand() % 100 + 1;
    if (playerMayBeInCombat < 95) {                                                                    // Player has 95% chance to avoid combat
        plr->setIsInCombat(false);
    }
    else {                                                                                             // Player has 5% chance to enter combat
        plr->setIsInCombat(true);
    }

    if (plr->getIsInCombat()) {                                                                        // If the player enters combat
        combatsystem.setTextDialogue("You've been ambushed!");
        combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());                                 // Print the starting screen where all values are at base
        
        while (plr->getIsInCombat()) {                                                                 // While the player remains in combat

            char combatKeyPress = _getch();                                                            // To receive player's input during battle

            if (awaitingRunConfirm) {
                // Handle Y/N for run confirmation
                if (combatKeyPress == 'y' || combatKeyPress == 'Y') {
                    combatsystem.runPVE(*plr, *plr->getCurrentEnemy());
                }
                else {
                    combatsystem.setTextDialogue("You snapped out of it, kept your head in the game.");
                }
                awaitingRunConfirm = false; // go back to normal combat
                combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());
                continue;
            }

            switch (combatKeyPress) {
            case 'f':
                combatsystem.fightPVE(*plr, *plr->getCurrentEnemy());                                  // Activate Fight Function if player presses F
                system("cls");
                break;
            case 'i':
                combatsystem.itemPVE(*plr, *plr->getCurrentEnemy());                                   // Activate Item Function if player presses I
                system("cls");
                break;
            case 'r':
                combatsystem.setTextDialogue("You're attempting to run, but you won't go unnoticed. Press Y/N to confirm");                       // Alerts player of their current action, also telling them there are consequences
                combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());
                awaitingRunConfirm = true;

                break;
            default:
                combatsystem.setTextDialogue("Invalid input!");
                break;
            }
            
            combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());                             // Update combat screen

            if (combatsystem.winLoseCondition(*plr, *plr->getCurrentEnemy()) == true) {                // If Player dies or both Player and Enemy die
                plr->setIsInCombat(false);
                plr->setCombatIsWon(false);
                playerDied = true;                                                                     // Restart the stage
            }                                                                                          // Else, do not end the program

            if (plr->getCombatIsWon()) {                                                               // Once a player has won, then end the combat system
                plr->setIsInCombat(false);
                plr->setCombatIsWon(false);                                                            // Reset Player won state
                plr->setJustLeftCombat(true);                                                          // Give player invulnerability state until moving away
            }
                                                                                                       // If none of these conditions are met, continue combat system until one happens
        }
    }

    if (playerDied == true) {
        restartStage(currentStage);
    }
}

//Benjamin 250572M 
// Restart the stage
void Game::restartStage(int currentStage)
{
    if (stage != nullptr) {
        delete stage;
        stage = nullptr;
    }

    stage = new Stage(this, plr);   

    plr->resetStats();
    plr->setPosition(0, 0);

    stage->printStage();
    std::cout << "Stage " << currentStage << " has been restarted." << std::endl;
}

void Game::advanceStage() {
    currentStage++;
    delete stage;
    stage = new Stage(this, plr);
}

// Update highest stage reached
void Game::getHighestStage(int currentStage)
{
    if (currentStage > highestStage) {
        highestStage = currentStage;
    }
    std::cout << "Highest Stage Reached: " << highestStage << std::endl;
}

// Pause game
void Game::pauseGame() {
    int choice = 0;
    char key;

    while (true) {
        system("cls");

        std::cout << "+------------------------+\n";
        std::cout << "|        PAUSED          |\n";
        std::cout << "+------------------------+\n";

        SetConsoleTextAttribute(hConsole, (choice == 0) ? 14 : 7);
        std::cout << "| " << (choice == 0 ? "> " : "  ") << "Resume               |\n";

        SetConsoleTextAttribute(hConsole, (choice == 1) ? 14 : 7);
        std::cout << "| " << (choice == 1 ? "> " : "  ") << "Restart Stage        |\n";

        SetConsoleTextAttribute(hConsole, (choice == 2) ? 14 : 7);
        std::cout << "| " << (choice == 2 ? "> " : "  ") << "Quit                 |\n";

        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "+------------------------+\n";

        key = _getch();

        if (key == 'w' || key == 'W') choice = (choice == 0) ? 2 : choice - 1;
        else if (key == 's' || key == 'S') choice = (choice == 2) ? 0 : choice + 1;
        else if (key == 13) {
            switch (choice) {
            case 0: return;
            case 1: restartStage(currentStage); return;
            case 2: exit(0);
            }
        }
    }
}