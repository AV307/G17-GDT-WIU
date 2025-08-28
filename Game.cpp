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
Game::Game()
{
    //set to 3 or 5 to test the boss rooms
    currentStage = 1;
    plr = new Player;
    stage = new Stage(this, plr);
    endGame = false;
    //stage->printStage();
}

//Ang Zhi En 252317H
//Destructor for Game, delete pointers
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

    bool pauseOpen = plr->checkPauseOpen();
    bool inventoryOpen = plr->checkInventoryOpen();
    bool shopOpen = plr->checkShopOpen();

    bool hasKey = plr->checkHasKey();
    bool hasHammer = plr->checkHasHammer();

    int menuIndex = plr->getMenuIndex();
    int inventoryIndex = plr->getInventoryIndex();

    Item** inventoryMenuArray = nullptr;
    if (currentStage > 5) {
        system("cls");

        Item** artifactArray = plr->getArtifacts();

        int rubberDuckyCount = 0;

        for (int i = 0; i < 10; i++) {
            if (artifactArray[i] != nullptr) {
                if (artifactArray[i]->getName() == "Rubber Duck") {
                    rubberDuckyCount++;
                }
            }
        }
        if (rubberDuckyCount > 4) {
            cout << "// +---------------------------------------------------------------------------------------------------+ //" << endl;
            cout << "// + You escaped, but something feels off... quickly, you noticed a light coming out of your backpack. + //" << endl;
            cout << "// +                   Upon opening it, the rubber duckies emitted a blinding light.                   + //" << endl;
            cout << "// +  When you came to, you realised you were back at the top, staring down at a collapsed dungeon...  + //" << endl;
            cout << "// +---------------------------------------[Press '0' to continue]-------------------------------------+ //" << endl;
            char confirm = _getch();

            if (confirm == '0') {
                cout << "// +                                                                             + //" << endl;
                cout << "// +   #####      #####        #     #     #               #   #    ##     #     + //" << endl;
                cout << "// +  #     #    #     #       #     #      #             #    #    # #    #     + //" << endl;
                cout << "// +  #          #             #     #       #     #     #     #    #  #   #     + //" << endl;
                cout << "// +  #    ###   #    ###      #     #        #   # #   #      #    #   #  #     + //" << endl;
                cout << "// +  #     #    #     #       #     #         # #   # #       #    #    # #     + //" << endl;
                cout << "// +   #####      #####         #####           #     #        #    #     ##     + //" << endl;
                cout << "// +                                                                             + //" << endl;
            }
            else {
                return;
            }
        }
        else {
            cout << "// +-----------------------------------------+ //" << endl;
            cout << "// + You escaped, but something feels off... + //" << endl;
            cout << "// +---------[Press '0' to continue]---------+ //" << endl;
            char confirm = _getch();

            if (confirm == '0') {
                cout << "// +                                                                             + //" << endl;
                cout << "// +   #####      #####        #     #     #               #   #    ##     #     + //" << endl;
                cout << "// +  #     #    #     #       #     #      #             #    #    # #    #     + //" << endl;
                cout << "// +  #          #             #     #       #     #     #     #    #  #   #     + //" << endl;
                cout << "// +  #    ###   #    ###      #     #        #   # #   #      #    #   #  #     + //" << endl;
                cout << "// +  #     #    #     #       #     #         # #   # #       #    #    # #     + //" << endl;
                cout << "// +   #####      #####         #####           #     #        #    #     ##     + //" << endl;
                cout << "// +                                                                             + //" << endl;
            }
            else {
                return;
            }
        }
        endGame = true;
    }
    else if (pauseOpen)
    {
        pauseGame();
    }
    else if (inventoryOpen == true) {
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
                size_t nameLength = inventoryMenuArray[i]->getName().length();
                size_t numLength = std::to_string(i + 1).length();
                size_t attackLength = std::to_string(inventoryMenuArray[i]->getAttackVal()).length();
                size_t defenseLength = std::to_string(inventoryMenuArray[i]->getDefenseVal()).length();
                int equipLength = 0;
                (inventoryMenuArray[i]->isEquipped() == true) ? equipLength = 11 : equipLength = 0;
                (inventoryMenuArray[i]->getAttackVal() == 0) ? attackLength = 0 : attackLength += 10;
                (inventoryMenuArray[i]->getDefenseVal() == 0) ? defenseLength = 0 : defenseLength += 11;

                size_t remainingSpaces = 54 - (nameLength + numLength + equipLength + attackLength + defenseLength + 2);
                for (int j = 0; j < remainingSpaces; j++) {
                    std::cout << " ";
                }
            }
            else {
                std::cout << "Empty";
                size_t numLength = std::to_string(i + 1).length();

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
    else if (shopOpen == true) {
    }
    else{
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
                plr->setHealth(plr->getHealth() + 5);                                                        // Player HP + 5 for every Stat Point
                break;
            case '2':
                ATKStat++;
                AvailablePts--;
                plr->setStatPoints(AvailablePts);
                plr->setAttack(plr->getAttack() + 2);                                                        // Player ATK + 2 for every Stat Point
                break;
            case '3':
                DEFStat++;
                AvailablePts--;
                plr->setStatPoints(AvailablePts);
                plr->setDefense(plr->getDefense() + 2);                                                      // Player DEF + 2 for every Stat Point
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

    if (plr->getIsInCombat()) {
        // If the player enters combat
        system("cls");

        combatsystem.setTextDialogue("You've been ambushed!");
        combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());                                 // Print the starting screen where all values are at base
        
        while (plr->getIsInCombat()) {                                                                 // While the player remains in combat

            char combatKeyPress = _getch();                                                            // To receive player's input during battle

            switch (combatKeyPress) {
            case 'f':
                combatsystem.fightPVE(*plr, *plr->getCurrentEnemy());                                  // Activate Fight Function if player presses F
                system("cls");
                break;
            case 'i':
                combatsystem.itemPVE(*plr, *plr->getCurrentEnemy());                                   // Activate Item Function if player presses I
                system("cls");
                break;
            case 'r': {

                system("cls");
                combatsystem.setTextDialogue("You're attempting to run, but you won't go unnoticed. Press Y/N to confirm");                       // Alerts player of their current action, also telling them there are consequences
                combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());
                // Handle Y/N for run confirmation

                char confirm = _getch();

               
                if (confirm == 'y' || confirm == 'Y') {
                    combatsystem.runPVE(*plr, *plr->getCurrentEnemy());

                }
                else if (confirm == 'n' || confirm == 'N') {
                    combatsystem.setTextDialogue("You snapped out of it, kept your head in the game.");

                }
                else {
                    continue;
                }
                
            

                system("cls");
                combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());

                break;
            }
            default:
                system("cls");
                combatsystem.setTextDialogue("Invalid input!");
                break;
            }
            
            
            system("cls");
            combatsystem.printCombatScreen(*plr, *plr->getCurrentEnemy());                             // Update combat screen

            if (combatsystem.winLoseCondition(*plr, *plr->getCurrentEnemy()) == true) {                // If Player dies or both Player and Enemy die
                plr->setIsInCombat(false);
                plr->setCombatIsWon(false);
                playerDied = true;                                                                     // Restart the stage
            }                                                                                          // Else, do not end the program

            if (plr->getCombatIsWon()) {                                                               // Once a player has won, then end the combat system
                plr->setIsInCombat(false);
                plr->setCombatIsWon(false);                                                            // Reset Player won state
                plr->setJustLeftCombat(true);   

                Entity* defeatedEnemy = plr->getCurrentEnemy();
                if (((Enemy*)defeatedEnemy)->getEnemyStatus() == 'S') {
					stage->setBossDefeated(true);
                }
            }
        }
    }

    if (playerDied == true) {
        restartStage(currentStage);
    }
}

Entity* Game::getCurrentEnemy() {
    return currentEnemies;
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

    system("cls");
    int randomHelpMessage = rand() % 3;
    cout << "// +-----------------------------------------------------------------------------+ //" << endl;
    cout << "// +                                                                             + //" << endl;
    cout << "// +               You died! Press any key to restart the stage!                 + //" << endl;
    cout << "// +                                                                             + //" << endl;
    if (randomHelpMessage == 0) {
        cout << "// +       Next time try running when you're outclassed, come back stronger      + //" << endl;
    }
    else if (randomHelpMessage == 1) {
        cout << "// +              Uhh, today might just not be your day, try again?              + //" << endl;
    }
    else {
        cout << "// +       You hear the calls of those who lost before you, keep going!          + //" << endl;
    }
    cout << "// +                                                                             + //" << endl;
    cout << "// +-----------------------------------------------------------------------------+ //" << endl;
    char confirm = _getch();
    if (confirm) {
        system("cls");
        stage->printStageWithFOV(plr, currentStage);
        std::cout << "Stage " << currentStage << " has been restarted." << std::endl;
    }
}

// Ang Zhi En 252317H
// Function that sends player into next stage
void Game::advanceStage() {
    currentStage++;
    delete stage;
    stage = nullptr;
    stage = new Stage(this, plr);
    stage->setBossDefeated(false);
}

// Update highest stage reached
void Game::getHighestStage(int currentStage)
{
    if (currentStage > highestStage) {
        highestStage = currentStage;
    }
    std::cout << "Highest Stage Reached: " << highestStage << std::endl;
}

bool Game::getEndGame()
{
    return endGame;
}

// Pause game
void Game::pauseGame() {
    int choice = 0;
    char key;

    while (plr->checkPauseOpen()) {
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
            case 0:
                system("cls");
                stage->printStageWithFOV(plr, currentStage);
                plr->setPauseOpen(false);
                return;
            case 1: 
                restartStage(currentStage);
                plr->setPauseOpen(false);
                return;
            case 2: exit(0);
            }
        }
    }
}