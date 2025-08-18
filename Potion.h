#pragma once
#include "Item.h"
class Potion : public Item
{
private:
	int attackBuff;
	int defenseBuff;

public:
	Potion();
	~Potion();

	int getAttackBuff() const;
	int getDefenseBuff() const;
};

