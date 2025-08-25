#include "BossRoom.h"

//Ang Zhi En 252317H
//Constructor for BossRoom, defines the position and sets up the room
//Incomplete
BossRoom::BossRoom(int currentStage)
{
    roomHeight = 30;
    roomWidth = 30;
    roomTopLeftX = 10;
    roomTopLeftY = 60;

    roomObjects = new RoomObjects(true, roomTopLeftY, roomWidth, roomHeight);

    // dynamically allocate bossRoomArray
    bossRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++)
    {
        bossRoomArray[i] = new char[roomWidth];
    }

    roomObjects->addObjects(roomWidth, roomHeight, currentStage, 'F');
    placeRoomObjects(bossRoomArray);

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
