#pragma once
#include "Entity.h"
#include<string>
using namespace std;

class Enemy {
private:
    string name;
    int health;
    int attack;
    int damage;
    int defence;
    int xp;
    int gold;
    int level;

public:
    Enemy(string n, int h, int atk, int dmg, int def, int xp, int gold, int lvl);

    void displayStatus() const;

    string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefence() const;
    int getXP() const;
    int getGold() const;
    int getLvl() const;

    void setHealth(int h);

    void attackEnemy(Enemy* Enemy, int damage);

    void levelUp(Enemy* enemy);

    ~Enemy();
};

   


