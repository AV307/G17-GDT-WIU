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
};

class TradingSystem {
private:
    Player* player;
    Entity* entity;

    DropInfo drops[8] = {
        {"Sycophant Heart", 0.25, 1, 2, 3, 5},
        {"Poisoned Fang", 0.25, 1, 3, 5, 5},
        {"Withered Nectar", 0.50, 1, 2, 3, 4},
        {"Prismarine Fin", 0.50, 1, 2, 3, 7},
        {"Jar of Hemovibe", 0.20, 1, 2, 3, 12},
        {"Burning Skin", 0.20, 1, 2, 3, 12},
        {"Opal Crystals", 0.10, 1, 2, 25, 50},
        {"Magma Jelly", 0.50, 2, 3, 5, 10}
    };

public:
    TradingSystem(Player* p, Entity* e);
    void showAvailableDrops();
    void tradeDrop(int dropIndex, int choice, std::string enemyType);
    // choice: 0=gold,1=xp,2=item
};
