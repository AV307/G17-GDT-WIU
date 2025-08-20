#include "Entity.h"
#include "Enemy.h"
#include <cmath>
#include <cstdlib>
#include <random>
#include <iostream>
#include <string>

//Caleb 250601F
//4 arrays to store enemy types for its corresponding statistics
//Completed
using namespace std;

const static int MAX_ENEMY_TYPE = 8;
std::string enemyBank[MAX_ENEMY_TYPE] = { "Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed" };
int enemyHP[MAX_ENEMY_TYPE] = { 90 ,100 ,110, 45, 125, 100, 50, 130 };
int enemyATK[MAX_ENEMY_TYPE] = { 10, 10, 7, 35, 15, 10, 13, 7 };
int enemyDEF[MAX_ENEMY_TYPE] = { 10, 10, 9, 10, 12, 10, 35, 5 };
char enemyStatus = ' ';

Enemy::Enemy(std::string type, char status) {
	//Checks what type of the enemy is (Undead/Animal/Flower ... )
	xp = 0;
	gold = 0;
	for (int i = 0; i < MAX_ENEMY_TYPE; i++) {
		if (type == enemyBank[i]) {
			health = enemyHP[i];
			attack = enemyATK[i];
			defense = enemyDEF[i];
		}
	}
	enemyStatus = status;
	//Checks what status the enemy is (Basic/Elite/Deluxe/Boss)
	switch (status) {

	case 'B':
		break;
	case 'E':
		health *= static_cast<int>(150 / 100);
		attack *= static_cast<int>(150 / 100);
		defense *= static_cast<int>(150 / 100);
		break;
	case 'D':
		health *= static_cast<int>(220 / 100);
		attack *= static_cast<int>(175 / 100);
		defense *= static_cast<int>(175 / 100);
		break;
	case 'X':
		health *= static_cast<int>(350 / 100);
		attack *= static_cast<int>(250 / 100);
		defense *= static_cast<int>(200 / 100);
		break;
	}
}
Enemy::~Enemy() {}

//Caleb 250601F
//Calculate enemy loot based on level, status, and type
//Completed
int Enemy::calculateLoot() {
	switch (enemyStatus) {
	case 'B':
		xp = static_cast<int>((((health + attack + defense)) * level) / 100);
		gold = 3;
		return xp, gold;
	case 'E':
		xp = static_cast<int>((((health + attack + defense)) * level) / 70);
		gold = 5;
		return xp, gold;
	case 'D':
		xp = static_cast<int>((((health + attack + defense)) * level) / 35);
		gold = 10;
		return xp, gold;
	case 'X':
		xp = static_cast<int>((((health + attack + defense)) * level) / 10);
		gold = 25;
		return xp, gold;
	}
}

//Caleb 250601F
//Checks if enemy is killed, returns true if does and vice versa
//Completed
bool Enemy::killEnemy() {
	if (health <= 0) {
		calculateLoot();
		return true;
	}
	else {
		return false;
	}
}

//Caleb 250601F
//Getter functions for enemy statistics
//Completed <- may expand 
int Enemy::getHealth() const
{
	return health;
}
int Enemy::getAttack() const
{
	return attack;
}
int Enemy::getDefense() const
{
	return defence;
}


	