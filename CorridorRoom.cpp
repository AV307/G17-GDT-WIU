#include "CorridorRoom.h"

//Ang Zhi En 252317H
//Constructor for corridorRoom, defines the position and sets up the room
//Incomplete
CorridorRoom::CorridorRoom(int currentStage, int roomNumber)
{
    roomHeight = 2; // to be set after room location decided
    roomWidth = 2;
    setRoomLocation(roomNumber);

    roomObjects = new RoomObjects(roomWidth, roomHeight);

    // dynamically allocate corridorRoomArray
    corridorRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        corridorRoomArray[i] = new char[roomWidth];
    }

    roomObjects->addObjects(roomWidth, roomHeight, currentStage, 'C');
    placeRoomObjects(corridorRoomArray);
}

//Ang Zhi En 252317H
//Destructor for corridorRoom, deletes pointers
//Incomplete
CorridorRoom::~CorridorRoom()
{
    // deallocate corridorRoomArray
    for (int i{ 0 }; i < roomHeight; i++)
    {
        delete[] corridorRoomArray[i];
    }
    delete[] corridorRoomArray;
}

//Ang Zhi En 252317H
//corridorRoomArray getter
char** CorridorRoom::getCorridorRoomArray()
{
    return corridorRoomArray;
}
