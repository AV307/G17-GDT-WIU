#pragma once
#include <iostream>
#include "Player.h"
#include "Entity.h"

struct DropInfo {
    std::string name;
    double rarity; // e.g., 0.25 for 25%
    int goldBasic; // reward for Basic
    int goldElite;
    int goldDelux;
    int goldBoss;

    int xpBasic;   
    int xpElite;
    int xpDelux;
    int xpBoss;
};

class TradingSystem {
private:
    Player* player;
    Entity* entity;

    DropInfo drops[8] = {
		//xp and gold rewards for each drop type
        // name, rarity, goldBasic, goldElite, goldDelux, goldBoss, xpBasic, xpElite, xpDelux, xpBoss
        {"Sycophant Heart", 0.25, 1, 2, 3, 5, 5, 10, 15, 25},
        {"Poisoned Fang",   0.25, 1, 3, 5, 7, 5, 12, 18, 30},
        {"Withered Nectar", 0.50, 1, 2, 3, 6, 4, 8, 12, 20},
        {"Prismarine Fin",  0.50, 1, 2, 3, 7, 7, 14, 21, 35},
        {"Jar of Hemovibe", 0.20, 1, 2, 3, 8,12, 24, 36, 60},
        {"Burning Skin",    0.20, 1, 2, 3, 9,12, 24, 36, 60},
        {"Opal Crystals",   0.10, 1, 2,25,50,50,100,200,400},
        {"Magma Jelly",     0.50, 2, 3, 5,10,10,20,30,50}
    };

public:
    TradingSystem(Player* p, Entity* e);
    void showAvailableDrops();
    void tradeDrop(int dropIndex, int choice, std::string enemyType);
    // choice: 0=gold,1=xp,2=item
};
