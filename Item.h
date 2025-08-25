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
	std::string type;

	bool consumable;
	bool consumed;
public:
	Item();
	Item(const std::string& n, const std::string& t, int c);
	virtual ~Item();

	int getAttackVal() const;
	int getDefenseVal() const;
	int getCost() const;
	std::string getType() { return type; }
	std::string getName() const;
	bool isEquipped() const;

	void consume();
	bool isConsumable();
	bool isConsumed();

	void setName(std::string itemName);
	void setEquipped(bool equip);
	void setAttackVal(int val);
	void setDefenseVal(int val);
	void setCost(int val);
};

