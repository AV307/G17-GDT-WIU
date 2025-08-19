#pragma once
#include "Room.h"
class BedRoom :
    public Room
{
private:
    char** bedRoomArray;
public:
    BedRoom(int currentStage);
    ~BedRoom();
    char** getBedRoomArray();
};

