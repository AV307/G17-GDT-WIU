#pragma once
#include "Entity.h"
#include<string>
using namespace std;

class Enemy : public Entity {
private:


public:
    Enemy(string type, char status);
    ~Enemy();
    bool killEnemy();
    int calculateLoot();

    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
};


