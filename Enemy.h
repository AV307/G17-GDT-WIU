#pragma once
#include "Entity.h"
#include<string>

class Enemy : public Entity{

public:
    Enemy();
    Enemy(std::string type, char status);
    ~Enemy();

    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    void killEnemy();
};


