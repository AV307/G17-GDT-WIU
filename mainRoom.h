#pragma once
#include "Room.h"

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

