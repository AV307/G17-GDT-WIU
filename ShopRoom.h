#pragma once
#include "Room.h"
#include "Item.h"
#include "Player.h"
class ShopRoom :
    public Room
{
private:
    char** shopRoomArray;
    Item* shopInventory[10];
    std::string itemNames[4] = { "Sword", "Shield", "Potion", "Bow" };
    int itemPrices[4] = { 50, 40, 20, 60 };

public:
    ShopRoom(int currentStage, int roomNumber);
    ~ShopRoom();
    char** getShopRoomArray();

    void showShopMenu(Player* player);
};