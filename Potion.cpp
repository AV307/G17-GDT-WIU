#include "Potion.h"

Potion::Potion()
{
	attackBuff = 0;
	defenseBuff = 0;
	heal = 0;
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

void Potion::setHealVal(int val)
{
	heal = val;
}

int Potion::getAttackVal() const
{
	return attackBuff;
}

int Potion::getDefenseVal() const
{
	return defenseBuff;
}

int Potion::getHeal() const
{
	return heal;
}
