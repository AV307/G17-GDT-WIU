#pragma once
#include "Entity.h"
#include<string>
#include<vector>
using namespace std;

//class Enemy :  public Entity
//{
//private:
//	string name;
//	int health;
//	int attack;
//	int damage;
//	int defence;
//	int speed;
//	int reward;
//
//
//
//public:
//	Enemy(string n, int h, int a, int dmg, int def, int s) :name(n), health(h), attack(a), damage(dmg), defence(def), speed(s) {};
//
//	string getName() const {
//		return name;
//	}
//
//	int getHealth() const {
//		return health;
//	}
//
//	int getAttack() const {
//		return health;
//	}
//
//	int getDamage() const {
//		return health;
//	}
//
//	int getDefence() const {
//		return health;
//	}
//
//	int getSpeed() const {
//		return health;
//	}
//};



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
    // Constructor
    Enemy(string n, int h, int a, int dmg, int def, int s, int r);

    // Getters
    string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefence() const;
    int getSpeed() const;
    int getReward() const;

    // Combat
    void takeDamage(int dmg);
    bool isAlive() const;

    ~Enemy();
};

