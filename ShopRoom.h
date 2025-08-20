#pragma once
#include "Room.h"
class ShopRoom :
    public Room
{
private:
    char** shopRoomArray;
public:
    ShopRoom(int currentStage);
    ~ShopRoom();
    char** getShopRoomArray();
};

