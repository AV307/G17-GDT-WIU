#include "BedRoom.h"

//Ang Zhi En 252317H
//Constructor for bedRoom, defines the position and sets up the room
//Incomplete
BedRoom::BedRoom(int currentStage)
{
    roomHeight = 20;
    roomWidth = 20;
    roomTopLeftX = 0; //dependant on whether room 1 or 2, incomplete
    roomTopLeftY = 0;

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
}

//Ang Zhi En 252317H
//Destructor for bedRoom, deletes pointers
//Incomplete
BedRoom::~BedRoom()
{
    // deallocate bedRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] bedRoomArray[i];
    }
    delete[] bedRoomArray;
}

//Ang Zhi En 252317H
//bedRoomArray getter
char** BedRoom::getBedRoomArray()
{
    return bedRoomArray;
}
