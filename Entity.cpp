#include "Entity.h"
#include "Enemy.h"

//Entity::Entity()
//{
//	health = 0;
//	attack = 0;
//	defense = 0;
//}

Entity::Entity() {}

Entity::Entity(string n, int h, int atk, int dmg, int def, int xp, int gold, int lvl) 
	: name(n), health(h), attack(atk), damage(dmg), defence(def), xp(xp), gold(gold), level(lvl) {};

string Entity::getName() const
{
	return string();
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

void Entity::setName(string n)
{
}

void Entity::setHealth(int h)
{
}

void Entity::setAttack(int atk)
{
}

void Entity::setDamage(int dmg)
{
}

void Entity::setDefence(int defence)
{
}

void Entity::setXP(int xp)
{
}

void Entity::setGold(int gold)
{
}

void Entity::setLvl(int lvl)
{
}


void Entity::attackEnemy(Enemy* Enemy, int damage)
{

}

void Entity::levelUp(Enemy* enemy)
{

}

Entity::~Entity()
{

}