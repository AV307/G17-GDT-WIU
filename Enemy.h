#pragma once
#include "Entity.h"
#include<string>
using namespace std;

//enum class Enemytype{
//    Basic,
//    Elite,
//    Boss
//};
class Enemy {
private:
    string name;
    int attack;
    int health;
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
    enum getEnemytype(Enemytype);

    void setHealth(int h);

    void attackEnemy(Enemy* Enemy, int damage);

    void levelUp(Enemy* enemy);

    void initialiseEnemies(Enemy* enemies);

    ~Enemy();
};

   


