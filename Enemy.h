#pragma once
#include "Entity.h"
#include<string>
using namespace std;
using namespace std;
using namespace std;

class Enemy {
private:
    string name;
    int health;
    int attack;
    int damage;
    int defence;
    int speed;
    int reward;

public:
    Enemy(string n, int h, int atk, int dmg, int def, int spd, int r);

    void displayStatus() const;

    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefence() const;
    int getSpeed() const;
    int getReward() const;

    void setHealth(int h);
};

   


