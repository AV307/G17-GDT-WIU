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
    bool sleepState;
    bool enemyArray[28][28] = { false };
    int enemyXR, enemyYR;

public:
    Enemy(string type, char status);
    ~Enemy();
    bool killEnemy(Game* game);
    bool isBossDefeated() const;
    void calculateLoot(Game* game);
    int calculateDropChance(int mult);
    bool isEnemyThere(Player* player);
    pair<int, int> enemyPos(int enemyX, int enemyY);

    bool getSleepState();
    void setSleepState(bool sleepState);

    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getXP() const;

    int getEnemyXR() const;
    int getEnemyYR() const;
};


