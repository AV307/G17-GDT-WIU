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
	Potion(char selectBuff);
	~Potion();

	void setAttackVal(int val);
	void setDefenseVal(int val);
	void setHealVal(int val);

	int getAttackVal() const;
	int getDefenseVal() const;
	int getHeal() const;
};

