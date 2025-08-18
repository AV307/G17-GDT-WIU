#include "Enemy.h"
#include<vector>
#include<string>
#include <iostream>
using namespace std;

int main() {
    vector<Enemy> enemies;

    enemies.push_back(Enemy("Slime", 10, 5, 3, 2, 1, 10));
    enemies.push_back(Enemy("Kobold", 20, 10, 10, 2, 5, 20));
    enemies.push_back(Enemy("wolf", 30, 20, 20, 5, 10, 30));

    Enemy& slime = enemies[0];
    Enemy& Kobold = enemies[1];
    Enemy& wolf = enemies[2];

    cout << "Encountered: " << slime.getName()
        << " with " << slime.getHealth() << " HP!\n";

    slime.takeDamage(4);

    cout << slime.getName() << " now has "
        << slime.getHealth() << " HP.\n";

    return 0;

}

Enemy::Enemy(string n, int h, int a, int dmg, int def, int s, int r)
{

}

string Enemy::getName() const
{
    return string();
}

int Enemy::getHealth() const
{
    return health;
}

int Enemy::getAttack() const
{
    return attack;
}

int Enemy::getDamage() const
{
    return damage;
}

int Enemy::getDefence() const
{
    return defence;
}

int Enemy::getSpeed() const
{
    return speed;
}

int Enemy::getReward() const
{
    return reward;
}

void Enemy::takeDamage(int dmg)
{
}

bool Enemy::isAlive() const
{
    return false;
}

Enemy::~Enemy()
{
}
