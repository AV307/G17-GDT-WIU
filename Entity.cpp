#include "Entity.h"

Entity::Entity()
{

}

void Entity::setHealth()
{
	health = 0;
}

void Entity::setAttack()
{
	attack = 0;
}

void Entity::setDamage()
{
	damage = 0;
}
void Entity::setDefense()
{
	defence = 0;
}

void Entity::setXP()
{
	xp = 0;
}

void Entity::setGold()
{
	gold = 0;
}

void Entity::setLvl()
{
	level = 1;
}

void Entity::setCRITDMG()
{
	CRITDMG = 0;
}
void Entity::setCRITRate()
{
	CRITRate = 0;
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

int Entity::getDefense() const
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