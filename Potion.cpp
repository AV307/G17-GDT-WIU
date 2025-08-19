#include "Potion.h"

Potion::Potion()
{
	attackBuff = 0;
	defenseBuff = 0;
}

Potion::~Potion()
{
}

void Potion::setAttackVal(int val)
{
	attackBuff = val;
}

void Potion::setDefenseVal(int val)
{
	defenseBuff = val;
}

int Potion::getAttackBuff() const
{
	return attackBuff;
}

int Potion::getDefenseBuff() const
{
	return defenseBuff;
}
