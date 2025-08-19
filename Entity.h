#pragma once
#include "Enemy.h"
class Entity
{
protected:
    string name;
    int attack;
    int health;
    int damage;
    int defence;
    int xp;
    int gold;
    int level;



public:
    Entity();
	Entity(string n, int h, int atk, int dmg, int def, int xp, int gold, int lvl);

    string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefense() const;
    int getXP() const;
    int getGold() const;
    int getLvl() const;

    void setName(string n);
    void setHealth(int h);
    void setAttack(int atk);
    void setDamage(int dmg);
    void setDefence(int defence);
    void setXP(int xp);
    void setGold(int gold);
    void setLvl(int lvl);

    void attackEnemy(Enemy* Enemy, int damage);

    void levelUp(Enemy* enemy);
	virtual ~Entity();

};

