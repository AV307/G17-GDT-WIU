#include "Enemy.h"
#include<string>
#include <iostream>
using namespace std;


Enemy::Enemy(string n, int h, int atk, int dmg, int def, int xp, int g, int lvl) {
    : name(n), health(h), attack(atk), damage(dmg), defence(def), xp(xp), gold(g), level(lvl) {};

//string n, int h, int atk, int dmg, int def, int xp, int gold, int lvl);
void Enemy::displayStatus() const {
    cout << "Enemy: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Damage: " << damage << endl;
    cout << "Defence: " << defence << endl;
    cout << "XP drop: " << xp << endl;
    cout << "Gold drop: " << gold << endl;
}

string Enemy::getName() const { 
    return name; 
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
int Enemy::getXP() const
{
    return xp;
}
int Enemy::getGold() const
{
    return gold;
}
int Enemy::getLvl() const
{
    return level;
}



void Enemy::setHealth(int h) { 
    health = h; 
}

void Enemy::attackEnemy(Enemy* enemy, int damage)
{
    if (enemy->health <= 0 && enemy == 0) {
        cout << "Enemy has been killed";
        enemy->getGold();
        enemy->getXP();
    }

}
void Enemy::levelUp(Enemy* enemy) {
    
    level++;
    health = static_cast<int>(health * level * 1.5);
    attack = static_cast<int>(attack * level * 1.5);
    damage = static_cast<int>(damage * level * 1.5);
    defence = static_cast<int>(defence * level * 1.5);
    xp = static_cast<int>(xp * level * 1.5);
    gold = static_cast<int>(gold * level * 1.5);
    cout <<Enemy::name << " is lvl " <<Enemy::level << "!\n";
}

void Enemy::initialiseEnemies(Enemy* enemies)
{
    Enemy* Slime = new Enemy("Slime", 10, 10, 10, 10, 10, 10, 10);
    Enemy* Kobold = new Enemy("Kobold", 20, 20, 20, 20, 20, 20, 20);
    Enemy* Wolf = new Enemy("Wolf", 30, 30, 30, 30, 30, 30, 30);
    Enemy* Boss = new Enemy("Boss", 100, 100, 100, 100, 100, 100, 100);
}

Enemy::~Enemy()
{

}

//name(n), health(h), attack(atk), damage(dmg), defence(def), speed(spd), reward(r)
int main(void) {

}