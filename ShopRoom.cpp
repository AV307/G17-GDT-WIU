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
