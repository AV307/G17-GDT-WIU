#pragma once
#include "Room.h"
class CorridorRoom :
    public Room
{
private:
    char** corridorRoomArray;
public:
    CorridorRoom(int currentStage, int roomNumber);
    ~CorridorRoom();
    char** getCorridorRoomArray();
};

