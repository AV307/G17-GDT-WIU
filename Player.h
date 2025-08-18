#pragma once
#include "Entity.h"
#include "Item.h"
class Player : public Entity
{
private:
	Item inventory[10];
public:
    Player();
    ~Player();
    void move();
    void checkCollision();
    void checkConsumption();
};



