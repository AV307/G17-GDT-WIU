#include "ShopRoom.h"
#include "Player.h"
#include <windows.h>
#include <conio.h>


//Ang Zhi En 252317H
//Constructor for ShopRoom, defines position and sets up room
//Incomplete
ShopRoom::ShopRoom(int currentStage, int roomNumber)
{
    roomHeight = 20;
    roomWidth = 20;
    setRoomLocation(roomNumber);

    roomObjects = new RoomObjects(true, roomTopLeftY, roomWidth, roomHeight);

    // dynamically allocate shopRoomArray
    shopRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        shopRoomArray[i] = new char[roomWidth];
    }

    roomObjects->addObjects(roomWidth, roomHeight, currentStage, 'S');
    placeRoomObjects(shopRoomArray);

    //Benjamin 250572M 
    // Initialize shop items (weapons)
    // Name, Atk buff, Cr buff, Cd buff;
    shopInventory[0] = new Weapon("Sword", 10, 0, 0);
    shopInventory[0]->setCost(50);
    shopInventory[1] = new Weapon("Mace", 10, 0, 20);
    shopInventory[1]->setCost(50);
    shopInventory[2] = new Weapon("Scythe", 15, 0, 0);
    shopInventory[2]->setCost(50);
    shopInventory[3] = new Weapon("Warhammer", 25, 20, 50);
    shopInventory[3]->setCost(50);

    shopInventory[4] = new Item("Heal Potion", "Buff", 30);           // price 30 gold
    shopInventory[5] = new Item("Strength Potion", "Buff", 25);       // price 25 gold
    shopInventory[6] = new Item("Weakening Potion", "Debuff", 20);    // price 20 gold
    shopInventory[7] = new Item("Sleep Potion", "Debuff", 40);        // price 40 gold
    shopInventory[8] = new Item("Key", "Key", 30);                     // price 30 gold

    // Set remaining shopInventory slots to nullptr to avoid undefined pointers
    for (int i = 9; i < 20; i++) {
        shopInventory[i] = nullptr;
    }
}




//Ang Zhi En 252317H
//Destructor for ShopRoom, deletes pointers
//Incomplete
ShopRoom::~ShopRoom()
{
    // deallocate shopRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] shopRoomArray[i];
    }
    delete[] shopRoomArray;
}

//Ang Zhi En 252317H
//getter for shopRoomArray
char** ShopRoom::getShopRoomArray()
{
	return shopRoomArray;
}



    //Benjamin 250572M
    //Displays the shop menu with items and prices
    void ShopRoom::showShopMenu(Player* player) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int key;        // store _getch() safely in int
        char choice;
        const string itemSelection[4] = {"Armour", "Weapon", "Potion", "Artifact"};
        string currentSelection = itemSelection[0];
        SetConsoleTextAttribute(hConsole, 7);

        while (player->checkShopOpen()) {
            system("cls");  // clear console

            // ===== ASCII Shop Frame =====
            //std::cout <<
            //    "--------------------------------------------------------------------------------------------------\n"
            //    "--------------------------------------------------------------------------------------------------\n"
            //    "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "||                                                                                              ||\n"
            //    "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
            //    "==================================================================================================\n"
            //    "= --------------------- ------------------------ ------------------------ ---------------------- =\n"
            //    "= |      "
            //    << SetConsoleTextAttribute(hConsole, (currentSelection == itemSelection[0]) ? 14 : 7) << 
            //    "       | |        " 
            //    << SetConsoleTextAttribute(hConsole, (currentSelection == itemSelection[1]) ? 14 : 7) <<
            //    "        | |        " 
            //    << SetConsoleTextAttribute(hConsole, (currentSelection == itemSelection[2]) ? 14 : 7) <<
            //    "        | |      "
            //    << SetConsoleTextAttribute(hConsole, (currentSelection == itemSelection[0]) ? 14 : 7) <<
            //    "      | =\n"
            //    "= --------------------- ------------------------ ------------------------ ---------------------- =\n"
            //    "==================================================================================================\n"
            //    "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

            // Display player gold
            std::cout << "Gold: " << player->getGold() << "\n\n";

            // Display shop items dynamically
            for (int i = 0; i < 10; i++) {
                if (shopInventory[i] != nullptr) {
                    std::cout << i + 1 << ". "
                        << shopInventory[i]->getName()
                        << " (" << shopInventory[i]->getCost() << " gold)\n";
                }
            }
            std::cout << "0. Exit Shop\n\n";
            std::cout << "Choose item: ";

            key = _getch();
            choice = static_cast<char>(key);
            std::cout << choice << "\n";

            if (choice == '0') {
                player->setShopOpen(false);
                return;
            };

            /*currentSelection = itemSelection[choice];*/
      

            int index = choice - 1; 
            // Convert char '1'-'9' to index 0-8
            if (index >= 0 && index < 10 && shopInventory[index] != nullptr) {
                Item* item = shopInventory[index];
                if (player->getGold() >= item->getCost()) {
                    player->setGold(player->getGold() - item->getCost());
                    player->addItemInventory(item);
                    std::cout << "You bought a " << item->getName()
                        << " for " << item->getCost() << " gold!\n";
                }
                else {
                    std::cout << "Not enough gold!\n";
                }
            }
            else {
                std::cout << "Invalid choice!\n";
            }

            std::cout << "Press any key to continue...";
            int temp = _getch();
            (void)temp;
        }

        player->printInventory();

    }





//  Caleb 250601F 
//  Shop Menu design
//  --------------------------------------------------------------------------------------------------
//  --------------------------------------------------------------------------------------------------
//  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||              
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ||                                                                                              ||
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^                                                                                   ||
//  ==================================================================================================
//  = --------------------- ------------------------ ------------------------ ---------------------- =
//  = |      Armour       | |        Weapon        | |        Potion        | |      Artifact      | =
//  = --------------------- ------------------------ ------------------------ ---------------------- =
//  ==================================================================================================
//  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Debug code

