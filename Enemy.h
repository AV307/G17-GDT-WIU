#pragma once
#include "Entity.h"
#include<string>
using namespace std;

class Game;
class Enemy : public Entity {
private:
    int currentStage = 0;
    int baseEXP = 0;

public:
    Enemy(string type, char status);
    ~Enemy();
    bool killEnemy(Game* game);
    bool isBossDefeated() const;
    int calculateLoot(Game* game);
    int calculateDropChance();

    int getHealth() const;
    int getAttack() const;
    int getDefense() const;

};


