#include "BedRoom.h"

BedRoom::BedRoom(int currentStage)
{
    roomHeight = 20;
    roomWidth = 20;
    roomTopLeftX = 50;
    roomTopLeftY = 30;

    // dynamically allocate bedRoomArray
    bedRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        bedRoomArray[i] = new char[roomWidth];
    }

    // set empty room
    for (int i{ 0 }; i < roomHeight; i++)
    {
        for (int j{ 0 }; j < roomWidth; j++)
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1)
            {
                bedRoomArray[i][j] = 'O'; // set to wall
            }
            else
            {
                bedRoomArray[i][j] = ' '; // set to space
            }
        }
    }

    // more code here to determine and set specifics in the main room
    switch (currentStage)
    {
    }
}

BedRoom::~BedRoom()
{
    // deallocate bedRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] bedRoomArray[i];
    }
    delete[] bedRoomArray;
}

char** BedRoom::getBedRoomArray()
{
    return bedRoomArray;
}
