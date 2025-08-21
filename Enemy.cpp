#include "Entity.h"
#include "Enemy.h"
#include "Game.h"
#include <cstdlib>
#include <random>
#include <iostream>
#include <string>

//Caleb 250601F
//4 arrays to store enemy types for its corresponding statistics
//Completed
using namespace std;

Enemy::Enemy(std::string type, char status) {
	//Checks what type of the enemy is (Undead/Animal/Flower ... )
	srand(static_cast<unsigned int>(time(0)));
	for (int h = 0; h < MAX_ENEMY_TYPE; h++) {
		enemyDrops[h] = 0;
	}
	xp = 0;
	gold = 0;
	for (int i = 0; i < MAX_ENEMY_TYPE; i++) {
		if (type == enemyBank[i]) {
			enemyType = type;
			health = enemyStats[0][i];
			attack = enemyStats[1][i];
			defense = enemyStats[2][i];
			CRITRate = enemyStats[3][i];
			CRITDMG = enemyStats[4][i];
			enemyDrops[i] += 1;
			baseEXP = enemyStats[5][i];
			chance = enemyStats[6][i];
			drops = i;
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
		defense *= static_cast<int>(250 / 100);
		break;
	}
}
Enemy::~Enemy() {}

//Caleb 250601F
//Calculate the chance of the enemy loot based on level, status, and type
//Completed
int Enemy::calculateDropChance(int mult) {
	return (rand() % 100 <= chance + mult) ? 1 : 0;
}

//Caleb 250601F
//Calculate enemy loot based on level, status, and type
//Completed
void Enemy::calculateLoot(Game* gamePtr)
{
	currentStage = gamePtr->getCurrentStage(); 

	switch (enemyStatus) {
	case 'B':
		xp = static_cast<int>(baseEXP / 100);
		gold = 3 + currentStage;
		enemyDrops[drops] = calculateDropChance(0);
		return;
	case 'E':
		if (enemyType == "Ascendants") {
			enemyDrops[drops] = calculateDropChance(40);
		}
		else {
			enemyDrops[drops] = 1;
		}
		xp = static_cast<int>(baseEXP / 70);
		baseEXP += 2;
		gold = 5 + currentStage;
		return;

	case 'D':
		xp = static_cast<int>(baseEXP / 35);
		gold = 10 + currentStage;
		baseEXP += 3;
		enemyDrops[drops] = 2;
		return;
	case 'X':
		xp = static_cast<int>(baseEXP / 10);
		baseEXP += 4;
		gold = 25 + currentStage;
		enemyDrops[drops] = 5;
		return;
	}
}

//Caleb 250601F
//Checks if enemy is killed, returns true if does and vice versa
//Completed
bool Enemy::killEnemy(Game* game) {
	if (health <= 0) {
		calculateLoot(game);
		return true;
	}
	else {
		return false;
	}
}

bool Enemy::isBossDefeated() const
{
	if (enemyStatus != 'B') {
		return false;
	}
	if (enemyStatus == 'B') {
		if (health <= 0) {
			return true;
		}
		else {
			return false;
		}
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
	return defense;
}
int Enemy::getXP() const
{
	return baseEXP;
}

// vampire
//			    \--\           \--\ 
//               \  \ -----------  \
//				Y \    o  v  v   o  \
//			   / o| ______________   \
//            /___/                  /
//            Y Y \__mm_________mm__/      
// 
// Humanoid
//           _________________
//          |                 |
//			|UUUUUUUUUUUUUUUUU|
//        __|   o   ---   o   |__ 
//       |  |_________________|  |    						
//       |_X|                 |X_|
//          |_______|-|_______|
//
// Ascendants
//				  /|\
//				 / |  \
//				/__ | __\
//			   /|-| 0 |- \
//			  / _ | ___|  _\
//			 / __ / \_ / \__\
//
// Cubed
//           __________________
//          |\_________________\
//          ||                 |
//          ||                 |
//          ||                 |
//          ||    o    >     o |
//          \|_________________|