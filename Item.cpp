#include "Item.h"

Item::Item()
{
	attack = 0;
	defense = 0;
	cost = 0;
	owned = false;
	equipped = false;
	name = "blank";
}

Item::~Item()
{
}


int Item::getAttackVal() const
{
	return attack;
}

int Item::getDefenseVal() const
{
	return defense;
}

int Item::getCost() const
{
	return cost;
}

void Item::setOwned(bool state)
{
	owned = state;
}

void Item::setName(std::string itemName)
{
	name = itemName;
}

void Item::setEquipped(bool equip)
{
	equipped = equip;
}

void Item::setAttackVal(int val)
{
	attack = val;
}

void Item::setDefenseVal(int val)
{
	defense = val;
}

void Item::setCost(int val)
{
	cost = val;
}

bool Item::isOwned() const
{
	return owned;
}

bool Item::isEquipped() const
{
	return equipped;
}
