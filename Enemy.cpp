#include "Entity.h"
#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;

const static int MAX_ENEMY_TYPE = 8;
std::string enemyBank[MAX_ENEMY_TYPE] = { "Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed" };
int enemyHP[MAX_ENEMY_TYPE] = { 90 ,100 ,110, 100, 125, 100, 50, 120 };
int enemyATK[MAX_ENEMY_TYPE] = { 10, 10, 7, 12, 12, 10, 13, 9 };
int enemyDEF[MAX_ENEMY_TYPE] = { 10, 10, 9, 11, 12, 10, 35, 12 };
Enemy::Enemy(string n, int h, int atk, int dmg, int def, int xpVal, int g, int lvl, Enemytype t)
    : name(n), health(h), attack(atk), damage(dmg), defence(def), xp(xpVal), gold(g), level(lvl), type(t) {
}

Enemy::Enemy(std::string type, char status) {
	xp = 0;
	for (int i = 0; i < MAX_ENEMY_TYPE; i++) {
		if (type == enemyBank[i]) {
			health = enemyHP[i];
			attack = enemyATK[i];
			defence = enemyDEF[i];
		}
	}
	switch (status) {
	case 'B':
		break;
	case 'E':
		health *= static_cast<int>(150 / 100);
		attack *= static_cast<int>(150 / 100);
		defence *= static_cast<int>(150 / 100);
		break;
	case 'D':
		health *= static_cast<int>(220 / 100);
		attack *= static_cast<int>(175 / 100);
		defence *= static_cast<int>(175 / 100);
		break;
	case 'X':
		health *= static_cast<int>(350 / 100);
		attack *= static_cast<int>(250 / 100);
		defence *= static_cast<int>(200 / 100);
		break;
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
Enemy::~Enemy(){}

void Enemy::initialiseEnemies(Enemy* enemies, int size)
{
    if (size < 8) {

void Enemy::killEnemy() {
	if (health <= 0) {
		 xp = static_cast<int>((((health + attack + defence) / 100) * level) / 10);
	}
}
	