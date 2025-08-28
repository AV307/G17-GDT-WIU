#include "Weapon.h"
#include <string>

Weapon::Weapon() : critRate(0), critDamage(0) {}

//Benjamin 250572M
//Constructor for Weapon, initializes weapon attributes
Weapon::Weapon(const std::string& name, int atk, int critR, int critD)
    : Item(name, "Weapon", 0),      // initialize base class properly
    attack(atk),
    critRate(critR),
    critDamage(critD)
{
    // nothing else needed
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


