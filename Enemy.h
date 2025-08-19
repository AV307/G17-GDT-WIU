#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
private:
    int level, EXP;
public:
    Enemy();
    Enemy(char type);
    ~Enemy();
};

