#pragma once
#include "Entity.h"
#include<string>
using namespace std;

class Game;
class Player;

class Enemy : public Entity {
private:
    int currentStage = 0;
    int baseEXP = 0;
    int chance = 0;
    int dropAMTID = 0;
    static bool enemyArray[28][28];

public:
    Enemy(string type, char status);
    ~Enemy();
    bool killEnemy(Game* game);
    bool isBossDefeated() const;
    void calculateLoot(Game* game);
    int calculateDropChance(int mult);
    bool isEnemyThere(Player* player, int checkX, int checkY);
    pair<int, int> enemyPos(int enemyX, int enemyY);

    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getXP() const;
};


