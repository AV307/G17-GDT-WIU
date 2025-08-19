#include "ShopRoom.h"

//Ang Zhi En 252317H
//Constructor for ShopRoom, defines position and sets up room
//Incomplete
ShopRoom::ShopRoom(int currentStage)
{
    roomHeight = 20;
    roomWidth = 20;
    roomTopLeftX = 0; //dependant on room number
    roomTopLeftY = 0;

    // dynamically allocate shopRoomArray
    shopRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        shopRoomArray[i] = new char[roomWidth];
    }

    // set empty room
    for (int i{ 0 }; i < roomHeight; i++)
    {
        for (int j{ 0 }; j < roomWidth; j++)
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1)
            {
                shopRoomArray[i][j] = 'O'; // set to wall
            }
            else
            {
                shopRoomArray[i][j] = ' '; // set to space
            }
        }
    }

    //add code below for setting up specific shop related parts
}

//Ang Zhi En 252317H
//Destructor for ShopRoom, deletes pointers
//Incomplete
ShopRoom::~ShopRoom()
{
    // deallocate bedRoomArray
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
