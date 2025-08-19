#include "Entity.h"
#include "Enemy.h"
#include <cmath>
#include <cstdlib>
#include <random>
#include <iostream>
#include <string>
Enemy::Enemy() {

}
Enemy::Enemy(std::string type, char status) {
	EXP = 0;
	for (int i = 0; i < MAX_ENEMY_TYPE; i++) {
		if (type == enemyBank[i]) {
			health = enemyHP[i];
			attack = enemyATK[i];
			defense = enemyDEF[i];
		}
	}
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
Enemy::~Enemy() {

}

void Enemy::killEnemy() {
	if (health <= 0) {
		EXP = static_cast<int>((((health + attack + defense) / 100) * level) / 10);
	}
}

int Enemy::getHealth() const { 
    return health; 
}
int Enemy::getAttack() const { 
    return attack; 
}
int Enemy::getDefense() const { 
    return defense; 
}

