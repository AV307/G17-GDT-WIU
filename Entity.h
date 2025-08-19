#pragma once
#include "Enemy.h"
#include<string>
class Entity
{
protected:
    std::string name;
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
	Entity(std::string n, int h, int atk, int dmg, int def, int xp, int gold, int lvl);

    const static int MAX_ENEMY_TYPE = 8;
    std::string enemyBank[MAX_ENEMY_TYPE] = { "Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed" };
    int enemyHP[MAX_ENEMY_TYPE] = { 90 ,100 ,110, 100, 125, 100, 50, 120 };
    int enemyATK[MAX_ENEMY_TYPE] = { 10, 10, 7, 12, 12, 10, 13, 9 };
    int enemyDEF[MAX_ENEMY_TYPE] = { 10, 10, 9, 11, 12, 10, 35, 12 };

    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefense() const;
    int getXP() const;
    int getGold() const;
    int getLvl() const;

    void setName(std::string n);
    void setHealth(int h);
    void setAttack(int atk);
    void setDamage(int dmg);
    void setDefence(int defence);
    void setXP(int xp);
    void setGold(int gold);
    void setLvl(int lvl);
    void displayStatus();
    virtual ~Entity();

};
  

