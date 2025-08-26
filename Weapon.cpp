#include "Weapon.h"
#include <string>

Weapon::Weapon() : critRate(0), critDamage(0) {}

//Benjamin 250572M
//Constructor for Weapon, initializes weapon attributes
Weapon::Weapon(const std::string& name, int atk, int critRate, int critDamage)
{
	this->name = name;
	this->attack = atk;
	this->critRate = critRate;
	this->critDamage = critDamage;
}

Weapon::~Weapon()
{

}

int Weapon::getAttackVal() const {
	return attack;
}
int Weapon::getCritRateVal() const
{
	return critRate;
}

int Weapon::getCritDamageVal() const
{
	return critDamage;
}


