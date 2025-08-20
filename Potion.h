#pragma once
#include "Item.h"
class Potion : public Item
{
private:
	int attackBuff;
	int defenseBuff;
	int heal;

public:
	Potion();
	~Potion();

	void setAttackVal(int val);
	void setDefenseVal(int val);
	void setHealVal(int val);

	int getAttackBuff() const;
	int getDefenseBuff() const;
	int getHeal() const;
};

