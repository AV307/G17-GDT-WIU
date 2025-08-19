#include "Entity.h"



Entity::Entity() : health(100), attack(10), damage(5), defence(5), xp(0), gold(0), level(1), CRITDMG(2), CRITRate(10) {
}


Entity::Entity(int hp, int atk, int dmg, int def, int exp, int g, int lvl, int critdmg, int critrate)
    : health(hp), attack(atk), damage(dmg), defence(def),
    xp(exp), gold(g), level(lvl), CRITDMG(critdmg), CRITRate(critrate) {
}

int Entity::getHealth() const { 
    return health; 
}

int Entity::getAttack() const {
    return attack; 
}

int Entity::getDamage() const { 
    return damage; 
}

int Entity::getDefense() const { 
    return defence; 
}

int Entity::getXP() const { 
    return xp; 
}

int Entity::getGold() const { 
    return gold; 
}

int Entity::getLvl() const { 
    return level; 
}

int Entity::getCRITDMG() const { 
    return CRITDMG; 
}
int Entity::getCRITRate() const { 
    return CRITRate; 
}

void Entity::setHealth(int hp) { 
    health = hp; 
}

void Entity::setAttack(int atk) { 
    attack = atk; 
}

void Entity::setDamage(int dmg) { 
    damage = dmg; 
}

void Entity::setDefense(int def) { 
    defence = def; 
}

void Entity::setXP(int exp) { 
    xp = exp; 
}

void Entity::setGold(int g) { 
    gold = g; 
}

void Entity::setLvl(int lvl) { 
    level = lvl; 
}

void Entity::setCritDMG(int critdmg) { 
    CRITDMG = critdmg; 
}

void Entity::setCritRate(int critrate) {
    CRITRate = critrate; 
}



Entity::~Entity()
{
}
