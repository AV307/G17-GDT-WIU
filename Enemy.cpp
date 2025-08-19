#include "Enemy.h"
#include<vector>
#include<string>
#include <iostream>
using namespace std;


Enemy::Enemy(string n, int h, int atk, int dmg, int def, int spd, int r)
    : name(n), health(h), attack(atk), damage(dmg), defence(def), speed(spd), reward(r) {
}

void Enemy::displayStatus() const {
    cout << "Enemy: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Damage: " << damage << endl;
    cout << "Defence: " << defence << endl;
    cout << "Speed: " << speed << endl;
    cout << "Reward: " << reward << endl;
}

string Enemy::getName() const { 
    return name; 
}
int Enemy::getHealth() const { 
    return health; 
}
int Enemy::getAttack() const { 
    return attack; 
}
int Enemy::getDamage() const { 
    return damage; 
}
int Enemy::getDefence() const { 
    return defence; 
}
int Enemy::getSpeed() const { 
    return speed; 
}
int Enemy::getReward() const { 
    return reward; 
}

void Enemy::setHealth(int h) { 
    health = h; 
}