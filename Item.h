#pragma once
#include <string>
class Item
{
protected:
	int cost;
	int attack;
	int defense;
	bool equipped;
	std::string name;
public:
	Item();
	virtual ~Item();

	int getAttackVal() const;
	int getDefenseVal() const;
	int getCost() const;
	std::string getName() const;
	bool isEquipped() const;

	void setName(std::string itemName);
	void setEquipped(bool equip);
	void setAttackVal(int val);
	void setDefenseVal(int val);
	void setCost(int val);
};

