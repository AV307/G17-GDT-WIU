#pragma once
#include "Entity.h"
#include <string>

enum class Enemytype {
    Basic,
    Elite,
    Boss
};

class Enemy {
private:
    std::string name;
    int attack;
    int health;
    int damage;
    int defence;
    int xp;
    int gold;
    int level;
    Enemytype type;

public:
    // Constructor
    Enemy(std::string n, int h, int atk, int dmg, int def, int xp, int gold, int lvl, Enemytype t);

    const static int MAX_ENEMY_TYPE = 8;
    std::string enemyBank[MAX_ENEMY_TYPE] = { "Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed" };
    int enemyHP[MAX_ENEMY_TYPE] = { 90 ,100 ,110, 100, 125, 100, 50, 120 };
    int enemyATK[MAX_ENEMY_TYPE] = { 10, 10, 7, 12, 12, 10, 13, 9 };
    int enemyDEF[MAX_ENEMY_TYPE] = { 10, 10, 9, 11, 12, 10, 35, 12 };


    void displayStatus() const;

    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefence() const;
    int getXP() const;
    int getGold() const;
    int getLvl() const;
    Enemytype getEnemytype() const;

    void setHealth(int h);

    void attackEnemy(Enemy* target, int damage);
    void levelUp();

    void getCritRate();
    

    void initialiseEnemies(Enemy* enemies, int size);

    ~Enemy();
};
