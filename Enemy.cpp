#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(string n, int h, int atk, int dmg, int def, int xpVal, int g, int lvl, Enemytype t)
    : name(n), health(h), attack(atk), damage(dmg), defence(def), xp(xpVal), gold(g), level(lvl), type(t) {
}

void Enemy::displayStatus() const {
    cout << "Enemy: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Damage: " << damage << endl;
    cout << "Defence: " << defence << endl;
    cout << "XP drop: " << xp << endl;
    cout << "Gold drop: " << gold << endl;
    cout << "Level: " << level << endl;
}

string Enemy::getName() const { return name; }
int Enemy::getHealth() const { return health; }
int Enemy::getAttack() const { return attack; }
int Enemy::getDamage() const { return damage; }
int Enemy::getDefence() const { return defence; }
int Enemy::getXP() const { return xp; }
int Enemy::getGold() const { return gold; }
int Enemy::getLvl() const { return level; }
Enemytype Enemy::getEnemytype() const { return type; }

void Enemy::setHealth(int h) { health = h; }

void Enemy::attackEnemy(Enemy* target, int dmg) {
    if (!target) return;

    target->health -= dmg;
    cout << name << " attacks " << target->name << " for " << dmg << " damage!" << endl;

    if (target->health <= 0) {
        target->health = 0;
        cout << target->name << " has been killed!" << endl;
        cout << "You gained " << target->xp << " XP and " << target->gold << " gold.\n";
    }
}

void Enemy::levelUp() {
    level++;
    health = static_cast<int>(health * 1.5);
    attack = static_cast<int>(attack * 1.5);
    damage = static_cast<int>(damage * 1.5);
    defence = static_cast<int>(defence * 1.5);
    xp = static_cast<int>(xp * 1.5);
    gold = static_cast<int>(gold * 1.5);

    cout << name << " leveled up to level " << level << "!\n";
}

void Enemy::getCritRate()
{

}



Enemy::~Enemy()
{
}

void Enemy::initialiseEnemies(Enemy* enemies, int size)
{
    if (size < 8) {

        enemies[0] = Enemy("Undead", 10, 5, 3, 2, 5, 2, 1, Enemytype::Basic);
        enemies[1] = Enemy("Animals", 20, 8, 5, 4, 10, 5, 2, Enemytype::Basic);
        enemies[2] = Enemy("Flowers", 30, 12, 8, 6, 15, 8, 3, Enemytype::Basic);
        enemies[3] = Enemy("Aquatic", 100, 30, 20, 15, 100, 50, 10, Enemytype::Elite);
        enemies[4] = Enemy("Vampires", 100, 30, 20, 15, 100, 50, 10, Enemytype::Elite);
        enemies[5] = Enemy("Humanoid", 100, 30, 20, 15, 100, 50, 10, Enemytype::Elite);
        enemies[6] = Enemy("Ascendants", 100, 30, 20, 15, 100, 50, 10, Enemytype::Boss);
        enemies[7] = Enemy("Cubed", 100, 30, 20, 15, 100, 50, 10, Enemytype::Boss);
    }
}




    
