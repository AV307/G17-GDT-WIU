#include "BossRoom.h"

BossRoom::BossRoom(int currentStage)
{
    roomHeight = 30;
    roomWidth = 30;
    roomTopLeftX = 10;
    roomTopLeftY = 30;

    // dynamically allocate bossRoomArray
    bossRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        bossRoomArray[i] = new char[roomWidth];
    }

    // set empty room
    for (int i{ 0 }; i < roomHeight; i++)
    {
        for (int j{ 0 }; j < roomWidth; j++)
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1)
            {
                bossRoomArray[i][j] = 'O'; // set to wall
            }
            else
            {
                bossRoomArray[i][j] = ' '; // set to space
            }
        }
    }

    // more code here to determine and set specifics in the main room
    switch (currentStage)
    {
    }
}

BossRoom::~BossRoom()
{
    // deallocate bossRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] bossRoomArray[i];
    }
    delete[] bossRoomArray;
}

char** BossRoom::getBossRoomArray()
{
    return bossRoomArray;
}
