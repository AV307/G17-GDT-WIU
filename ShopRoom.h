#pragma once
#include "Room.h"
class ShopRoom :
    public Room
{
private:
    char** shopRoomArray;
    //Item* shopInventory[10];
public:
    ShopRoom(int currentStage, int roomNumber);
    ~ShopRoom();
    char** getShopRoomArray();
};

