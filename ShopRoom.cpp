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
    int choice;

    while (true) {
        system("cls");  // clear console
        cout << "====== SHOP ======\n";
        cout << "Gold: " << player->getGold() << "\n\n";

        // Display all items with numbers 6–9
        cout << "6. " << itemNames[0] << "Sword " << itemPrices[0] << " gold\n";    //user needs to enter 6, 7, 8
        cout << "7. " << itemNames[1] << "Shield" << itemPrices[1] << " gold\n";
        cout << "8. " << itemNames[2] << "Potion" << itemPrices[2] << " gold\n";
        cout << "9. " << itemNames[3] << "Bow" << itemPrices[3] << " gold\n";
        cout << "0. Exit Shop\n";

        cout << "Choose item: ";
        cin >> choice;

        if (choice == 0) break;

        int index = -1;
        if (choice == 6) index = 0;
        else if (choice == 7) index = 1;
        else if (choice == 8) index = 2;
        else if (choice == 9) index = 3;

        if (index != -1) {
            if (player->getGold() >= itemPrices[index]) {
                player->setGold(player->getGold() - itemPrices[index]);
                player->addItemInventory(itemNames[index]);
                cout << "You bought a " << itemNames[index]
                    << " for " << itemPrices[index] << " gold!\n";
            }
            else {
                cout << "Not enough gold!\n";
            }
        }
        else {
            cout << "Invalid choice!\n";
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    player->printInventory();
}
