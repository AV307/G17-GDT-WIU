#pragma once
#include <string>
using namespace std;
class Entity
{
protected:
    int attack ,health ,damage ,defence ,xp ,gold ,level;

public:
	Entity();

    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefense() const;
    int getXP() const;
    int getGold() const;
    int getLvl() const;


	virtual ~Entity();

};

