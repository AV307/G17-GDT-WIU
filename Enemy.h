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
    //char getStatus() const;
    //string getType() const;
};


