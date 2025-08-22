#pragma once
#include <iostream>
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

class TradingSystem
{
private:
    Player* player;
    Entity* entity;
 
    const char* drops[8] = {
        "Sycophant Heart",
        "Poisoned Fang",
        "Withered Nectar",
        "Prismarine Fin",
        "Jar of Hemovibe",
        "Burning Skin",
        "Opal Crystals",
        "Magma Jelly"
    };

public:
    //TradingSystem(Player* p, Entity* e);

    //void showAvailableDrops();
    void tradeDrop(int dropIndex, int choice);
   // choice = 0 (gold), 1 (xp), 2 (item)
};
