#include "PortalRoom.h"

//Ang Zhi En 252317H
//Constructor for PortalRoom, defines position and sets up room
PortalRoom::PortalRoom(int currentStage, int roomNumber)
{
    roomHeight = 11;
    roomWidth = 11;
    roomTopLeftX = 15;
    roomTopLeftY = 45;

    roomObjects = new RoomObjects(false, roomTopLeftY, roomWidth, roomHeight);

    // dynamically allocate shopRoomArray
    portalRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        portalRoomArray[i] = new char[roomWidth];
    }

    roomObjects->addObjects(roomWidth, roomHeight, currentStage, 'P');
    placeRoomObjects(portalRoomArray);
}

//Ang Zhi En 252317H
//Destructor for portalRoom, deletes pointers
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
