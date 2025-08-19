#include "TreasureRoom.h"
TreasureRoom::TreasureRoom(int currentStage)
{
    roomHeight = 20;
    roomWidth = 20;
    roomTopLeftX = 0;
    roomTopLeftY = 30;

    // dynamically allocate treasureRoomArray
    treasureRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        treasureRoomArray[i] = new char[roomWidth];
    }

    // set empty room
    for (int i{ 0 }; i < roomHeight; i++)
    {
        for (int j{ 0 }; j < roomWidth; j++)
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1)
            {
                treasureRoomArray[i][j] = 'O'; // set to wall
            }
            else
            {
                treasureRoomArray[i][j] = ' '; // set to space
            }
        }
    }

    // more code here to determine and set specifics in the main room
    switch (currentStage)
    {
    }
}

TreasureRoom::~TreasureRoom() {
    // deallocate treasureRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] treasureRoomArray[i];
    }
    delete[] treasureRoomArray;
}

char** TreasureRoom::getTreasureRoomArray()
{
	return treasureRoomArray;
}
