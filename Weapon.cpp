#include "Weapon.h"
#include <string>

Weapon::Weapon() : critRate(0), critDamage(0) {}

//Benjamin 250572M
//Constructor for Weapon, initializes weapon attributes
Weapon::Weapon(const std::string& name, int atk, int critRate, int critDamage)
{
	this->name = name;
	attack = atk;
	this->critRate = critRate;
	this->critDamage = critDamage;
}

Weapon::~Weapon()
{

}

int Weapon::getCritRate() const
{
	return 0;
}

int Weapon::getCritDamage() const
{
	return 0;
}


