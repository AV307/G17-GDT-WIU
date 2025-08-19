#include "ShopRoom.h"

ShopRoom::ShopRoom(int currentStage)
{
    roomHeight = 20;
    roomWidth = 20;
    roomTopLeftX = 50;
    roomTopLeftY = 30;

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

    // more code here to determine and set specifics in the main room
    switch (currentStage)
    {
    }
}

ShopRoom::~ShopRoom()
{
    // deallocate bedRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] shopRoomArray[i];
    }
    delete[] shopRoomArray;
}

char** ShopRoom::getShopRoomArray()
{
	return shopRoomArray;
}
