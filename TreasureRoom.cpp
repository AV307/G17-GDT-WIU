#include "TreasureRoom.h"
#include<iostream>


//Ang Zhi En 252317H
//Constructor for TreasureRoom, set position and sets up the room
//Incomplete
TreasureRoom::TreasureRoom(int currentStage, int roomNumber)
{
    roomHeight = 20;
    roomWidth = 20;
    setRoomLocation(roomNumber);

    roomObjects = new RoomObjects(roomWidth, roomHeight);

    // dynamically allocate treasureRoomArray
    treasureRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        treasureRoomArray[i] = new char[roomWidth];
    }

    placeRoomObjects(treasureRoomArray);

    //add code for setting up treasure room (chest)
}

//Ang Zhi En 252317H
//Destructor for TreasureRoom, deletes pointers
//Incomplete
TreasureRoom::~TreasureRoom() {
    // deallocate treasureRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] treasureRoomArray[i];
    }
    delete[] treasureRoomArray;
}

//Ang Zhi En 252317H
//Getter for treasureRoomArray
char** TreasureRoom::getTreasureRoomArray()
{
	return treasureRoomArray;
}



int chestCounter = 0; // put this in TreasureRoom.cpp (or static in class)

//Benjamin 250572M
// function that checks if player has key to unlock the treasure chest

void TreasureRoom::openChest(Player* player) {
    if (player->checkKey()) {
        chestCounter++;

        if (chestCounter % 3 == 1) {
            player->setGold(player->getGold() + 200);
            std::cout << "You found 200 gold!\n";
        }
        else if (chestCounter % 3 == 2) {
            player->addWeapon("Steel Axe", 15);
            std::cout << "You found a Steel Axe!\n";
        }
        else {
            player->addConsumable("Healing potion", 25, 25, 25);
            std::cout << "You found a Healing Potion!\n";
        }
    }
    else {
        std::cout << "The chest is locked. You need a key!\n";
    }
}
