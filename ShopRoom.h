#pragma once
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include <conio.h>  
#include "Weapon.h"
class ShopRoom :
    public Room
{
private:
    char** shopRoomArray;
    Weapon* shopInventory[4];  // store weapons directly
    std::string itemNames[4] = { "Sword", "Mace", "Scythe", "Warhammer" };
    int itemPrices[4] = { 50, 70, 100, 150 };

public:
    ShopRoom(int currentStage, int roomNumber);
    ~ShopRoom();
    char** getShopRoomArray();

    void showShopMenu(Player* player);
};