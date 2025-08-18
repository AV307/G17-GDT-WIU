#pragma once
#include "Entity.h"
class Player : public Entity
{
private:

public:
	Player();
	~Player();
	void move();
	void checkCollision();
	void checkConsumption();
};



