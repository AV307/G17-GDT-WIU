#pragma once
#include "Room.h"

class Game;
class mainRoom :
    public Room
{
private:
    char mainRoomArray[60][60];
    Game* game;

public:
    mainRoom(int currentStage);
    ~mainRoom();
};

