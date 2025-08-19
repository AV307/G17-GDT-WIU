#include "Entity.h"

Entity::Entity()
{

}

void Entity::setHealth(int hp)
{
	hp = 0;
}

void Entity::setAttack(int atk)
{
	atk = 0;
}

void Entity::setDamage(int dmg)
{
	dmg = 0;
}
void Entity::setDefence(int def)
{
	def = 0;
}

void Entity::setXP(int xp)
{
	xp = 0;
}

void Entity::setGold(int gold)
{
	gold = 0;
}

void Entity::setLvl(int lvl)
{
	lvl = 1;
}

void Entity::setCritDMG(int critDMG)
{
	critDMG = 0;
}
void Entity::setCritRate(int critRate)
{
	critRate = 0;
}

int Entity::getHealth() const
{
	return health;
}

int Entity::getAttack() const
{
	return attack;
}

int Entity::getDamage() const
{
	return damage;
}

int Entity::getDefence() const
{
	return defence;
}

int Entity::getXP() const
{
	return xp;
}

int Entity::getGold() const
{
	return gold;
}

int Entity::getLvl() const
{
	return getLvl();
}
int Entity::getCRITDMG() const
{
	return CRITDMG;
}
int Entity::getCRITRate() const
{
	return CRITRate;
}





Entity::~Entity()
{

}