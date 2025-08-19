#pragma once
#include "Enemy.h"
#include <string>
class Entity
{
protected:
    string name;
    int attack ,health ,damage ,defence ,xp ,gold ,level;

public:
	Entity();

    //std::string getName() const;
    //int getHealth() const;
    //int getAttack() const;
    //int getDamage() const;
    //int getDefense() const;
    //int getXP() const;
    //int getGold() const;
    //int getLvl() const;

    void attackEnemy(Enemy* Enemy, int damage);

    void levelUp(Enemy* enemy);

	virtual ~Entity();

};

