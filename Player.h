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
	static int health, attack, defense, CRITRate, CRITDMG, strength;
};



