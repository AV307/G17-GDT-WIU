#include "Entity.h"
#include "Enemy.h"
Enemy::Enemy() {

}
Enemy::Enemy(char type) {
	EXP = 0;
	health = 100;
	attack = 15;
	defense = 10;
	identity = type;
	switch (identity) {
	case 'B':
		break;
	case 'E':
		health *= 150 / 100;
		attack *= 150 / 100;
		defense *= 133 / 100;
		break;
	case 'X':
		health *= 500 / 100;
		attack *= 200 / 100;
		defense *= 150 / 100;
		break;
	}
}
Enemy::~Enemy() {
	EXP = ((health + attack + defense) / 100) * level;
}

