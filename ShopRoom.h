#pragma once
#include "Room.h"
class ShopRoom :
    public Room
{
private:
    char** shopRoomArray;
public:
    ShopRoom(int currentStage, int roomNumber);
    ~ShopRoom();
    char** getShopRoomArray();
};

