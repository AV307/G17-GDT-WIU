#include "Potion.h"

Potion::Potion()
{
	attackBuff = 0;
	defenseBuff = 0;
}

Potion::~Potion()
{
}

int Potion::getAttackBuff() const
{
	return attackBuff;
}

int Potion::getDefenseBuff() const
{
	return defenseBuff;
}
