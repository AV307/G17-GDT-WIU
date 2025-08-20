#pragma once
#include "Room.h"
class TreasureRoom :
    public Room
{
private:
    char** treasureRoomArray;
public:
    TreasureRoom(int currentStage, int roomNumber);
    ~TreasureRoom();
    char** getTreasureRoomArray();
};

