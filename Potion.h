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

	void setAttackVal(int val);
	void setDefenseVal(int val);

	int getAttackBuff() const;
	int getDefenseBuff() const;
};

