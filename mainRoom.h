#pragma once
#include "Room.h"
#include "Enemy.h"

class Game;
class mainRoom :
    public Room
{
private:
    char** mainRoomArray;

public:
    mainRoom(int currentStage);
    ~mainRoom();
    char** getMainRoomArray();
};

