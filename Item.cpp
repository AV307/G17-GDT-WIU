#include "Item.h"

Item::Item()
{
}

Item::Item(const std::string& n, const std::string& t, int c)
	: name(n), type(t), cost(c) {
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

std::string Item::getName() const
{
	return name;
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

bool Item::isEquipped() const
{
	return equipped;
}

void Item::consume() {
	if (consumable) {
		consumed = true;
	}
}

bool Item::isConsumable() {
	return consumable;
}
bool Item::isConsumed() {
	return consumed;
}
