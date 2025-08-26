#pragma once
#include "Room.h"
class BossRoom :
    public Room
{
private:
    char** bossRoomArray;
public:
    BossRoom(int currentStage, int roomNumber);
    ~BossRoom();
    char** getBossRoomArray();
};

