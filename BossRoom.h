#pragma once
#include "Room.h"
class BossRoom :
    public Room
{
private:
    char** bossRoomArray;
public:
    BossRoom(int currentStage);
    ~BossRoom();
    char** getBossRoomArray();
};

