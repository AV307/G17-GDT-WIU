#include "BossRoom.h"

//Ang Zhi En 252317H
//Constructor for BossRoom, defines the position and sets up the room
//Incomplete
BossRoom::BossRoom(int currentStage)
{
    roomHeight = 30;
    roomWidth = 30;
    roomTopLeftX = 0; //dependant on whether room 1 or 2, incomplete
    roomTopLeftY = 0;

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

    // boss selection will depend on whether stage 3 or 5, getting harder
    switch (currentStage)
    {
    }
}

//Ang Zhi En 252317H
//Destructor for BossRoom, deletes pointers
//Incomplete
BossRoom::~BossRoom()
{
    // deallocate bossRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] bossRoomArray[i];
    }
    delete[] bossRoomArray;
}

//Ang Zhi En 252317H
//BossRoom array getter
char** BossRoom::getBossRoomArray()
{
    return bossRoomArray;
}
