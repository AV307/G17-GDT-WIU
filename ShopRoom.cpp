#include "ShopRoom.h"

//Ang Zhi En 252317H
//Constructor for ShopRoom, defines position and sets up room
//Incomplete
ShopRoom::ShopRoom(int currentStage, int roomNumber)
{
    roomHeight = 20;
    roomWidth = 20;
    setRoomLocation(roomNumber);

    roomObjects = new RoomObjects(roomWidth, roomHeight);

    // dynamically allocate shopRoomArray
    shopRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        shopRoomArray[i] = new char[roomWidth];
    }

    roomObjects->addObjects(roomWidth, roomHeight, currentStage, 'S');
    placeRoomObjects(shopRoomArray);

    //add code below for setting up specific shop related parts
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
    int key;        // store _getch() safely in int
    char choice;

    while (true) {
        system("cls");  // clear console

        // ===== ASCII Shop Frame =====
        std::cout <<
            "--------------------------------------------------------------------------------------------------\n"
            "--------------------------------------------------------------------------------------------------\n"
            "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "||                                                                                              ||\n"
            "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
            "==================================================================================================\n"
            "= --------------------- ------------------------ ------------------------ ---------------------- =\n"
            "= |      Armour       | |        Weapon        | |        Potion        | |      Artifact      | =\n"
            "= --------------------- ------------------------ ------------------------ ---------------------- =\n"
            "==================================================================================================\n"
            "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

        // Display player gold
        std::cout << "Gold: " << player->getGold() << "\n\n";

        // Display all items with numbers 6–9
        std::cout << "6. " << itemNames[0] << " (" << itemPrices[0] << " gold)\n";
        std::cout << "7. " << itemNames[1] << " (" << itemPrices[1] << " gold)\n";
        std::cout << "8. " << itemNames[2] << " (" << itemPrices[2] << " gold)\n";
        std::cout << "9. " << itemNames[3] << " (" << itemPrices[3] << " gold)\n";
        std::cout << "0. Exit Shop\n";

        std::cout << "\nChoose item: ";
        key = _getch();                  // wait for single key press
        choice = static_cast<char>(key); // cast to char for comparison
        std::cout << choice << "\n";     // echo pressed key

        if (choice == '0') break;

        int index = -1;
        if (choice == '6') index = 0;
        else if (choice == '7') index = 1;
        else if (choice == '8') index = 2;
        else if (choice == '9') index = 3;

        if (index != -1) {
            if (player->getGold() >= itemPrices[index]) {
                player->setGold(player->getGold() - itemPrices[index]);
                player->addItemInventory(itemNames[index]);
                std::cout << "You bought a " << itemNames[index]
                    << " for " << itemPrices[index] << " gold!\n";
            }
            else {
                std::cout << "Not enough gold!\n";
            }
        }
        else {
            std::cout << "Invalid choice!\n";
        }

        // Wait for key press before refreshing menu
        int temp = _getch();
        (void)temp; // avoid compiler warning for unused variable
    }

    // Print inventory after exiting shop
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

