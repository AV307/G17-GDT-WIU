#pragma once
#include "Room.h"
class mainRoom :
    public Room
{
private:
    char mainRoomArray[60][60];

public:
    mainRoom();
    ~mainRoom();
};

