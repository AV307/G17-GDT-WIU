#include "Weapon.h"
#include <string>

Weapon::Weapon() : critRate(0), critDamage(0) {}

//Benjamin 250572M
//Constructor for Weapon, initializes weapon attributes
Weapon::Weapon(const std::string& name, int atk, int critR, int critD)
    : Item(name, "Weapon", 0),      // initialize base class properly
    critRate(critR),
    critDamage(critD),
	attack(atk)
{
    // nothing else needed
}

Weapon::Weapon(int weaponIndex) {
	critRate = critRateValues[weaponIndex];
	critDamage = critDamageValues[weaponIndex];
	attack = attackValues[weaponIndex]; 
}

Weapon::~Weapon()
{

}
int Weapon::getAttack() const
{
    return attack; // Assuming getValue() returns the attack value for weapons
}
int Weapon::getCritRateVal() const
{
	return critRate;
}

int Weapon::getCritDamageVal() const
{
	return critDamage;
}

void Weapon::setCritDamage(int val)
{
    critDamage = val;
}
void Weapon::setCritRate(int val)
{
    critRate = val;
}




