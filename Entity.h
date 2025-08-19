#pragma once
#include <string>
#include "Enemy.h"
class Entity
{
protected:
	int health;
	int attack;
	int defense;
	int level, EXP;

	const static int MAX_ENEMY_TYPE = 8;
	std::string enemyBank[MAX_ENEMY_TYPE] = {"Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed"};
	int enemyHP[MAX_ENEMY_TYPE] = { 90 ,100 ,110, 100, 125, 100, 50, 120 };
	int enemyATK[MAX_ENEMY_TYPE] = { 10, 10, 7, 12, 12, 10, 13, 9 };
	int enemyDEF[MAX_ENEMY_TYPE] = { 10, 10, 9, 11, 12, 10, 35, 12 };

public:
	Entity();
	virtual ~Entity();

};

