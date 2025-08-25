#include "Entity.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"
#include <cstdlib>
#include <random>
#include <iostream>
#include <string>

using namespace std;
string newPos;
pair<int, int> Enemy::enemyPos(int enemyXPair, int enemyYPair) {  
	enemyArray[enemyXPair][enemyYPair] = true;						// paring is a function that returns a pair of values can be both bool or int or string etc.
	return make_pair(enemyXPair, enemyYPair);
};

bool Enemy::isEnemyThere(Player* player, int checkX, int checkY) {
	pair<int, int> enemyPosPair = enemyPos(checkX, checkY);
	if (player != nullptr) {
		if (player->getXPos() == enemyPosPair.first && player->getYPos() == enemyPosPair.second) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

Enemy::Enemy(std::string type, char status) {
	//Checks what type of the enemy is (Undead/Animal/Flower ... )
	for (int h = 0; h < MAX_ENEMY_TYPE; h++) {
		enemyDrops[h] = 0;
	}
	xp = 0;
	gold = 0;
	dropAMTID = 0;
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
			dropName = i;
		}
	}
	enemyStatus = status;
	//Checks what status the enemy is (Basic/Elite/Deluxe/Boss)
	//Enemy with higher status will have higher stats
	switch (status) {

	case 'B':
		break;
	case 'E':
		dropAMTID = 0;
		health *= static_cast<int>(150 / 100);
		attack *= static_cast<int>(150 / 100);
		defense *= static_cast<int>(150 / 100);
		break;
	case 'D':
		dropAMTID = 1;
		health *= static_cast<int>(220 / 100);
		attack *= static_cast<int>(175 / 100);
		defense *= static_cast<int>(175 / 100);
		break;
	case 'X':
		dropAMTID = 2;
		health *= static_cast<int>(350 / 100);
		attack *= static_cast<int>(250 / 100);
		defense *= static_cast<int>(250 / 100);
		break;
	}

	enemyPos(12, 3);
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
		enemyDrops[dropName] = calculateDropChance(0);
		return;
	case 'E':
		if (enemyType == "Ascendants" || dropAmount[dropName][dropAMTID] == 50) {          // If drop amount is 50% chance and type is ascendants
			enemyDrops[dropName] = calculateDropChance(40);
		}
		else {
			enemyDrops[dropName] = dropAmount[dropName][dropAMTID];
		}
		xp = static_cast<int>(baseEXP / 70);
		baseEXP += 2;
		gold = 5 + currentStage;
		return;

	case 'D':
		xp = static_cast<int>(baseEXP / 35);
		gold = 10 + currentStage;
		baseEXP += 3;
		enemyDrops[dropName] = dropAmount[dropName][dropAMTID];
		return;
	case 'X':
		xp = static_cast<int>(baseEXP / 10);
		baseEXP += 4;
		gold = 25 + currentStage;
		enemyDrops[dropName] = dropAmount[dropName][dropAMTID];
		return;
	}
}

//Caleb 250601F
//Checks if enemy is killed, returns true if does and vice versa
//Completed

bool Enemy::isBossDefeated() const
{
	if (enemyStatus != 'X') {
		return false;
	}
	if (enemyStatus == 'X') {
		if (health <= 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Enemy::killEnemy(Game* game) {
	if (health <= 0) {
		isBossDefeated();
		calculateLoot(game);
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
	return defense;
}
int Enemy::getXP() const
{
	return baseEXP;
}

// DRAFT DESIGNS
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