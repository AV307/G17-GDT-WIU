#include "Armour.h"

Armour::Armour()
{
	
}

Armour::Armour(int armourIndex) {
	armourNameVal = armourName[armourIndex];
	defenseVal = defenseBoost[armourIndex];
}
Armour::~Armour()
{
}
string Armour::getArmourName() const {
	return armourNameVal;
}

int Armour::getDefenseBoost() const {
	return defenseVal;
}