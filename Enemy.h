#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
private:
    int EXP;
public:
    Enemy();
    Enemy(char type);
    ~Enemy();
};

