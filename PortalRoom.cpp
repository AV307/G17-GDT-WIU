#include "PortalRoom.h"

//Ang Zhi En 252317H
//Constructor for PortalRoom, defines position and sets up room
//Incomplete
PortalRoom::PortalRoom(int currentStage, int roomNumber)
{
    roomHeight = 11;
    roomWidth = 11;
    roomTopLeftX = 0;
    roomTopLeftY = 45;

    // dynamically allocate shopRoomArray
    portalRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        portalRoomArray[i] = new char[roomWidth];
    }

    // set empty room
    for (int i{ 0 }; i < roomHeight; i++)
    {
        for (int j{ 0 }; j < roomWidth; j++)
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1)
            {
                portalRoomArray[i][j] = 'O'; // set to wall
            }
            else
            {
                portalRoomArray[i][j] = ' '; // set to space
            }
        }
    }

    //add code below for setting up specific portal related parts
}

//Ang Zhi En 252317H
//Destructor for portalRoom, deletes pointers
//Incomplete
PortalRoom::~PortalRoom()
{
    // deallocate portalRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] portalRoomArray[i];
    }
    delete[] portalRoomArray;
}

//Ang Zhi En 252317H
//Getter for portalRoomArray
char** PortalRoom::getPortalRoomArray()
{
	return portalRoomArray;
}
