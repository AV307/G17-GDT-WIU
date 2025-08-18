#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player();
	~Player();
	void move();
	void checkCollision();
	void checkConsumption();
	void calculateDamage();
};



