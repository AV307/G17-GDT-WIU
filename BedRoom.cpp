#include "BedRoom.h"

//Ang Zhi En 252317H
//Constructor for bedRoom, defines the position and sets up the room
//Incomplete
BedRoom::BedRoom(int currentStage, int roomNumber)
{
    roomHeight = 20;
    roomWidth = 20;
    setRoomLocation(roomNumber);

    roomObjects = new RoomObjects(roomWidth, roomHeight);

    // dynamically allocate bedRoomArray
    bedRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        bedRoomArray[i] = new char[roomWidth];
    }

    roomObjects->addObjects(roomWidth, roomHeight, currentStage, 'B');
    placeRoomObjects(bedRoomArray);
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
