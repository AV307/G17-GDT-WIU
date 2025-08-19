#include "Entity.h"
#include "Enemy.h"
#include <cmath>
#include <cstdlib>
#include <random>
#include <iostream>
#include <string>
using namespace std;

const static int MAX_ENEMY_TYPE = 8;
std::string enemyBank[MAX_ENEMY_TYPE] = { "Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed" };
int enemyHP[MAX_ENEMY_TYPE] = { 90 ,100 ,110, 100, 125, 100, 50, 120 };
int enemyATK[MAX_ENEMY_TYPE] = { 10, 10, 7, 12, 12, 10, 13, 9 };
int enemyDEF[MAX_ENEMY_TYPE] = { 10, 10, 9, 11, 12, 10, 35, 12 };

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
}
Enemy::~Enemy() {}


void Enemy::killEnemy() {
	if (health <= 0) {
		 xp = static_cast<int>((((health + attack + defence) / 100) * level) / 10);
	}
}
	