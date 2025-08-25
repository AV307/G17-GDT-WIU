#pragma once
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include <conio.h>  
#include "Weapon.h"
class Player;

class ShopRoom :
    public Room
{
private:
    char** shopRoomArray;
    Item* shopInventory[20];  // store weapons directly
    std::string itemNames[20] = { "Sword", "Mace", "Scythe", "Warhammer",
                                   "Heal Potion", "Strength Potion", "Weakening Potion",
                                   "Sleep Potion", "Key" };
    int itemPrices[20] = { 50, 70, 100, 150, 30, 25, 20, 40, 0 };

public:
    ShopRoom(int currentStage, int roomNumber);
    ~ShopRoom();
    char** getShopRoomArray();

    void showShopMenu(Player* player);
};
